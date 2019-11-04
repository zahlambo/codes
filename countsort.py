def countingSort(array):
    size = len(array)
    #find the length of array
    output = [0] * size
    #create array as size
    count = [0] *pi
    #create array as size as max val
    for i in range(0, size):
        count[array[i]] += 1
    for i in range(1, pi):
        count[i] += count[i - 1]
    i = size - 1
    while i >= 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1
    for i in range(0, size):
        array[i] = output[i]


array = [4, 2, 2, 8, 3, 3, 1]
pi=max(array)+1
countingSort(array)
print("Sorted Array in Ascending Order: ")
print(array)
