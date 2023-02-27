import matplotlib.pyplot as plt

times = []

with open("mac_results.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if line.startswith("CompletedProcess(args=['./driver', '-b'], returncode=0, stdout='time:"):
            tokens = line.split("time: ")
            time = tokens[1].split("s")[0]
            times.append(float(time))

    times = sorted(times, reverse=True)
    print(times)

plt.plot(times)
plt.show()