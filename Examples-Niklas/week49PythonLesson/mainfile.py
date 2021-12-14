import sys

# Imports a module from a package
from aFolder.aFolderInAFolder2 import file2
# Imports a module with the whole path as name
import aFolder.aFolderInAFolder2.file2
# Import a function from a module
from aFolder.aFolderInAFolder2.file2 import useOtherFolderToDivide
# Import multiple functions per a module
from aFolder.folderFile import Subtract, Subtract_Again
# Import a module from a package
import aFolder.folderFile
# Import module from working directory.
import anotherFile
# Import functions from module.
from anotherFile import Add, Multiply
# Imported folder as module
import aFolder

# importing a file and using its functions
anotherFile.Add(3, 5)
anotherFile.Multiply(3, 5)

# imported the functions from a file
Add(2, 5)
Multiply(5, 5)

#import sys
print("Places where the program will look for files to import:", sys.path)

# In order to use a file inside a folder that folder needs to be marked as a package.
# Do this by having a file called __init__.py in it.

# import aFolder.folderFile
# from aFolder.folderFile import Subtract

aFolder.folderFile.Subtract(5, 6)
Subtract(4, 3)

#from aFolder.aFolderInAFolder2.file2 import useOtherFolderToDivide
useOtherFolderToDivide(4, 2)

# from aFolder.aFolderInAFolder2 import file2

file2.useOtherFolderToDivide(2, 5)


print(dir(file2))  # Gets the attributes that's within a module.
print("File2 __name__:", file2.__name__)  # This gets the module name.
print("File2 __package__:", file2.__package__)  # This gets the package.
print("File2 __file__:", file2.__file__)  # This gets the absolute path.
