inp = str(input("Enter a string: "))
for i in range(0,len(inp),1):
    if inp[i].isupper():
        print(i)