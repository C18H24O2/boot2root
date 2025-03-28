import random
import subprocess
from time import sleep


tried = set()

answers = open("answers.txt").read().splitlines()

def execute(array):
    global answers
    process = subprocess.Popen(["./bomb"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    a = answers[:]
    a.append(str(array))
    out = "\n".join(a) + "\n"
    # print(out)
    stdout, stderr = process.communicate(input=out.encode())
    process.wait()
    if process.returncode == 0:
        print(array, "Correct!")
        # print(stdout.decode())
    else:
        pass
        # print("Wrong!")
        # print(stdout.decode())

for i in range(0, 1002):
    execute(i)
