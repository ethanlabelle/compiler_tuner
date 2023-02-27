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

mac_samples = [("('-O2', '-fdelete-null-pointer-checks', '-faligned-allocation', '-funroll-loops')\n", 1.705144), ("('-O1', '-O2', '-ffast-math', '-ffinite-loops', '-faligned-allocation', '-funroll-loops')\n", 1.740941), ("('-O1', '-Ofast', '-fdelete-null-pointer-checks', '-ffast-math', '-faligned-allocation', '-ffinite-math-only', '-funroll-loops')\n", 1.759902), ("('-O0', '-O3', '-ffast-math', '-ffinite-loops', '-faligned-allocation', '-ffinite-math-only', '-fvectorize')\n", 1.775548), ("('-O2', '-O3', '-fdelete-null-pointer-checks', '-ffast-math', '-ffinite-loops', '-faligned-allocation', '-ffinite-math-only', '-funroll-loops', '-fvectorize')\n", 1.788885), ("('-O3', '-Ofast', '-ffinite-math-only', '-fvectorize')\n", 1.801994), ("('-O0', '-O3', '-fdelete-null-pointer-checks', '-ffast-math')\n", 1.817464), ("('-O1', '-Ofast', '-ffast-math', '-ffinite-loops', '-faligned-allocation', '-funroll-loops')\n", 1.836937), ("('-O0', '-O3', '-fdelete-null-pointer-checks', '-ffast-math', '-ffinite-math-only', '-fvectorize')\n", 1.864822), ("('-O0', '-fdelete-null-pointer-checks', '-ffinite-math-only', '-funroll-loops', '-fvectorize')\n", 2.72181)]
intel_samples = [("('-O1', '-ffast-math', '-ffinite-loops', '-faligned-allocation', '-ffinite-math-only', '-funroll-loops')\n", 1.925661), ("('-O0', '-O2', '-O3', '-ffast-math', '-faligned-allocation', '-fvectorize')\n", 1.938127), ("('-O2', '-O3', '-ffast-math', '-ffinite-loops', '-faligned-allocation')\n", 1.939747), ("('-O2', '-faligned-allocation', '-ffinite-math-only')\n", 1.947453), ("('-O0', '-O2', '-Ofast', '-faligned-allocation', '-ffinite-math-only', '-fvectorize')\n", 1.961514), ("('-O0', '-O3', '-Ofast', '-faligned-allocation', '-ffinite-math-only')\n", 1.963413), ("('-O1', '-O2', '-Ofast', '-ffast-math', '-fvectorize')\n", 1.965191), ("('-O0', '-O2', '-O3', '-Ofast', '-ffinite-loops', '-ffinite-math-only', '-funroll-loops')\n", 1.969725), ("('-O0', '-O1', '-ffinite-loops', '-faligned-allocation')\n", 1.988994), ("('-O0', '-O1', '-O2', '-Ofast', '-fdelete-null-pointer-checks', '-ffast-math', '-faligned-allocation', '-ffinite-math-only')\n", 2.019643)]

if __name__ == "__main__":
    # enumeration = list(powerset(clang_flags))
    # count = 0
    # for flags in enumeration:
    #     count += 1
    #     print(count, " ", flags)
    #     add_flags(" ".join(flags))
    #     build()
    #     run_verifier()
    #     run_benchmark()
    #     print()
    #     clear_flags()
    for settings in intel_samples:
        print(settings)
        flags = settings[0]
        flags = " ".join(eval(flags))
        add_flags(flags)
        build()
        run_benchmark()
        print()
        clear_flags()
