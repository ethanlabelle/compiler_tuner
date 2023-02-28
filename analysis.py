import matplotlib.pyplot as plt

times=[]
with open("mac_results.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if line.startswith("CompletedProcess(args=['./driver', '-b'], returncode=0, stdout='time:"):
            tokens = line.split("time: ")
            time = tokens[1].split("s")[0]
            times.append(float(time))

    times = sorted(times, reverse=True)

plt.xlabel("Setting Number")
plt.ylabel("Program Runtime (s)")
plt.plot(times)
plt.show()

times=[]
with open("intel_results.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if line.startswith("CompletedProcess(args=['./driver', '-b'], returncode=0, stdout='time:"):
            tokens = line.split("time: ")
            time = tokens[1].split("s")[0]
            times.append(float(time))

    times = sorted(times, reverse=True)

plt.xlabel("Setting Number")
plt.ylabel("Program Runtime (s)")
plt.plot(times)
plt.show()

with open("mac_iterations.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if line.startswith("CompletedProcess(args=['./driver', '-b'], returncode=0, stdout="):
            test = []
            tokens = line.split("stdout='")
            trials = tokens[1]
            trials = trials.split('time ')
            for trial in trials:
                if len(trial) > 0:
                    trial = trial.split(": ")
                    trial = trial[1].split("s")[0]
                    test.append(float(trial))
            plt.plot(test)
plt.xlabel("Iterations")
plt.ylabel("Program Runtime (s)")
plt.show()

with open("intel_iterations.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if line.startswith("CompletedProcess(args=['./driver', '-b'], returncode=0, stdout="):
            test = []
            tokens = line.split("stdout='")
            trials = tokens[1]
            trials = trials.split('time ')
            for trial in trials:
                if len(trial) > 0:
                    trial = trial.split(": ")
                    trial = trial[1].split("s")[0]
                    test.append(float(trial))
            plt.plot(test)
plt.xlabel("Iterations")
plt.ylabel("Program Runtime (s)")
plt.show()