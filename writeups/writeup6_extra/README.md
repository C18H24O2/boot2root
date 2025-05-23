# Writeup 6 - haha iso modification haha

The subject explicitely told us that the goal is to exploit the server, not the ISO or the loading mechanism. So let's exploit that.

## The hacking!1!!1!! 01010011100111 hacker

When VirtualBox is booting, you can keep `SHIFT` pressed, and you can change the GRUB init parameters.

You can set the command line to be `live init=/bin/bash`, and pop a root shell. :trollface:

## The bigger hack>!!?!>>!

This one is a bit more advanced. We can... decompress the ISO!!!!! It's an archive, so of course it should be decompressable.

```bash
$ file boot2root.iso
boot2root.iso: ISO 9660 CD-ROM filesystem data (DOS/MBR boot sector) 'BornToSec' (bootable)
$ 7z x boot2root.iso
...
$ ls
'[BOOT]'   boot2root.iso   casper   install   isolinux   md5sum.txt   preseed   README.diskdefines   ubuntu
```

What we do care about is the `casper` directory, which contains the kernel and initrd files.

```bash
$ cd casper
$ ls
filesystem.manifest          filesystem.size      initrd.gz           squashfs-root
filesystem.manifest-desktop  filesystem.squashfs  README.diskdefines  vmlinuz
```

Ding ding ding!!! We struck gold!

There is a `filesystem.squashfs` file, which is a specific type of archive used for filesystems. Guess what? It's also decompressable!

```bash
$ file filesystem.squashfs
filesystem.squashfs: Squashfs filesystem, little endian, version 4.0, zlib compressed, 404208299 bytes, 69611 inodes, blocksize: 1048576 bytes, created: Fri Jun 16 22:39:21 2017
$ unsquashfs filesystem.squashfs
...
$ cd squashfs-root
$ ls
bin  boot  dev  etc  home  initrd.img  lib  media  mnt  opt  proc  root  run  sbin  selinux  srv  sys  tmp  usr  var  vmlinuz
```

we're such fucking hackers oh my god we can read the `/root/README` file!

Anyhow, we wanna get a root shell, so it's not *that* easy. Let's see if we can find a sequence break from the usual writeup.

We have access to home folders, so let's just go to `thor` and get the `turtle` file. We can then do a little bit of *actual work* to find the password for the `zaz` user, and continue the "normal" lame way of doing "actual exploits" and "buffer overflows" and whatnot.

this was a really fun challenge, skipping two thirds of it didn't make it any less fun hahahahahahahahahaahahahahdhffjkj;woelspiijapiv;owekgowigjwpo;fkalsmklr
