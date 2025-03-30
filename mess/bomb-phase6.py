import random
import subprocess
from time import sleep


n = [i for i in range(0, 6)]
tried = set()

answers = open("answers.txt").read().splitlines()

def execute(array):
    global answers
    process = subprocess.Popen(["./bomb"], stdin=subprocess.PIPE)
    a = answers[:]
    a.append(" ".join(map(str, array)))
    out = "\n".join(a) + "\n"
    # print(out)
    stdout, stderr = process.communicate(input=out.encode())
    process.wait()
    if process.returncode == 0:
        print("Correct!")
        # print(stdout.decode())
    else:
        print("Wrong!")
        # print(stdout.decode())

i = 0
while True:
    new_array = n[:]
    random.shuffle(new_array)
    new_array = tuple(new_array)
    # h = hash(frozenset(new_array))
    if new_array not in tried:
        i += 1
        print(new_array)
        tried.add(new_array)
        execute(new_array)
        print(f"{i}/720")
        # sleep(1)
    # else:
        # print("Already tried")

