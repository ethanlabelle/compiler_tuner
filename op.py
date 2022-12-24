import subprocess
import os

def cat_makefile():
    os.chdir("./src")
    file = open("Makefile", "r+") 
    [print(line) for line in file.readlines()]
    os.chdir("..")

def build():
    os.chdir("./src")
    subprocess.run(["make", "clean"])
    subprocess.run(["make"])
    os.chdir("..")

def run_benchmark():
    os.chdir("./src")
    subprocess.run(["./driver", "-b"])
    os.chdir("..")

def run_verifier():
    os.chdir("./src")
    subprocess.run(["./driver", "-v"])
    os.chdir("..")

if __name__ == "__main__":
    build()
    run_verifier()
