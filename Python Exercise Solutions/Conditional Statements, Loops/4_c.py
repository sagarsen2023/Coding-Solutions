n = int(input("Enter a mumber: "))
if (n == 0) or (n == 1):
  print(f"{n}! = 1")
else:
  result = 1
  temp = n
  while(n != 1):
    result *= n
    n -= 1
  print(f"{temp}! = {result}")
