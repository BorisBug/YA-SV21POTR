"""
Beskrivning

Using the os module make a program to find and compile the source(.c) files
in a project with any structure (means that generate the .o files).

To run commands you can use the os.system function. E.g. os.system("gcc -c example.c")

The program shall implement a generalized solution. You can use the fizzbuzz project as an example.

You need to import os
Look at https://docs.python.org/3/library/os.html
"""
import os
from pathlib import Path

def CollectSourceFiles(path: Path, files: list):
    for file in path.iterdir():
        if file.name=='..':
            pass
        if file.is_file() and file.suffix=='.c':
            print("compile:", file)
            files.append(file.absolute())
        elif file.is_dir() and file.name!='.':
            CollectSourceFiles(file, files)

files = []
path = Path()
CollectSourceFiles(path, files)

# iterdir retrieves a list of things in the directory so we can iterate over them.
for p in path.iterdir():
    print("iterdir:", p)

#for file in files:
#    print