#!python


def factorial(n):
    return (1 if n == 0 else n * factorial(n - 1))


if __name__ == "__main__":
    import platform
    print(platform.system())
    print("Factorial 5 is {}".format(factorial(5)))
