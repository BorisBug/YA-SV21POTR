

import json
import os
import shutil
from pathlib import Path
import collections

mylist = [1, 2, "hello", 3.5, True]  # Brackets are lists.
print(type(mylist), "contains", mylist)
mytuple = (1, 2, "hello")  # Parenthesis are tuples
print(type(mytuple))
# Brackets are sets, unless they're structured like dictionaries, then they're dictionaries.,
myset = {1, 2, "hello"}
print(type(myset))

print(mylist[0])
mylist.remove("hello")
print(type(mylist), "contains", mylist)

# thisIsAnInput = input()
# print(thisIsAnInput)

for value in mylist:
    print(value, end=" ")
print()

# Create a stack.
stack = []
stack.append(5)
stack.append(50)
stack.append(500)
stack.append(5000)
stack.append(50000)
print(stack)

print("Stack Length:", len(stack))
print("Popping:", stack.pop(), "Stack Length:", len(stack))
print("Popping:", stack.pop(), "Stack Length:", len(stack))
print("Popping:", stack.pop(), "Stack Length:", len(stack))
print("Popping:", stack.pop(), "Stack Length:", len(stack))
print("Popping:", stack.pop(), "Stack Length:", len(stack))


# Create a queue
queue = []
queue.append(5)
queue.append(50)
queue.append(500)
queue.append(5000)
queue.append(50000)
print(queue)

print("Queue Length:", len(queue))
# Giving an argument to pop gives what index of element I am popping.
print("Popping:", queue.pop(0), "Queue Length:", len(queue))
print("Popping:", queue.pop(0), "Queue Length:", len(queue))
print("Popping:", queue.pop(0), "Queue Length:", len(queue))
print("Popping:", queue.pop(0), "Queue Length:", len(queue))
print("Popping:", queue.pop(0), "Queue Length:", len(queue))

# List things
arange = range(-50, 101, 5)
print(arange)
print(list(arange))
# range(<where I'm starting>, <where I'm ending + 1>, <steps I'm taking between each>)
# range(0, 100, 5)
mylist = list(range(0, 100, 5))  # Will end at 99.
print(mylist)
print(mylist[12])  # Get value at that index.
print(mylist[5:12])  # Get values at index 5 to 11 (12-1).
print(mylist[5:12:2])  # Get every other value from index 5 to 11 (12-1).
print(mylist[:12])  # Just end-value, starts at index 0
print(mylist[5:])  # Just start-value, takes the rest of the list
# From start to finish, taking only every given amount of numbers.
print(mylist[::3])
# -1 counts backwards. -1 is last element of list. -2 is second to last element of list, etc.
print(mylist[5:-3])

# This just makes two pointers pointing at same list
list2 = mylist
mylist[0] = 13
print(list2, mylist)

# mylist[:] retrieves a copy of the list, which can be saved to a new location.
list3 = mylist[:]
mylist[0] = 0
print(list3, mylist)

for value in mylist:
    print(value, end=" ")
print()

# mylist = [0, 0, 0, 0, 0, 0, 0, 0, 0]

for value in mylist:  # This works to get index if there's no duplicates.
    print("index:", mylist.index(value), "value:", value, end=" | ")
print()

# Enumerate retrieves the list as a list of tuples,
# where the value is combined with their index in the list.
for value in enumerate(mylist):
    print(value, end=" ")
print()

for value in enumerate(mylist):  # Index has index 0, and values have index 1.
    # We can separate them like this.
    print("index:", value[0], "value:", value[1], end=" | ")
print()

for index, value in enumerate(mylist):
    # Or we can split them up like above, loop over both.
    print("index:", index, "value:", value, end=" | ")
print()

print(mylist)
print(list(enumerate(mylist)))

# Tuples
# Readonly lists.
mytuple = (1, 2, True, "Hello")
print(mytuple)

# mytuple[0] = 5 #TypeError: 'tuple' object does not support item assignment
mytuple2 = (5, "Yo")
mytuple3 = mytuple + mytuple2
print(list(mytuple3))
print(len(mytuple3), type(mytuple3), mytuple3)

# Dictionaries
# A dictionary has values behind "keys", which are then used to retrieve the values.
mydictionary = {1: "Hello", "Name": "Niklas", (5, 4): "Hey"}
print(mydictionary[1])  # Under the key of 1 I have the word "Hello"
# Keys can be numbers, strings, tuples, most things.
print(mydictionary["Name"])
mydictionary["Name"] = "Cullberg"
print(mydictionary["Name"])
print(mydictionary[(5, 4)])
print(mydictionary)  # List everything in the dictorionary.

# Can add new things to dictionary as I like.
mydictionary["New thing"] = "I'm new."
print(mydictionary["New thing"])

# print(mydictionary["Doesn't exist"])#Will give KeyError if looking for thing that doesn't exist.

# Popping retrieves value while removing from dictionary.
print("Popping from dictionary:", mydictionary.pop("Name"))
print(mydictionary)

# copy creates new dictionary. They are on different memory addresses and can be changed independently.
# dictionary2 = mydictionary would point both at same address, just as with lists.
dictionary2 = mydictionary.copy()
dictionary2["Hi"] = "Hello."
print(dictionary2, mydictionary)

print()
print("Dictionary:", dictionary2)
print("Keys:", dictionary2.keys())  # Method to get the keys.
print("Values:", dictionary2.values())  # Method to get the values.
print("Items:", dictionary2.items())  # Method to get the items.
# The keys of a dictionary is what the values are stored behind.
# The values of a dictionary is what's behind each key.
# The items of a dictonary is each combo of key and value in a dictionary.

