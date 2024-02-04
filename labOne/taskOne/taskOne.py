def summation(arr):
    return sum(arr)
def maximum(arr):
    return max(arr)
def main():
    n = int(input("Enter the length of the array: "))
    arr = []
    print("Enter", n ,"integers: ")
    for i in range(n):
        arr.append(int(input()))

    sum_result = summation(arr)
    print("Sum of the integers:", sum_result)

    max_result = maximum(arr)
    print("Maximum integer:", max_result)

if __name__ == "__main__":
    main()