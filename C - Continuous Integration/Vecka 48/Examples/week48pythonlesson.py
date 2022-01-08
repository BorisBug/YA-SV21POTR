from zipfile import ZipFile
from pathlib import Path
alist = [1, 2, 3, 4, 4, 6, 5, 7, 7, 7]

list_again = [x for x in alist]
print(list_again)

list_again_but_each_element_is_doubled = [number*2 for number in alist]

new_list = []
for number in alist:
    new_list.append(number * 2)

print(list_again_but_each_element_is_doubled)
print(new_list)

new_list = []
for number in alist:
    if (number % 2 == 0):
        new_list.append(number)

list_again_but_only_even_numbers = [
    number for number in alist if number % 2 == 0]

print(new_list)
print(list_again_but_only_even_numbers)

alist = [1, 2, 3, 4, 4, 6, 5, 7, 7, 7]

new_list = []
for number in alist:
    if (number % 2 == 0 and number > 4):
        new_list.append(number**2)

list2 = [number**2 for number in alist if number % 2 == 1 if number > 4]
print(list2)

list3 = [alist.pop() for i in range(len(alist))]
print(list3)

alist = [1, 2, 3, 4, 4, 6, 5, 7, 7, 7]

dictionary = {number*2: 3*number for number in alist if number % 2 == 1}
print(dictionary)

set = {number**2 for number in alist}
set2 = {number**2 for number in alist if number % 2 == 0}
print(set, set2)

list_of_keys = ['value', 23, True, 'hey']
list_of_values = [13, 'qwww', False, 2]

zip_list = zip(list_of_keys, list_of_values)
# print("Zipped list:", list(zip_list))

zipped_dictionary = {key: value for (key, value) in zip_list}
print("Zipped directory:", zipped_dictionary)

total = sum((number for number in range(1000)))
print(total)

gen = (number**3 for number in alist)
for value in gen:
    print(value)


# numbers = [1, 2]
# Index error. We are accessing something that doesn't exist.
# print(numbers[3])

try:
    numbers = [1, 2]
    print(numbers[3])
except IndexError as ex:
    print("Ex says", ex)
    print("Ex is of type: ", type(ex))
else:
    print("This only runs if we don't crash.")
finally:
    print("This runs regardless.")
print("Hey look we didn't crash!")

try:
    # number = int(input("Input a number: "))
    number = 5
    five_divided_by_number = 5 / number
except (ValueError, ZeroDivisionError) as ex:
    print("Ex says", ex)
    print("Ex is of type: ", type(ex))
except ZeroDivisionError:
    print("Don't divide by zero.")

try:
    file = open("copy.txt")
    #  Something in the file could go wrong
except (FileNotFoundError, ValueError):
    print("Exception")
finally:
    file.close()
    # We'd want the file to close even if we crashed.

try:
    with open("copy.txt") as file:
        print("Hey, it's open!")
except ValueError:
    print("Exception")

value1 = 10
try:
    five = 5 / 0
    value3 = value1 + value2
except ZeroDivisionError as error:
    print("Hey, no error anymore.")
except NameError as error:
    print("NameError", error)

value1, value2 = 10, 0
try:
    try:
        value3 = value1 / value2
    except NameError as error:
        print(error)
    value3 = value1 + rwbogpwf
except ZeroDivisionError as error:
    print(error)

try:
    raise Exception("Causing an exception ourselves.",
                    "With multiple arguments")
except Exception as exception:
    print(exception)
    print(exception.args)
    message1, message2 = exception.args
    print("Message1: ", message1)
    print("Message2: ", message2)

# Second string
# r = read
# w = write
# a = append
# +
# t = text
# b = binary
try:
    file = open("file.txt", "wt")
    file.write("Hello World!\n" * 10)
except FileNotFoundError as error:
    print(error)
else:
    file.close()

with open("file.txt", "r+t") as file:
    try:
        lines = file.readlines()
        # file contains a location in the file. After one file.readlines(), it's at the end of the file,
        # therefore lines2 here can't read anything because there's nothing left to read
        lines2 = file.readlines()
        print("lines: ", lines)
        print("lines2: ", lines2)
    except Exception as error:
        print("Error: ", error)

with open("file.txt", "r+t") as file:
    try:
        lines = file.readlines()
        file.seek(0)  # Goes to (variable) index character in file
        lines2 = file.readlines()
        print("lines: ", lines)
        print("lines2: ", lines2)
    except Exception as error:
        print("Error: ", error)

