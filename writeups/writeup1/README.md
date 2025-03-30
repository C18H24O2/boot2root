# Writeup 1 - The usual way in

This first writeup will focus on the intended way of penetrating the system, from booting the machine up to getting a `root` shell.

## Preparation

This repository contains a [`shell.nix`](../../shell.nix) file, which can be used to run a shell environment with all the required tools used to exploit the machine.

We can use the `nix-shell` command to enter the shell environment:

```bash
$ nix-shell
[nix-shell:~/boot2root]$
```

We can now download the ISO and launch the virtual machine via the provided [run script](../../vm/run.sh):

```bash
[nix-shell:~/boot2root]$ ./vm/run.sh
...
[nix-shell:~/boot2root]$
```

## Enumeration

### Finding the machine's IP address

The first thing we need to do is to find the machine's IP address. The virtual machine was setup on a private network via VirtualBox, so we can just scan the few hundred IPs in the interface's range (in this case `vboxnet0`, `192.168.56.1/24`).

```bash
[nix-shell:~/boot2root]$ ip addr show vboxnet0
6: vboxnet0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 0a:00:27:00:00:00 brd ff:ff:ff:ff:ff:ff
    inet 192.168.56.1/24 brd 192.168.56.255 scope global vboxnet0
       valid_lft forever preferred_lft forever
    inet6 fe80::800:27ff:fe00:0/64 scope link
       valid_lft forever preferred_lft forever

[nix-shell:~/boot2root]$ nmap 192.168.56.1/24
Starting Nmap 7.94 ( https://nmap.org ) at 2025-03-30 19:39 CEST
Nmap scan report for 192.168.56.108
Host is up (0.00012s latency).
Not shown: 994 closed tcp ports (conn-refused)
PORT    STATE SERVICE
...

Nmap done: 256 IP addresses (1 hosts up) scanned in 3.05 seconds
```

We now get the IP address of the machine: `192.168.56.108`.

### Finding public services

Now that we have the IP address, we can do a deeper scan of the machine to find open ports and services.

```bash
[nix-shell:~/boot2root]$ nmap -sV -sC -p- 192.168.56.108
Starting Nmap 7.94 ( https://nmap.org ) at 2025-03-30 19:44 CEST
Nmap scan report for 192.168.56.108
Host is up (0.00055s latency).
Not shown: 65529 closed tcp ports (conn-refused)
PORT    STATE SERVICE  VERSION
21/tcp  open  ftp      vsftpd 2.0.8 or later
|_ftp-anon: got code 500 "OOPS: vsftpd: refusing to run with writable root inside chroot()".
22/tcp  open  ssh      OpenSSH 5.9p1 Debian 5ubuntu1.7 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   1024 07:bf:02:20:f0:8a:c8:48:1e:fc:41:ae:a4:46:fa:25 (DSA)
|   2048 26:dd:80:a3:df:c4:4b:53:1e:53:42:46:ef:6e:30:b2 (RSA)
|_  256 cf:c3:8c:31:d7:47:7c:84:e2:d2:16:31:b2:8e:63:a7 (ECDSA)
80/tcp  open  http     Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_http-title: Hack me if you can
143/tcp open  imap     Dovecot imapd
|_ssl-date: 2025-03-30T17:44:24+00:00; 0s from scanner time.
|_imap-capabilities: more LOGINDISABLEDA0001 ID OK LOGIN-REFERRALS post-login capabilities SASL-IR listed IMAP4rev1 Pre-login have IDLE ENABLE STARTTLS LITERAL+
| ssl-cert: Subject: commonName=localhost/organizationName=Dovecot mail server
| Not valid before: 2015-10-08T20:57:30
|_Not valid after:  2025-10-07T20:57:30
443/tcp open  ssl/http Apache httpd 2.2.22
| ssl-cert: Subject: commonName=BornToSec
| Not valid before: 2015-10-08T00:19:46
|_Not valid after:  2025-10-05T00:19:46
|_http-title: 404 Not Found
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_ssl-date: 2025-03-30T17:44:24+00:00; 0s from scanner time.
993/tcp open  ssl/imap Dovecot imapd
| ssl-cert: Subject: commonName=localhost/organizationName=Dovecot mail server
| Not valid before: 2015-10-08T20:57:30
|_Not valid after:  2025-10-07T20:57:30
|_ssl-date: 2025-03-30T17:44:24+00:00; 0s from scanner time.
|_imap-capabilities: more ID AUTH=PLAINA0001 LOGIN-REFERRALS ENABLE capabilities SASL-IR post-login IDLE listed have OK IMAP4rev1 Pre-login LITERAL+
Service Info: Host: 127.0.1.1; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 13.88 second
```

Alright, that's a lot of information, but we can see that the machine is running a Linux distribution, and that it has a few open ports.

There's two HTTP services, one on port 80 and one on port 443, an FTP service on port 21, and some mail services on port 143 and 993.

## Exploration

### FTP

The FTP service doesn't accept anonymous logins, so we'll need to come back to it later.

### SSH

We can try to connect to the machine via SSH, but again, we don't know any credentials that might work, and bruteforcing would take too long (and is not what the subject wants us to do, sadge).

### HTTP

Looking around the HTTP (port 80) service, we can see that it's running Apache 2.2.22
