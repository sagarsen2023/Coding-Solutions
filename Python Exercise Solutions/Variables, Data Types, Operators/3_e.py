n1 = int(input("Enter the first value: "))
n2 = int(input("Enter the second value: "))
n3 = int(input("Enter the third value: "))

if (n1 > n2) and (n1 > n3):
  print(f"{n1} is the largest")
elif (n1 < n2) and (n2 > n3):
  print(f"{n2} is the largest")
elif (n3 > n2) and (n2 < n3):
  print(f"{n3} is the largest")
else: 
  print("One or multiple values may be same.")
