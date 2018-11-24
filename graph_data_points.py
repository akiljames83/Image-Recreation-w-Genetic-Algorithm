import matplotlib.pyplot as plt

file = open("data.txt",'r')
points = file.read()
file.close()

data_points = points.strip().split(" ")
data_points = [float(i) for i in data_points]
x = list(range(len(data_points)))

plt.title("Percentage Change of Fitness with Exponentialy Decaying Adaptive Learning Rates")
plt.ylabel('Percentage Change (%)')
plt.xlabel('Number of Generations (hundreds)')
plt.ylim((50,100))
plt.plot(x, data_points)
plt.show()

# x = list(range(500))
# learning_rate = [0.999**(i) for i in x]#[(1/(0.9995**(i)) - 1) for i in x] #0.995
# plt.plot(x, learning_rate)
# plt.show()