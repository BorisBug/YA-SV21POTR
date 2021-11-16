#!python

input_list = [1, 2, 3, 4, 4, 6, 5, 7, 7, 7]
list1 = [2 * x for x in input_list]
list2 = [x**2 for x in input_list if x % 2 == 1 if x > 4]
list3 = [(x + 2) for x in range(10) if x % 2 == 0]
print(list3)

dict1 = {x: 3 * x for x in input_list}
dict2 = {x: x**2 for x in range(10)}

list1 = ['a', 'b', 'c', 'd']
list2 = [12, 'bbbbb', 'cccccc', 3.14]

dict3 = {key: value for (key, value) in zip(list1, list2)}

dict4 = {}
for i, v in enumerate(list1):
    dict4[v] = list2[i]

print(dict3, dict4)

set1 = {x**2 for x in input_list}
set2 = {x**2 for x in input_list if x % 2 == 0}
print(set1, set2)

total = sum((x * x for x in range(100000)))
print(total)

gen = (x**3 for x in input_list if x % 2 == 0)
for v in gen:
    print(v)'

a = 10
try:
    try:
        c = a / b
    except NameError as err:
        print(err)
except ZeroDivisionError as err:
    print(err)

a, b = 10, 0
try:
    c = a / b
except NameError as err:
    print(err)
except ZeroDivisionError as err:
    print(err)

try:
    raise Exception('aaa', 'bbb')
except Exception as excp:
    print(type(excp))  # the exception instance
    print(excp.args)  # arguments stored in .args
    a, b = excp.args
    print(a, b)

try:
    f = open('file.txt', 'r')
except OSError:
    print('cannot open file')
else:
    f.close()
    print("File closed")

x, y = 10, 0

try:
    result = x / y
except ZeroDivisionError:
    print("division by zero!")
else:
    print("result is", result)
finally:
    print("executing finally clause")


try:
    file = open("file.txt", "wt")
    file.write("Hello World!\n" * 10)
except FileNotFoundError as err:
    print(err)
else:
    file.close()

with open("file.txt", "r+t") as file:
    try:
        lines = file.readlines()
        file.seek(0)
        file.truncate(0)
        for line in lines:
            file.write(line.replace("World", "Eva"))
    except Exception as err:
        print("An error occurred", err)
        exit(1)


def func(name, age):
    print("{} is {} years old.".format(name, age))
    return "hello"


print(func("Stefan", 21))


def myfunc(a, *args):
    print(a, len(args), args[0])


myfunc(12, 13, 14)
myfunc(12, 13, 14, "Hello")


def func1(param1, param2, param3):
    print(param1, param2, param3)


func1(param1=12, param2=30, param3="Hello")
func1(param2=30, param3="Hello", param1=12)


def func2(**kwargs):
    print(kwargs)


func2(a=10, b=20, c=30)
func2(a=10, b=20, c=30, d=40)


def func3(a, b, c=10):
    return (a * b * c)


print(func3(1, 2))
print(func3(1, 2, 5))


def factorial(n):
    return (1 if n == 1 else n * factorial(n - 1))


print(factorial(5))


def func4(name):
    print(name)

    def inner_func():
        print(name.upper())

    inner_func()


func4("Stefan")

x = lambda a, b: a * b * 10

print(x(20, 10))


def multiplier(n):
    return lambda a: a * n


doubler = multiplier(2)
print(doubler(15))

tripler = multiplier(3)
print(tripler(15))


def func5(name):
    age = 20  # Local
    global var
    var = 30
    print("{} is {} years old!".format(name, age))

    def inner_func():
        print("Age =", age)
        print("Var =", var)
    inner_func()


var = 10
func5("Stefan")
print("Var =", var)


def func6(name):
    age = 20  # Local
    global myvar
    myvar = 30
    print("{} is {} years old!".format(name, age))

    def inner_func():
        print("Age =", age)
        print("Var =", myvar)
    inner_func()


func6("Stefan")
print("myvar =", myvar)
