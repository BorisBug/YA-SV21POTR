inp = str(input("Enter a string: "))
for i in range(len(inp)):
    if inp[i].isupper():
        print(i)