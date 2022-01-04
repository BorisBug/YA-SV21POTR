#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char designation[20];
    int age;
} aStruct;

void addOne(int number)
{
    number += 1;
}

void addOneViaPointer(int *number)
{
    int n = *number;
    *number = n + n;
}

int addOneToBothValues(int *number1, int *number2)
{
    *number1 += 1;
    *number2 += 1;
    //By changing in dereferenced pointers we can change a variable in a different scope.

    return *number1;
}

/*void printAnyKindOfValue(int *voidPointer)
{

}
void printAnyKindOfValue(char *voidPointer)
{

}
void printAnyKindOfValue(float *voidPointer)
{

}*/
void printAnyKindOfValue(void *voidPointer, char type)
{
    int five = 5;
    float fivef = (float)five;
    int *intPointer = NULL;
    int contentsOfIntPointer = 5;
    char *charPointer = NULL;

    //If we receive a void-pointer, we can use the type it was sent through
    //to put it through a switch case function, and we do something different
    //depending on which kind of pointer it is. We type-cast the pointer to
    //a different kind of pointer depending on the type-value.
    switch (type)
    {
    case 'i':
        intPointer = (int *)voidPointer;
        contentsOfIntPointer = *(int *)voidPointer;
        printf("This was an int and it had the value %u.\n", *intPointer);
        break;
    case 'c':
        charPointer = (char *)voidPointer;
        printf("This was an char and it had the value %c.\n", *charPointer);
        break;
    default:
        break;
    }
}

