def factorial(number):
    if number == 1:
        return 1
    else:
        return factorial(number-1)*number


a_number = int(input("Input a number: "))
print("Factorial of", a_number, "is", factorial(a_number))

# Alternatively
result = a_number

for number in range(1, a_number, 1):
    result = result*(number)

print("Factorial of", a_number, "is", result)
