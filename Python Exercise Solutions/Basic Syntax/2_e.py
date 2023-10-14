a=int(input("Enter 1st number:"))
b=int(input("Enter 2nd number:"))
print(f"The value you previously entered: a = {a} and b = {b}")

# without using 3rd varriable
a=a+b
b=a-b
a=a-b
print(f"Without using the third variable, a = {a} and b = {b}")

# With using the third variable
temp = a
a = b
b = temp
print(f"With using the third variable, a = {a} and b = {b}")
