num = int(input("Enter a number:"))

def Factorial(x):
    fact = 1
    while(x>0):
        fact *= x
        x -= 1
    return fact

print(f'Factorial of {num} is {Factorial(num)}')