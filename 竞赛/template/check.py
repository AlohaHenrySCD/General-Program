import os
from random import randint

os.system("g++ a.cpp -o a -std=c++14 -O2")
os.system("g++ b.cpp -o b -std=c++14 -O2")

def readfile(file):
    with open(file, "r") as f:
        return "\n".join(f.readlines())

while True:
    with open("a.in", "w") as f:
        f.write(f"{randint(1, 100)} {randint(1,100)}")

    os.system("./a") # a
    os.system("./b <a.in >a.ans")

    aa = readfile("a.out")
    bb = readfile("a.ans")

    if (aa != bb):
        print("Error!")
        break
    else:
        print("Pass")