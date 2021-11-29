list_1 = [1,2,3,4,4,6,5,7,7,7]
print("list 1 =", list_1)

# copied
list_2 = [x for x in list_1]
print("list 2 =", list_2)

# double
list_3 = []
for x in list_1:
    list_3.append(x*2)
print("list 3 =", list_3)

# double (short vewrsion)
list_4 = [x*2 for x in list_1]
print("list 4 =", list_4)

# even numbers
list_5 = [x for x in list_1 if x%2==0]
print("list 5 =", list_5)

# pow2 for odd numbers and x bigger than 4
list_6 = [x**2 for x in list_1 if x%2==1 if x>4]
print("list 6 =", list_6)

# index of each element
list_7 = [i for i in range(len(list_1))]
print("list 7 =", list_7)

##### similar ideas with a dictionary
# key & value
dic1 = {num: 3*num for num in list_1 if num%2==1}
print("dic1 = ", dic1, type(dic1))

##### similar ideas with a set (if we have only key)
# key only
set1 = {num**2 for num in list_1}
print("set1 = ", set1, type(set1))



##############################
##############################

keys = ['value',23,True,'hey']
vals = [13,'qwer', False, 2]

zip_list = zip(keys, vals)
print("zip_list =", list(zip_list))

zip_dict = {key: value for(key, value) in zip(keys, vals)}
print("zip_dict =", zip_dict)

total = sum(num for num in list_1)
print("total =", total)

gen = (num**3 for num in list_1)
for v in gen:
    print("v =", v)


##############################
# try, except, finally

try:
    numbers = [1,2]
    print(numbers[3])
except IndexError as ex:
    print("Ex says:", ex)
    print("Ex type is:", type(ex))
else:
    print("Print only if we don't crash!")
finally:
    print("Print always!")
print("We made it here!")

try:
    number = 3 #int(input("Input a number: "))
    div = 5 / number
except ValueError as ex:
    print("Ex says:", ex)
except ZeroDivisionError as ex:
    print("Ex says:", ex)
print("We made it here!")

try:
    number = 0 #int(input("Input a number: "))
    div = 5 / number
except (ValueError, ZeroDivisionError) as ex:
    print("Ex says:", ex)
print("We made it here!")


try:
    raise Exception("Causing our own exception", "With multiple args")
except Exception as ex:
    print(ex)
    print(ex.args)
    msg1, msg2 = ex.args
    print("msg1=", msg1)
    print("msg2=", msg2)


try:
    file = open("copy.txt", "wt")
    file.write("bla bla")
except FileNotFoundError as err:
    print(err)
else:
    file.close()

##############################
# with

with open("copy.txt", "wt") as file:
    try:
        file.write("bla bla")
    except FileNotFoundError as err:
        print("Error: ",err)



##############################
# functions

def write_msg(msg1, msg2):
    print(msg1 + msg2)

write_msg("hello ", "world")
write_msg(10, 20)

def divide(num=5, by=2):
    return num/by

print(divide())
print(divide(10))
print(divide(num=20))
print(divide(by=3))
print(divide(num=20, by=5))
print(divide(20, 5))
print(divide(by=5, num=20))

def play_with_list(*nums): # nums is a list
    return sum(nums)

print("play_with_list = ", play_with_list(2,7,5,10))


def play_with_dict(**dictionary): # nums is a dict
    print("dictionary:", dictionary)
    print("num:", dictionary["num"])
    print("string:", dictionary["string"])
    print("boolean:", dictionary["boolean"])

play_with_dict(num=2,string="hello",boolean=True)

print()
print("...Global...")
x = 1
if True:
    x = 2
    if True:
        x = 3
        print("inner:", x)
    print("outer:", x)
print("global:", x)


print()
print("...Scope...")
x = 1
def outer():
    x = 2
    def inner():
        x = 3
        print("inner:", x)
    inner()
    print("outer:", x)
outer()
print("global:", x)


print()
print("...Use global...")
x = 1
def outer2():
    global x
    x = 2
    def inner2():
        global x
        x = 3
        print("inner:", x)
    inner2()
    print("outer:", x)
outer2()
print("global:", x)

print()
print("...Use nonlocal...")
x = 1
def outer3():
    x = 2
    def inner3():
        nonlocal x
        x = 3
        print("inner:", x)
    inner3()
    print("outer:", x)
outer3()
print("global:", x)


##############################
# lambda

def lamnbda_fun(num1, num2):
    return num1 + num2

def multiplier(num):  # function that returns a functions
    return lambda mp: mp * num # the returned function is still missing a parameter

print()
doubler = multiplier(2)
print("doubler:", doubler(5))
tripler = multiplier(3)
print("tripler:", tripler(5))


##############################
# zip files

from pathlib import Path
from zipfile import ZipFile
import zipfile

limit_files = 0
zipFile = ZipFile("files1.zip", "w")
for path in Path("").glob("*.*"):
    limit_files = limit_files+1
    if limit_files < 10 and path.name!=zipFile.filename: 
        print(path)
        zipFile.write(path)
zipFile.close()

print("file 1 created")

limit_files = 0
with ZipFile("files2.zip", "w") as zipFile:
    for path in Path("").glob("*.*"):
        limit_files = limit_files+1
        if limit_files < 10 and path.name!=zipFile.filename:
            print(path)
            zipFile.write(path)

print("file 2 created")

with ZipFile("files2.zip") as zipFile:
    print(zipFile.namelist())
    info = zipFile.getinfo("copy.txt")
    print(info)
    print(info.file_size)
    print(info.compress_size)
#   zipFile.extractall("NewExtractFile")

print("file 2 openned")
