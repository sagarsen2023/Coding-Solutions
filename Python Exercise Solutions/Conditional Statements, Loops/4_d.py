n = int(input("Enter the length of Fibonacci series: "))

if n <= 0:
    print("No result")
elif n == 1:
    print("0")
elif n == 2:
    print("0, 1")
else:
    low = 0
    high = 1
    print("0, 1", end=", ")
    for _ in range(2, n):  
        next_num = low + high
        print(next_num, end=", ")
        low, high = high, next_num  
