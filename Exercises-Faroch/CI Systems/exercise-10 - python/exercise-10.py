"""
Beskrivning
1) Write a Python program to search for decimal numbers which have min. 1 and max. 3 digits, in a given string.
2) Write a Python program to validate an IPv4 address. IPv4 format is xxx.xxx.xxx.xxx and xxx shall be between 0 and 255.
3) Write a Python program to replace whitespaces in a string with an underscore and vice versa.
4) Write a Python program to validate and convert a date of yyyy-mm-dd format to dd/mm/yyyy format.
5) Write a Python program to find all words starting with 'a' or 'e' in a given string.
"""

# 1) Write a Python program to search for decimal numbers which have min. 1 and max. 3 digits, in a given string.
def digits(num: int):
    if num<0:
        #num = -num
        return -1
    if num<10:
        return 1
    else:
        return 1+digits(num//10)

print(digits(1))
print(digits(11))
print(digits(-2))
print(digits(-22))
print(digits(300))
print(digits(123456))

#2) Write a Python program to validate an IPv4 address. IPv4 format is xxx.xxx.xxx.xxx and xxx shall be between 0 and 255.
def ValidateIPv4(addr: str):
    nums = addr.split('.')
    if len(nums)!=4:
        return False
    for num in nums:
        if len(num)>3:
            return False
        for c in num:
            if not c.isnumeric():
                return False
        num = int(num)
        if num<0 or num>255:
            return False
    return True

print(ValidateIPv4("1.2.3.4")) # ok
print(ValidateIPv4("1.2.255.1")) # ok
print(ValidateIPv4("1.2.256.1")) # 256 -> too big
print(ValidateIPv4("1.2.255.0.1")) # 5 segments
print(ValidateIPv4("111.222.333.444")) # 333 and 444
print(ValidateIPv4("255.255.255.255")) # ok


# 3) Write a Python program to replace whitespaces in a string with an underscore and vice versa.

#def SwapSpacesAndUnderscores(txt: str):
#    return txt.replace(' ', '#&#', -1).replace('_', ' ', -1).replace('#&#', '_', -1)
def SwapSpacesAndUnderscores(txt: str):
    res = ""
    for c in txt:
        if c==' ': c='_'
        elif c=='_': c=' '
        res += c
    return res

test = "abc def_ghi 123_456"
print(SwapSpacesAndUnderscores(test))
test = "a_d e___f   g_-_h"
print(SwapSpacesAndUnderscores(test))

# 4) Write a Python program to validate and convert a date of yyyy-mm-dd format to dd/mm/yyyy format.
import datetime

# 5) Write a Python program to find all words starting with 'a' or 'e' in a given string.
