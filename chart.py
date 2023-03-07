import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

y_QuickSort = [0.26, 0.371, 0.211, 0.229, 0.242, 0.461, 0.341, 0.301, 0.37, 0.247]
plt.plot(x, y_QuickSort, label = "QuickSort")

y_MergeSort = [0.874, 0.887, 0.849, 0.755, 0.877, 0.901, 0.863, 0.839, 0.886, 0.871]
plt.plot(x, y_MergeSort, label = "MergeSort")

y_HeapSort = [0.519, 0.032, 0.031, 0.016, 0.031, 0.024, 0.031, 0.03, 0.031, 0.031]
plt.plot(x, y_HeapSort, label = "HeapSort")

y_IntroSort = [0.233, 0.263, 0.246, 0.247, 0.248, 0.235, 0.251, 0.236, 0.251, 0.255]
plt.plot(x, y_IntroSort, label = "IntroSort")


plt.xlabel('kth running')
plt.ylabel('running time - second')
plt.title('Speed Rate Graph')
plt.legend()
  
# function to show the plot
plt.show()