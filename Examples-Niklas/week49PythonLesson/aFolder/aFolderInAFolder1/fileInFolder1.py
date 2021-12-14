def Divide(number1, number2):
    number3 = number1 / number2
    print(number1, "divided by", number2, "equals", number3)
    return number3


def Divide_Again(number1, number2):
    number3 = number1 / number2
    print(number1, "divided by", number2, "equals", number3)
    return number3


print("fileInFolder __name__:", __name__)
# If this is the file we're running, it gets the name "__main__"
# With the below if-check, we can then make code that only runs
# if this is the file we're running as our main-file.
if __name__ == "__main__":
    print("We're running this file now.")
    print("Let's divide 5 with 2.")
    Divide(5, 2)
