# View -> Command Palette -> Python: Select Linter -> pylint
#

import math
from os import path
from array import array
from types import prepare_class

print("H", "e", "l", "l", "o", " world")

owergbw = 1000000000000
print(type(owergbw), ":", owergbw)
a_float = 100.0
print(type(a_float))
a_string = "Hello"
print(type(a_string))
a_bool = True
another_bool = False
print(type(a_bool))
none_type = None
print(type(none_type))

# print(""variable)

# If you're on mac, you want to go to Settings -> find three dots (...) to the right -> Open settings.JSon.
# Search for code-runner-executorMap. Find python, and change in user-settings.
# Write code-runner.executorMap to get the default user settings into user settings.
# Change "python": "python -u" to "python": "python3"

a_long_string = """rgnwng
grwpngpw'
nwprnwp
gwpnigpw
"""
print(a_long_string)

"""
    I can write
    a multiple line comment
    like this.
"""

# Strings
a_string = "I'm a string"

print("The length of the long string is ", len(a_string))
a_list = [1, 2, 3, 4, 5, 4]
print("The length of a_list is", len(a_list))

# Shift-alt-arrow-key to duplicate
print("Second character of a_string is", a_string[1])
print("Second number in a_list is", a_list[1])

print("\"", a_string[:4], "\"")  # Starts at beginning, goes to index 3

print("\"", a_string[4:], "\"")  # Starts at index 4, goes to end.

# Starts at beginning, goes to end, but only takes every other value.
print("\"", a_string[::2], "\"")

# Starts at 2 : goes to 5 (given value-1) : only takes every third value.
print("\"", a_string[2:6:3], "\"")

one_string, another_string = "   I am", "a string   "
a_string = f"{one_string} {another_string}"
print(a_string)

print(f"Upper: {a_string.upper()}")
print(f"Lower: {a_string.lower()}")
print(f"Title: {a_string.title()}")
print(f"Strip: {a_string.strip()}")
print(f"LStrip: {a_string.lstrip()}")
print(f"RStrip: {a_string.rstrip()}")

print(f"Index of \"stri\":", a_string.strip().find("stri"))
print(f"Is \"stri\" in string:", "stri" in a_string)
print(f"Is \"strig\" in string:", "strig" in a_string)
print(f"Is \"strig\" not in string:", "strig" not in a_string)

# Numbers
an_int = 5
a_float = 2.4
a_complex_number = 1 + 3j
a_complex_number = complex(1, 3)
print(a_complex_number)