int main()
{

    int five = 5;
    int *fivePointer = &five;
    // The above creates the pointer fivePointer and points it at the address of the variable five.

    int anotherFive = *fivePointer;
    // The above retrieves the value at the address fivePointer points at.

    // & before a variable means getting its address. "Get pointer to this variable" command.
    // * before a pointer means getting the value of the address it contains.

    printf("anotherFive is now: %u\n", anotherFive);

    printf("Five has the value of %u.\n", five);                    //Prints the value of five.
    printf("Five is at the address of %p.\n", &five);               //Prints the address of five.
    printf("FivePointer points at the address %p.\n", fivePointer); //Prints the address fivePointer is pointing at.
    printf("FivePointer points at a value of %u.\n", *fivePointer); //Prints the value of the address fivePointer is pointing at.

    aStruct thisSturct = {"Hiya", 22};
    aStruct *structPointer = &thisSturct;
    // We can create structs and point at them.

    printf("The struct has the designation %s and the age of %d.\n", structPointer->designation, (*structPointer).age);
    // To access variables of structs or other things through pointers, use -> after the pointer.
    // It also works to just dereference the pointer and retrieve the struct itself and then just .variable.

    int *wildPointer;
    printf("Wild pointer currently pointing at %p\n", wildPointer);
    // A wild pointer points at a random spot in memory. This is dangerous, because we don't know what it's pointing at.
    int *notAWildPointer = NULL;
    //Instead, make it a NULL pointer. NULL pointers are harmless, trying to use one just results in nothing,
    //instead of changing who knows what if we were to use a wild pointer accidentally.

    int aNumber = 6;
    int *aNumberPtr = &aNumber;
    // We can use pointers to get values from functions.
    addOne(aNumber);
    // addOne takes a value. The number we're sending along becomes a new variable set to the same
    // value as the one we sent. It no longer has any connection to the variable it was copied from.
    addOneViaPointer(aNumberPtr);
    // The same is true if we send a pointer, a new pointer is created, but it still points to the
    // same spot in memory. Hence, by changing the dereference of the pointer we're sending along,
    // we can change one or several variables by proxy by sending along their address in memory.
    printf("aNumber has the value of %u.\n", aNumber);

    int anotherNumber = 14;
    addOneToBothValues(&aNumber, &anotherNumber);
    // This one, for example, adds one to both aNumber and anotherNumber.
    printf("aNumber has the value of %u.\n", aNumber);
    printf("anotherNumber has the value of %u.\n", anotherNumber);

    void *voidPtr = &anotherNumber;
    //A void-pointer is a pointer that points to a value, but doesn't know what it is.
    //It is useful because it can be cast as any other type of pointer.
    char type = 'i';
    //It does, however, need some way to tell what kind of pointer it should be translated into.
    //For instance, a char which, if it's 'i', the void-pointer is an int. A different letter for
    //other types, and so on.

    char *charPtr = &type;

    printAnyKindOfValue(voidPtr, type);
    //Void pointers can be used make functions that take any kind of pointer. It just also
    //needs the type of the pointer to be sent along somehow.
    printAnyKindOfValue(charPtr, 'c');
    printAnyKindOfValue(charPtr, 'i');
    //Be careful. The compiler has no way of telling if we're making a mistake and sending
    //in the wrong kind of type for the pointer-type. We need to recognize this ourselves.

    const int sizeOfThisParticularArray = 4;

    int intArray[4] = {1, 2, 3, 4};
    printf("intArray: %p.\n", intArray);
    printf("intArray: %p.\n", &intArray);
    printf("intArray: %p.\n", &intArray[0]);
    //It is notable that the value of the array itself, the address of the array and the
    //address of the first element of the array is the exact same.

    int *intArrayPtr = intArray;
    //We can then create a pointer that points at the first element of the array, just like
    //the array itself. We can change a pointer we direct at the array, we can't change the
    //array-pointer marking where the array starts.

    printf("The value of intArray spot 1 is %i.\n", *intArrayPtr + 1);
    /*When we do basic math on a pointer we go in increments of how much memory the type
    of the variable the pointer points at takes. For instance, an int takes 4 bytes of memory.
    When we say +1 on an int-pointer, we move four spaces forward in memory, perfect for
    getting to the next int in the list. The same with any other form of arithmetic done
    on standard pointers.
    */

    for (int i = 0; i < 4; i++)
    {
        printf("The value of intArray spot %i is %i.\n", i, *intArrayPtr + i);
    }
    //We can use pointer + i to step through an array because of that.

    for (intArrayPtr = intArray; (intArrayPtr - intArray) < sizeOfThisParticularArray; intArrayPtr += 1)
    {
        printf("Currently at address %p. ", intArrayPtr);
        printf("The value of intArray spot %i is %i.\n", (intArrayPtr - intArray), *intArrayPtr);
    }
    /*Above we're using a pointer to step through an array. We first assign the pointer to the start
    of the array with intArrayPtr = intArray. When we then take a pointer minus another pointer we
    get the distance between them measured in the kind of pointers they are, meaning with int-pointers
    it is how many ints there are in between them, and that can be used to find out how far through the
    array they are and if they're exceeding the max size of this array.

    Finally intArrayPtr++ or intArrayPtr += 1 steps forward through the array using said pointer. We
    then don't have to use i or something like that at all, because with each step intArrayPtr will be
    on top of the next value in the array. We can still use (intArrayPtr - intArray) to get the current
    index. 
    */
    intArrayPtr = intArray;

    int elements1[3] = {1, 2, 3};
    int elements2[3] = {4, 5, 6};
    int elements3[3] = {7, 8, 9};

    int *ptrArray[3] = {elements1, elements2, elements3};
    //By creating an array of pointers we can create a multidimensional array.

    printf("ptrArray[][] has a value that is %u.\n", *(*(ptrArray + 2) + 2) /*ptrArray[2][2]*/);
    printf("ptrArray[][] has a value that is %u.\n", /**(*(ptrArray + 2) + 2)*/ ptrArray[2][2]);
    //They can then access the various elements in any of these two ways.

    int multidimensionalArray[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int(*matrixPointer)[3] = multidimensionalArray;
    printf("matrixPointer[1][2] = %u\n", matrixPointer[1][2]);
    printf("matrixPointer[2][2] = %u\n", *(*(matrixPointer + 2) + 2));

    int eight = 8;
    int *eightPtr = &eight;
    int **eightPtrPtr = &eightPtr;
    int ***eightPtrPtrPtr = &eightPtrPtr;
    //We can make pointers to pointers to pointers to pointers. They're now in a line.
    //This could be useful if we, for instance, have a bunch of structs that contain a
    //pointer that we want to all point in the same direction. If we point them at a
    //pointer, then if the value they're looking at need to be changed then we can just
    //change where that pointer //is looking at, no need to change the pointer in each
    //and every struct.

    printf("The value is %u.\n", ***eightPtrPtrPtr);
    //For each dereference we go through another pointer

    return 0;
}