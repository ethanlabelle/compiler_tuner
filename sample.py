data = []
with open("intel_results.txt", "r") as f:
    lines = f.readlines()
    for i in range(0, len(lines), 4):
        tokens = lines[i].split("   ")
        flags = tokens[1]
        tokens = lines[i+2].split("time: ")
        runtime = float(tokens[1].split("s")[0])
        data.append((flags, runtime))

data = sorted(data, key= lambda x: x[1])
samples = []
n_samples = 10
for i in range(n_samples):
    ind = int((len(data)/n_samples) * i)
    samples.append(data[ind])
print(samples)