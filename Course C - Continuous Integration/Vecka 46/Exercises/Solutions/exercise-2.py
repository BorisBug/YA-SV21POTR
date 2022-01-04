a_string = input("Input a string: ")
reverse_string = a_string[::-1]
print(reverse_string)

# Alternatively
reverse_string = reversed(a_string)
print(''.join(reverse_string))

# Using a Stack
new_list = []
for character in a_string:
    new_list.append(character)
new_list_length = len(new_list)
for character in range(new_list_length):
    print(new_list.pop(), end="")
