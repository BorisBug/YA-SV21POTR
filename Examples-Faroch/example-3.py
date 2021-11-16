#!python

import collections

mylist = [1, 2, "Hello", 3.5, True]
mylist[0] = "Hi"
mylist.remove("Hello")
print(mylist)

stack = []

stack.append(5)
stack.append(50)
stack.append(500)
print(len(stack))

print(stack.pop())
print(len(stack))

queue = []
queue.append(5)
queue.append(50)
queue.append(500)
print(queue)

print(queue.pop(0))
print(len(queue))

print(queue.pop(0))
print(len(queue))


mylist = list(range(0, 100, 5))
print(mylist)
print(mylist[5:12])
print(mylist[:-1:2])

list2 = mylist
mylist[0] = 1000
print(list2, mylist)

list2 = mylist[:]
print(list2, mylist)

list3 = list2 + mylist
print(list3)

for value in mylist:
    print(value)

for value in mylist:
    print(mylist.index(value), value)

for index, value in enumerate(mylist):
    print(index, value)

t1 = (1, 2, True, "Hello")
print(len(t1), type(t1), t1)

# t1[0] = 1000

t2 = t1 + (10, 20, 30)
print(len(t2), type(t2), t2)

mydict = {1: "Hello", "a": "World", 1: "Test"}
print(mydict["a"])
mydict["a"] = "Stefan"
print(mydict["a"])

mydict["b"] = "BBBBBBBB"
print(mydict)


print(mydict.pop("b"))
print(mydict)

dict2 = mydict.copy()
mydict[1] = 3.6
print(dict2, mydict)

print(mydict.keys(), mydict.values(), mydict.items())

mydict = {"Lars": 20, "Eva": 30, "Eric": (None, True)}

for v in mydict.values():
    print(v)

for k in mydict.keys():
    print(k)

for k, v in mydict.items():
    print(k, v)

print(len(mydict))

myset = {1, "Hello", 3.5, 1}
print(len(myset), myset)

temp = myset
myset.update({'a', 'b'})
print(temp, myset)

print("My Set:")
myset = list(myset)
myset = set(myset)
print(myset)

for v in myset:
    print(v)

for i, v in enumerate(myset):
    print(i, v)


mydict = {1: 'c', 3: 'b', 5: 'a'}
for i, v in mydict.items():
    print(i, ':', v)

mydict = collections.OrderedDict()
mydict[0] = 10
mydict['a'] = 100
mydict[2] = "Hello"
for i, v in mydict.items():
    print(i, ':', v)

mylist = [1, 0, 1, 0, 10]
mylist = list(set(mylist))
print(mylist)
