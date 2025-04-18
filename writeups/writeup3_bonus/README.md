# Writeup 3 - ret2libc

> This writeup takes from [Writeup 1, step ?](../writeup1/README.md), having discovered `zaz` user's credentials.

Instead of writing our payload to the stack to execute it, we can use a "ret2libc" technique, which will jump to a libc function that will execute our payload.

`TODO`