# Sets
# A set is an unordered list with no duplicates.
myset = {1, "Hello", 3.5, 1}
print(myset)

tempset = myset
myset.update({"Hi", 1, 3, "Yo", "Hello"})

print(len(myset), myset, tempset)

for value in myset:
    print(value, end=" ")
print()

for index, value in enumerate(myset):
    print("index:", index, " value:", value)
print()

myset = {1, "Hello", 3.5}
myset2 = {"Hi", 1, 3, "Yo", "Hello"}

print("union: ", myset | myset2)  # One set plus the other.
print("intersection: ", myset & myset2)  # Values both have.
print("difference: ", myset - myset2)  # Values myset has but myset2 does not.
print("difference: ", myset2 - myset)  # Values myset2 has but myset does not.
print("symmetric difference: ", myset ^ myset2)
# Values myset or myset2 has, but not both.


mydictionary = {1: "c", 3: "b", 5: "a"}
for index, value in mydictionary.items():
    print(index, ":", value)

# import collections

mydictionary = collections.OrderedDict()
mydictionary[0] = 1000
mydictionary["b"] = 2
mydictionary[2] = 100
mydictionary["a"] = 45
for index, value in mydictionary.items():
    print(index, ":", value)

mylist = [1, 0, 1, 0, 10]
mylist = list(set(mylist))
print(mylist)

# Let's do some files and directories after the break.

# from pathlib import Path

# path = Path("C:\\Program Files\\Microsoft\\etc")
# path = Path("/user/local/bin")
path = Path() / "Directory"  # Append Directory to path.
if not path.exists():  # If the directory doesn't exist
    path.mkdir()  # Make the directory

# import shutil
# path.rmdir()  # This removes the directory.
shutil.rmtree(path)  # "Remove tree", remove recursively
path.mkdir()

if path.is_dir():  # Identify if this is a directory.
    print("This is a directory.")
elif path.is_file():  # Identify if this is a file.
    print("This is a file.")

path = path / "text.txt"  # Append text.txt to path.
path.write_text("This is text.\nThis is a new line.")
print("Current path:", path)  # Local address.
print("Absolute path:", path.absolute())  # Address from root.
print("What we're making:", path.name)  # text.txt
print("Name of what we're making", path.stem)  # text
print("Type of file we're making", path.suffix)  # .txt

path = Path()
# iterdir retrieves a list of things in the directory so we can iterate over them.
for p in path.iterdir():
    print("iterdir:", p)
# glob searches for things that match the name given as argument. * means all.
# *.txt means all txt-files.
for p in path.glob("*.txt"):
    print("glob:", p)

# rglob is glob but will search through directories recursively.
for p in path.rglob("*.txt"):
    print("rglob:", p)


path = Path() / "Directory/text.txt"
# Writes into text-file. If it doesn't exist, creates it.
path.write_text("Hello.\nTwo lines.")
print("This file exists now:", path.exists())
path2 = Path() / "Directory/copy2.txt"
# path2.write_text(path.read_text()) #We can copy by reading from the file and then writing it into the new file.
shutil.copy(path, path2)  # This shutil function does the same.
# path.rename(path2) # Renames a file to given path.
# path.unlink() # Removes a file at the path.

# open takes two arguments. First the path. Then what we want to do with it given with one letter.
# r - Read the file.
# w - Write in the file. This erases the current content.
# a - Append to the file. This does not erase the current content.
# x - Create the file.

# We can also add a second letter that says what we're working with.
# t - Text
# b - Binary.
# Example: rt - read text.
with open(path, "rt") as file:
    print("Read:", file.read())

with open(path, "w") as file:
    file.write("Hello ")
    file.writelines("Hello.\nHow's life?\nI'm good.")

with open(path, "a") as file:
    file.write("World")
# with does damage control, what one would usually do try/finally for and does clean-up code.

try:
    file = open(path, "w")
finally:  # Alternate. Finally will always close the file, even if we get an exception.
    file.close()

#file.write("Hey.") #

# afile = open(path, "w")
# afile.write("Writing things.") #Can also do this, but then you need to do your own clean-up code.

with open(path, "w") as file:
    file.write("Hello ")
    file.writelines("Hello.\nHow's life?\nI'm good.")

with open(path, "rt") as file:
    # Looping over file-contents gets us strings that is each line.
    for something in file:
        print("Read:", something, end="")
print()

with open(path, "rb") as file:
    # Looping over file-contents gets us strings that is each line.
    for something in file:
        print("Read:", something)
print()

# import os
# open(path, "r") as file:
#   os.read()

if os.path.exists("Directory/copy2.txt"):
    os.remove("Directory/copy2.txt")

#import json

people = [
    {"name": "George", "age": 15},
    {"name": "Lowel", "age": 13},
    {"name": "Cain", "age": 12}
]

# A json in python is a list of dictionaries.
print("a", type(people), "of", type(people[0]))

# We can make it into a string with json.dumps(<list>)
data = json.dumps(people)
print(data)
path = Path("./Directory/people.json")
path.write_text(data)  # We can then write it into a json file.

# newData = path.read_text(data) # This didn't work?

with open(path, "rt") as file:
    newData = file.readline()  # We can then read it as a string.
print()
print("Data loaded from json-file: ", newData)
# Then we can make it a json (list of dictionaries) with json.loads(<string>)
newPeople = json.loads(newData)
print(newPeople)
print("a", type(newPeople), "of", type(newPeople[0]))  # And there we go.
