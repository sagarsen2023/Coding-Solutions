def divide_numbers(dividend, divisor):
    try:
        result = dividend / divisor
        return result
    except ZeroDivisionError:
        print("Error: Division by zero!")
        return None

dividend = int(input("Enter dividend: "))
divisor = int(input("Enter divisor: "))

result = divide_numbers(dividend, divisor)
if result is not None:
    print("Result of division:", result)
