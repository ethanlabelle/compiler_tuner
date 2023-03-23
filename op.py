import subprocess
import os
from itertools import chain, combinations

def powerset(elements):
    return chain.from_iterable(combinations(elements, r) for r in range(len(elements) + 1))

def add_flags(flags):
    os.chdir("./src")
    file = open("Makefile", "r") 
    data = file.readlines()
    for i in range(len(data)):
        if data[i].startswith("CFLAGS ="):
            data[i] = "CFLAGS = " + flags + "\n"
    file = open("Makefile", "w") 
    file.writelines(data)
    os.chdir("..")

def clear_flags():
    os.chdir("./src")
    file = open("Makefile", "r")
    data = file.readlines()
    for i in range(len(data)):
        if data[i].startswith("CFLAGS ="):
            data[i] = "CFLAGS =" + "\n"
    file = open("Makefile", "w")
    file.writelines(data)
    os.chdir("..")

def build():
    os.chdir("./src")
    result = subprocess.run(["make", "clean"], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    result = subprocess.run(["make"], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    os.chdir("..")

def run_benchmark():
    os.chdir("./src")
    result = subprocess.run(["./driver", "-b"], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    print(result)
    os.chdir("..")

def run_verifier():
    os.chdir("./src")
    result = subprocess.run(["./driver", "-v"], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    print(result)
    os.chdir("..")

# clang --help emits a 1300 line, nonexhaustive list of flags
clang_flags = [
        "-O0",
        "-O1",
        "-O2",
        "-O3",
        "-Ofast",
        "-fdelete-null-pointer-checks",
        "-ffast-math",
        "-ffinite-loops",
        "-faligned-allocation",
        "-ffinite-math-only",
        "-funroll-loops",
        "-fvectorize"
        ]

exhaust = False
if __name__ == "__main__":
    count = 0
    if exhaust:
        enumeration = list(powerset(clang_flags))
        for flags in enumeration:
            count += 1
            print(count, " ", flags)
            add_flags(" ".join(flags))
            build()
            run_verifier()
            run_benchmark()
            print()
            clear_flags()
    else:
        clang_flags.insert(0, "")
        for flag in clang_flags:
            count += 1
            print(count, " ", flag)
            add_flags(flag)
            build()
            run_verifier()
            run_benchmark()
            print()
            clear_flags()