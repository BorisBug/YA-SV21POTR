# Relative. Finds the target relative to the file's location.
from ..aFolderInAFolder1.fileInFolder1 import Divide
# Absolute. Finds the target from the root package.
from aFolder.aFolderInAFolder1.fileInFolder1 import Divide


def useOtherFolderToDivide(number1, number2):
    print("Passing through file 2!")
    return Divide(number1, number2)
