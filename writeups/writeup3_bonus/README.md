# Writeup 3 - ret2libc

> This writeup takes from [Writeup 1, step ?](../writeup1/README.md), having discovered `zaz` user's credentials.

Instead of writing our payload to the stack to execute it, we can use a "ret2libc" technique, which will jump to a libc function that will execute our payload.

## Preparation

Like the previous writeup, we first need access to a proper shell on the machine, here we use the `zaz` user account again, as it contains the `exploit_me` binary, needed for this exploit.

## Explanation

In the first `breadcrumbs` path, we simply execute the stack of the vulnerable suid binary to get a shell with elevated privileges. This works fine on this machine as the stack of this program is ***executable***: this means we can easily overwrite a return address with the address of the wanted shellcode.
With newer machines, and better security standards, the stack of a program is usually not executable, which makes the previous exploit unusable. This is where ***ret2libc*** or ***return to libc*** comes in. The idea behind this exploit is very similar, it is still a stack overflow attack, but instead of inputting an address pointing to a *shellcode* to run we point towards the memory location of the function `system()`, to which we can pass the path to a shell to be executed.

## Running the exploit

`TODO`
