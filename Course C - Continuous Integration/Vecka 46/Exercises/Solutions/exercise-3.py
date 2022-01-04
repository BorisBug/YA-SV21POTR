a_string = list(input("Write a string: "))
for character in enumerate(a_string):
    # Checks against ascii table.
    if ord(character[1]) > 64 and ord(character[1]) < 91:
        print("Found ", character[1], " at index ",
              character[0], ".")
