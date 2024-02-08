n = int(input("Enter a number: "))
flag = 0
if (n >= 1) and (n < 4):
  print("This is a prime number")
elif n == 0:
  print("You have entered 0")
else:
  for i in range(2, n):
    if n%i == 0:
      flag += 1
  if flag > 0:
    print(f"{n} is not a prime number.")
  else:
    print(f"{n} is a prime number.")