print("5 + 4:", 5 + 4)
print("5 - 4:", 5 - 4)
print("5 * 4:", 5 * 4)
print("5 / 4:", 5 / 4)
print("5 // 4:", 5 // 4)
print("5 % 4:", 5 % 4)
print("5 ** 4:", 5 ** 4)  # 5 to the power of 4. 5^4

x = 5
x = x + 4
x += 4
x -= 4
x *= 4
x //= 4
print(x)


print("round(2.9):", round(2.9))
print("abs(2.9):", abs(-2.9))
print("math.ceil(2.9):", math.ceil(2.9))
print("math.floor(2.9):", math.floor(2.9))
print("math.log10(2.9):", math.log10(2.9))

# User input
user_input = 5  # input("Please write a number: ")
print("type of input:", type(user_input))
print("input as an int:", int(user_input))
print("input as a float:", float(user_input))
print("input as a boolean:", bool(user_input))
print("input as a string:", str(int(user_input)))

print("Is empty string true?", bool(""))
print("Is anything else true?", bool("anything"))
print("Is 0 true?", bool(0))
print("Is 21 true?", bool(21))
print("Is None true?", bool(None))

"""
Falsy values: A boolean is true unless it's one of these three values
1: "" - If it's a string
2: 0 - If it's a number
3: None - If it's a struct/object
These will be interpreted as False if they're checked as a boolean. Everything else is true.
"""

print("6 is equal to 3:", 6 == 3)
print("6 is not equal to 3:", 6 != 3)
print("6 is greater than 3:", 6 > 3)
print("6 is greater than or equal to 3:", 6 >= 3)
print("6 is less than 3:", 6 < 3)
print("6 is less than or equal to 3:", 6 <= 3)
print("c is greater than a:", "c" > "a")
print("ord(c)", ord("c"))
print("ord(a)", ord("a"))

# if-statements
available_houses = 3
have_money = True
if available_houses > 0:
    print("Do we detect this?")
    if have_money:
        print("I'll take a house.")
        available_houses -= 1
        print(f"There are now {available_houses} houses left.")
        print("This is a new if-statement.")
    print("This is back to the first if-statement.")
elif have_money:
    print("I have money but no houses to spend it on...")
else:
    print("There's no houses available and I have no money.")

if available_houses > 0 and have_money:
    print("There are available houses AND I have money for them.")

if available_houses > 0 or have_money:
    print("I either have money, there are available houses, or both!")

if not have_money:
    print("I can't affort a house.")

print("This is not part of an if-statement.")

# Scope
x = 3

if True:
    x = 4
    if True:
        xa = 4
        x = 5
        print(x)
    print(x)
print(x)

print("xa:", xa)

if xa == 4:
    print("Got here.")

number_between_five_and_sixteen = 6
if 5 < number_between_five_and_sixteen < 16:
    print("Number is between 5 and 16.")


# Loops
a_list = [1, 2, 6 + 4j, 8, "a", "a", True, 2.5, True, False, "Hello."]
print("a_list contains:", a_list)
a_string = "This is a string."

for element in a_list:
    print(element)

list_of_numbers = list(range(20))
print(range(len(a_list)))
print("list(range(len(a_list))) = ", list(range(len(a_list))))

for number in range(len(a_list)):
    print(f"At index {number} of a_list there is {a_list[number]}")
# a_list[2:3:5]
# Telling range I want to start at index 1, stop at index 7 (8-1), and take 2 steps forward each time.
# for number in range(start=1, stop=8, step=2):
for number in range(1, 8, 2):
    print(f"At index {number} of a_list there is {a_list[number]}")

two_point_five_index = -1
for number in range(len(a_list)):
    if a_list[number] == 2.5:  # I'm looking for the number 2.5
        two_point_five_index = number  # If I find it, I can stop the loop.
        break  # Breaks (stops) the loop
else:
    # You only get to the else-statement if the for-loop didn't run "break".
    # That is, in this case, we didn't find 2.5
    print("2.5 wasn't in the loop.")

number = 5
while number > 0:
    number -= 1
    print("Number is at:", number)

user_input = ""
while user_input.lower() != "quit":
    #user_input = input("Write a command: ")
    user_input = "quit"


letters = ["d", "s", "l", "t"]
numbers = [4, 7, 12, 8]
combined = letters + numbers
print("Combined:", combined)
numbers_five_times_over = numbers * 5
print("Numbers five times:", numbers_five_times_over)
a_string = "This is a string."
print("a_string:", a_string)
string_list = list(a_string)
print("string_list:", string_list)
print("Index 5 of string_list:", string_list[5])
print("Index 3-5 of string_list:", string_list[3:6])
# [-1] gives last element, [-2] gives second to last, [-3] gives third to last, and so on
print("Last index of string_list:", string_list[3:-1])

letters = ["d", "s", "l", "t", "l"]
letters.append("e")
print("Letters right now:", letters)
last_letter = letters.pop()
print("Last letter was:", last_letter)
print("Letters right now:", letters)
# Inserting j at index 2, all other elements moved +1 index.
letters.insert(2, "j")
print("Letters right now:", letters)
letters.remove("l")
print("Letters right now:", letters)
del letters[2:4]
print("Letters right now:", letters)
# print("Index of a:", letters.index("a")) #If a doesn't exist, throws error.
if "a" in letters:
    print("Index of a:", letters.index("a"))

letter_count = letters.count("a")  # Counts number of "a"s.
print("letter_count", letter_count)
if letter_count > 0:
    print("Index of a:", letters.index("a"))


letters.clear()
print("Letters right now:", letters)

a_list = []  # Creates empty list.

numbers = [2, 6, 3, 5, 1]
numbers.sort()
print("Sorted numbers:", numbers)
numbers.sort(reverse=True)
print("Sorted reverse numbers:", numbers)
print("Sorted function:", sorted(numbers))
print("Sorted reverse function:", sorted(numbers, reverse=True))

# Tuples
# Read-only lists of data.
a_tuple1 = (1, 2, 3)
a_tuple2 = 1, 2
a_tuple3 = 1,
a_tuple4 = ()
print(a_tuple1)
print(a_tuple2)
print(a_tuple3)
print(a_tuple4)
print(type(a_tuple1))
a_list = [1, 4, 5]
a_tuple = tuple(a_list)
print("This was a list:", a_tuple)

people = [
    ("Joe", 16, "Golfing"),
    ("Luna", 72, "Dancing"),
    ("Jacob", 10, "Gaming"),
    ("Pilot", 24, "Flying")
]


def sort_item(item):
    return item[1]


people.sort(key=sort_item)
print(people)

# [] <- List
# () <- Tuple
# {} <- Dictionary/Sets

# Zip function - Combines multiple lists and makes tuples out of the elements on the same index.
list1 = [1, 2, 3]
list2 = [4, 5, 6]
list_zipped = zip(list1, list2, list("hey"))
print("Zipped list:", list_zipped)
print("Making a list out of the zipped object:", list(list_zipped))


# Arrays
# We need to give a letter to specify what kind of array it is.
"""
Type code   | C type | Python type | Minimum size in bytes - https://docs.python.org/3/library/array.html
'b'         | signed char | int | 1
'B'         | unsigned char | int | 1
'u'         | wchar_t | Unicode character | 2
'h'         | signed short | int | 2
'H'         | unsigned short | int | 2
'i'         | signed int | int | 2
'I'         | unsigned int | int | 2
'l'         | signed long | int | 4
'L'         | unsigned long | int | 4
'q'         | signed long long | int | 8
'Q'         | unsigned long long | int | 8 
'f'         | float | float | 4
'd'         | double | float | 8
"""
numbers = array("i", [2, 3, 4])
numbers.append(3)  # Putting 3 at end
numbers.insert(2, 3)  # Putting another 3 at index 2
numbers.pop()  # Removing last 3
numbers.remove(2)  # Removing the 2 at the start.
print("This array:", numbers)

# Set - Unordered list of unique values
numbers = [4, 7, 2, 4, 7, 3, 2, 1]
number_set = set(numbers)
print("number_set:", number_set)
becomes_a_dictionaries = {}
print(type(number_set))
print("length of set:", len(number_set))

another_set = {1, 6, 9, 0, 7}
print(type(another_set))

print("number set:", number_set, "Another set:", another_set)

# Union - Gets all values from both sets.
print("number_set | another_set:", number_set | another_set)
# Intersection - Gets values that are in both sets.
print("number_set & another_set:", number_set & another_set)
# Difference - Gets values that are in number_set, removing those that are also present in another_set.
print("number_set - another_set:", number_set - another_set)
# Difference - Gets values that are in another_set, removing those that are also present in number_set.
print("another_set - number_set:", another_set - number_set)
# Symmetric Difference - Gets values that are in either set, but not both.
print("number_set ^ another_set:", number_set ^ another_set)

if 1 in number_set:
    print("1 is in number_set.")


# Dictionaries
# Are collections of data bound to key-words instead of indexes.
a_dictionary = {"x": 1, "y": 2}
print("a_dictionary[\"x\"]:", a_dictionary["x"])
a_dictionary["x"] = 34
print("a_dictionary[\"x\"]:", a_dictionary["x"])
a_dictionary[23] = "Yay"
print("a_dictionary[23]:", a_dictionary[23])
print("Dictionary a_dictionary:", a_dictionary)

# print(coordinates["a"]) #This gets an error, as nothing exists behind the key "a".
#a_dictionary["a"] = 2
if "a" in a_dictionary:
    print("a_dictionary[\"a\"]:", a_dictionary["a"])

print("a_dictionary keys:", a_dictionary.keys())
# get() something that doesn't exist doesn't crash, just gets None.
print("a_dictionary.get(\"a\"):", a_dictionary.get("a"))  # this gets None.

del a_dictionary[23]

a_dictionary["v"] = 23
a_dictionary["f"] = True
a_dictionary["hello"] = "world"

for thing in a_dictionary:
    # This only gets the names of the keys.
    print("Thing without items() is:", thing)

for thing in a_dictionary.items():
    # Loops through a list of tuples containing key and value.
    print("Thing with items() is:", thing)

for key, value in a_dictionary.items():
    # Separates the tuples into the two parameters key and value.
    print("Under key", key, "was value", value)
