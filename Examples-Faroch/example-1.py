#!python

# This is a single line comment

import sys

print(sys.argv, len(sys.argv))  # sys.argv has the list of arguments

x = 5
y = 10

"""
This is a
multiline commmet
"""

print("x + y =", x + y)
print()
print("Hello ' World!")
print('Hello " World!')

x = 2

if x == 2:
    print(x)
    if True:
        print(1)
        print(10)

x = 2.0
z = complex(1, 2)  # z = 1 + 2j
print(z)

x = "Hello"


n = None
if n == True:
    print("None is True")
elif n == False:
    print("None is False")
else:
    print("None is None")

del n

print(type(x))

print(type(2))

print(type(2.1))

print(type(True))

if isinstance(x, str):
    print("x is a string")

print(float(2))
print(str(2))
print(int("22") + 8)
print(float("2.2") + 8)
print("Hello " + str(3.1415))
print(int("0xff", 16))
print(hex(255))

a, b = 2, 4
print("a =", a, "b =", b)

a, b = b, a
print("a =", a, "b =", b)

if not (a != 2 or b != 4):
    print("a is 2 and b is 4")

if a is not b:
    print("a is not b")

a = b = 2
if a is b:
    print("a is b")

string = "Hello, my friend! How are you?"

if 'friend' in string:
    print("friend is in the string")

if 'name' not in string:
    print("name is not in the string")

string = """Hello World!
Hello World!
Hello World!
Hello World!"""
print(string)

string = ("Hello World!\n"
          "Hello World!\n"
          "Hello World!\n"
          "Hello World!")
print(string)

age = 40
name = "Faroch"
print("{1} is {0} years {0} old.{{}}".format(name, age))
print("Temperature is {:.03f}".format(5 / 3))

string = "Hello World!\n"
string += "Hello World!\n"
string += "Hello World!\n"
string += "Hello World!\n"

print(string)

string = "Hello World!\n" * 4
print(string)

string = "Hello World!"
print("Length =", len(string))
print(string[0])

print(string[0:5])  # [start:end:step]
print(string[:5])
print(string[2:5])

print(string[0:10:2])
print(string[2:-2])

# string[0] = 'h'

print(string.lower())

n = 10
while n > 0:
    print(n ** n)
    n -= 1

for value in range(1, 10):
    print(value ** value)

age = input("Enter your age: ")
if age.isnumeric():
    name = input("Enter your name: ")
    print("{} is {} years old.".format(name, age))

    age = int(age)
    if age < 10:
        print("Lesser than 10")
    elif age < 20:
        print("Between 10 and 20")
    else:
        print("Greater than 20")
else:
    print("The input is not a number")


# while True:
#    pass # do nothing

n = 17
is_prime = True
for v in range(2, n):  # [2, n)
    if n % v == 0:
        is_prime = False
        break
if is_prime == True:
    print("{} is prime".format(n))

for v in range(2, n):
    if n % v == 0:
        break
else:
    print("{} is prime".format(n))

v = 2
while v < n:
    if n % v == 0:
        break
    v += 1
else:
    print("{} is prime".format(n))
