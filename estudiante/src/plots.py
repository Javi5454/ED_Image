import matplotlib.pyplot as plt
import numpy as np

data_rows = np.genfromtxt("eficiencia2_rows.csv", delimiter=",", names=["x", "y"])
data_cols = np.genfromtxt("eficiencia2_cols.csv", delimiter=",", names=["x", "y"])
data_iter = np.genfromtxt("eficiencia2_iter.csv", delimiter=",", names=["x", "y"])


plt.plot(data_rows["x"], data_rows["y"], color="r", label="rows")
plt.plot(data_cols["x"], data_cols["y"], color="g", label="cols")
plt.plot(data_iter["x"], data_iter["y"], color="b", label="iter")

plt.xlabel("n_datos")
plt.ylabel("segs")
plt.legend(loc="upper left")


plt.show()


