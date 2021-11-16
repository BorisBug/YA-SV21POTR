#!python


def function(name, age):
    print("{} is {} years old!".format(name, age))


def factorial(n):
    return (1 if n <= 1 else n * factorial(n - 1))


if __name__ == '__main__':
    import platform
    print(platform.system())
    function("Stefan", 30)
    print("Factorial 5 is", factorial(5))
