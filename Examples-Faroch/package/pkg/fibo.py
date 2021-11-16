#!python

# Fibonacci sequence up to n
# f(n) = f(n - 1) + f(n - 2); f(0) = 0, f(1) = 1
def fibonacci(n):
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a + b
    return result


if __name__ == "__main__":
    import platform
    print(platform.system())
    print("Fibonacci: {}".format(fibonacci(10)))
