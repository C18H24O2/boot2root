# Writeup 8 - fakeroot

> This writeup takes from [Writeup 1](../writeup1/README.md), step ?, having found ssh credentials credentials.

When having an SSH connection, you can run `fakeroot` to get a "root shell" as per the subject's standards:

```bash
$ fakeroot
fakeroot $ id
uid=0(root) gid=0(root) groups=0(root)
fakeroot $ whoami
root
```

This *technically* respects the subject's requirements:
```
The root user means that the user id must be 0 and there must be a
real shell where you can run commands such as 'whoami'.
```

:trollface:
