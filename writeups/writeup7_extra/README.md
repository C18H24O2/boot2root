# Writeup 7 - that could've been so fucking good

> This writeup takes from [Writeup 1](../writeup1/README.md), step ?, having discovered `/webmail/` credentials.

The SquirrelMail version is '1.4.22' and is vulnerable to a [Remote Code Execution vulnerability](https://www.exploit-db.com/exploits/41910).

This could've been a really nice entrypoint, skipping the SQL & php shenanigans, getting us a reverse shell with just a smol script.

Unfortunately, due to the fact that the setup on machine is not a functionnal one, we can't use the exploit :(

## Let's still explain the exploit because it's cool and whatever

The exploit consists in sending a mail from the SquirrelMail server, with a specially crafted subject, users settings, and a malicious payload.

This will trick the `sendmail` CLI to add extra flags, by putting a tab (`\t`) character in the sender's email address, you can escape the arguments given and add an output file:

```bash
sendmail -f target@example.com\t<extra flags>
```

You can then send a mail with a shell in the body, and tell sendmail to save a copy to something like `/var/www/forum/c_templates/shell.php`. 

We'll finally be able to run it when visiting `/forum/c_templates/shell.php` and run server commands/a reverse-shell.
