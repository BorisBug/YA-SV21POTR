/**
 * @file exercise-37.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 37 - use the run.sh file
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>

/*
Beskrivning
Make a program using functions to read an expression including two operands
and an operator as 3 arguments from command line and print the value of the
evaluated expression to the output. If the expression is not valid, print an
error message to the output.

The expression shall be in the format of operand1 operator operand2. E.g. 23 + 45.
The operands shall be two unsigned integers and the operator shall be +, -, *, / or %
The code for operators (add, subtract, multiply, divide and modulus functions) shall
be impelemented in a module (calculator)

For example:
 $ ./claculate.exe 23 + 45
 $ 23 + 45 = 68
*/

void operate(const char *v1, const char *v2, const char *operator)
{
    char op = 0;
    unsigned long long n1=0, n2=0, result=0;
    sscanf(v1, "%llu", &n1); // value 1
    sscanf(v2, "%llu", &n2); // value 2
    op = operator[0]; // operator

    int error = 0;
    switch (op)
    {
    case '+':   result = n1 + n2; break;
    case '-':   result = n1 - n2; break;
    case '/':   if(n2)
                    result = n1/n2;
                else
                {
                    error = 1;
                    printf("Error: Divide by 0\n");
                }
                break;
    case '*':   result = n1 * n2; break;
    case '%':   if(n2)
                    result = n1%n2;
                else
                {
                    error = 1;
                    printf("Error: Divide by 0\n");
                }
                break;
    default:    error = 1;
                printf("Error: Undefined operator '%c'\n", op);
                break;
    }

    if(!error)
        printf("%llu %c %llu = %llu\n", n1, op, n2, result);
}

int main(int argc, char *argv[])
{
//  printf("\n\nCount: %d\n", argc);
    
//  for(int i=0; i<argc; i++)
//      printf("val[%d]: %s\n", i, argv[i]);

    if(argc>=4)
        operate(argv[1], argv[3], argv[2]);

    /*
    // test
    operate("10", "20", "+");
    operate("10.5", "20.5", "+");
    operate("100", "20", "-");
    operate("100", "20.45", "-");
    operate("100", "3", "/");
    operate("3", "5", "*");
    operate("13", "10", "%");
    operate("3", "5", "?");
    */

    return 0;
}