with open("file.txt", "r+t") as file:
    try:
        lines = file.readlines()
        file.seek(0)
        # Removes everything but the next (variable) characters from file.
        file.truncate(0)
        lines2 = file.readlines()
        print("lines: ", lines)
        print("lines2: ", lines2)
        for line in lines:
            file.write(line.replace("World", "Eva"))
    except Exception as error:
        print("Error: ", error)


def write_message(message):
    print("Type of message:", type(message))
    print("Message:", message)


write_message("Hello World!")
write_message(15)


def write_message(message1, message2):
    print(message1 + message2)


write_message("Hello ", "World")
write_message(2, 26)


def get_combined_message(message1, message2):
    return f"{message1} {message2}"


message_from_function = get_combined_message("Hello", "World")
print("Message from function:", message_from_function)

print("Printing a function that doesn't return anything:", write_message("a", "b"))


# Default values, 5 for number, 2 for by.
def divide(number=5, by=2):
    return number / by


print("10 divided by 2 is:", divide(10))  # Set number, default by
print("5 divided by 2 is:", divide())  # Both default.
print("5 divided by 5 is:", divide(by=5))  # Default number, set by
# Given arguments in wrong order.
print("50 divided by 5 is:", divide(by=5, number=50))


def get_sum(firstNumber, *numbers):
    total = firstNumber
    print(numbers)
    for number in numbers:
        total += number
    return total


def get_sum_quicker(*numbers):
    return sum(numbers)


print("Printing sum of 3, 7, 2, 8 and 22: ", get_sum(3, 7, 2, 8, 22))


def takes_a_dictionary_as_argument(firstnumber, **dictionary_of_arguments):
    print("Dictionary of arguments:", dictionary_of_arguments)
    print("First number:", firstnumber)
    print("Number:", dictionary_of_arguments["number"])
    print("String:", dictionary_of_arguments["a_string"])
    print("Boolean:", dictionary_of_arguments["boolean"])


takes_a_dictionary_as_argument(5, number=22, a_string="Hello.", boolean=True)

print("Printing sum of 3, 7, 2, 8 and 22: ", get_sum(3, 7, 2, 8, 22))


def takes_list_and_dictionary_as_argument(firstnumber, *numbers, **dictionary_of_arguments):
    print("Dictionary of arguments:", dictionary_of_arguments)
    print("First number:", firstnumber)
    print("Number:", dictionary_of_arguments["number"])
    print("String:", dictionary_of_arguments["a_string"])
    print("Boolean:", dictionary_of_arguments["boolean"])
    return sum(numbers)


print("Sum of fives:", takes_list_and_dictionary_as_argument(
    5, 5, 5, 5, number=22, a_string="Hello.", boolean=True))


x = 3
if True:
    x = 4
    if True:
        x = 5
        print(x)
    print(x)
print(x)


def outer():
    x = 6

    def inner():
        # I tell the program I want to use the x of the function inner is inside.
        # nonlocal x

        # I tell the program I want to use the global x in this function.
        global newVariable

        newVariable = 7
        print("inner:", x)

    inner()
    print("outer:", x)


outer()
print("global:", x)

print("NewVariable:", newVariable)

# 5! = 5*4*3*2*1


def factorial(n):
    return (1 if n == 1 else n * factorial(n - 1))


print("5! =", factorial(5))

#lambdaFunction = lambda number1, number2: number1 * number2


# lambdaFunction was reformated by the formatter into this, which is the same thing.
def lambdaFunction(number1, number2):
    return number1 * number2


print(lambdaFunction(4, 6))


def multiplier(number):  # Function that returns a function
    # The returned function is still missing a parameter (pm), which can be filled when calling the returned function.
    return lambda mp: mp * number


doubler = multiplier(2)  # Getting a function that fills "number" with 2.
# Inserting 5 into the missing parameter. Therefore, 5 * 2.
print("Doubler:", doubler(5))
tripler = multiplier(3)
print("Tripler:", tripler(5))  # 5 * 3


#from pathlib import Path
#from zipfile import ZipFile

zipFile = ZipFile("files.zip", "w")
for path in Path("").rglob("*.*"):
    zipFile.write(path)
zipFile.close()

# This takes all the files here and puts in a zip-file named files.zip. The above does exactly the same.
with ZipFile("files.zip", "w") as zipFile:
    for path in Path("").rglob("*.*"):
        zipFile.write(path)

# If not specified, we're automatically reading.
with ZipFile("files.zip") as zipFile:
    print(zipFile.namelist())  # Gets list of things in the zip-file.
    info = zipFile.getinfo("copy.txt")
    print(info.file_size)
    print(info.compress_size)
    # Extract everything to NewExtractFile.
    zipFile.extractall("NewExtractFile")
