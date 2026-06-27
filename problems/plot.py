import matplotlib.pyplot as plt

n = []
t = []

with open("complexity.dat") as f:
    for line in f:
        x, y = line.split()
        n.append(int(x))
        t.append(float(y))

plt.plot(n, t, marker='o')
plt.title("Activity Selection Time Complexity")
plt.xlabel("Input size (n)")
plt.ylabel("Time (seconds)")
plt.show()