#!python

import sys

if len(sys.argv) == 2:
    if sys.argv[1] != 'start':
        print("Bad argument!")
        exit(1)
else:
    print("Bad argument!")
    exit(1)

c = True
a, b = 10, 20
d = a if c == True else b
print(d)

mylist = [1, 2, 3, 4]
print("mylist =", mylist)
print(type(mylist), len(mylist))
mylist[2] = 10
print(mylist[2])
print(min(mylist))
print(max(mylist))

mylist.append("Hello")
print(mylist)

mylist.extend(['Hello', 'My Fried', 3.14])

list1 = [12, 34, 56] + ['v', 'p', 'g']
list2 = [120, 34, 56]
list2.sort()
print(list2)

print(list2.index(56))

list2.clear()
print(list2)

nlist = list(range(0, 50, 5))
print(nlist)

x = 15
if x in nlist:
    print('{} is in the list'.format(x))
else:
    print('{} is in not the list'.format(x))

print(nlist[-2])

vlist = nlist
vlist[0] = "Hello"
print(nlist, vlist)
nlist[-1] = "Stefan"
print(nlist, vlist)

clist = nlist[1:5]
clist[0] = True
print(nlist, clist)
clist = nlist[:]
clist[0] = "Bye"
print(nlist, clist)

for v in range(10):
    print(v)
print()

for v in nlist:
    print(v)
print()

names = ["Maria", "Eric", "Lars", "Eva"]
for name in names:
    print(name)
print()

for name in names:
    print("names[{}] = {}".format(names.index(name), name))
print()

for index, name in enumerate(names):
    print("names[{}] = {}".format(index, name))
print()

nlist = [1, 2, ["Lars", "Eva", [12.23, None]], True]
nlist.remove(1)
print(len(nlist), nlist)

t1 = (1, 2, "Hello", (True, 3.5))
print(type(t1), len(t1), t1)
# t1[0] = 10 # error
print(t1.index("Hello"))

t1 = t1 + ('a', 'b')
print(t1)

person_ages = {"Maria": 23, "Erik": 31, "Eva": 40}
print(type(person_ages), len(person_ages), person_ages)
print(person_ages["Maria"])
person_ages["Maria"] = 30
print(person_ages["Maria"])

print(person_ages.pop("Eva"))
print(person_ages)

person_ages.update({"Erik": 50})
print(person_ages)

print(person_ages.get("Erik"))

print(person_ages.keys(), person_ages.values())

mydict = person_ages
person_ages["Erik"] = 100
print(mydict, person_ages)

mydict = person_ages.copy()
person_ages.clear()
print(mydict, person_ages)
print(len(mydict))
print()

for key in mydict.keys():
    print(key)
print()

for value in mydict.values():
    print(value)
print()

for key, value in mydict.items():
    print("{} is {} years old.".format(key, value))
print()

myset = {1, 2, 3, 3}
print(type(myset), myset, len(myset))

myset = set([1, "Hello", 3, 3])
print(type(myset), myset, len(myset))

cset = myset
myset.remove("Hello")
print(cset, myset)

cset = myset.copy()
myset.clear()
print(cset, myset)

for v in cset:
    print(v)

for i, v in enumerate(cset):
    print(i, v)
