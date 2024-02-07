n1 = int(input("Enter the first number: "))
n2 = int(input("Enter the second number: "))
print("\n1. Add, 2. Substract, 3. Multiply, 4. Divide.")
selection = int(input("Enter your selection"))
match selection:
  case 1: 
    print(f"{n1} + {n2} = {n1+n2}")
  case 2:
    print(f"{n1} - {n2} = {n1-n2}")
  case 3:
    print(f"{n1} * {n2} = {n1*n2}")
  case 4:
    print(f"{n1} / {n2} = {n1/n2}")
  case _: 
    print("Sorry Wrong Input")
