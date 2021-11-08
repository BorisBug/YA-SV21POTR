#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Prime numbers.
1. a. Printout the first 100 primes.
   b. Printout every tenth prime of the first 1000 primes.
*/

// Not optimized -- gross 'obvious' calculation
bool is_prime_old(int x)
{
    // never <2
    if(x<2)
       return false;

    // only divisible by 1 & itself
    for(unsigned i=2; i<=x/2; i++)
       if(x%i==0)
          return false;

    return true;
}

// Best optimization
bool is_prime(int x)
{
    // never <2
    if(x<2)
        return false;

    // only divisible by 1 & itself
    unsigned max = sqrt(x);
    for(unsigned i=2; i<=max; i++)
        if(x%i==0)
            return false;

    return true;
}

// print & add line if it is the end column (gentle format)
void print_prime(unsigned n, unsigned counter)
{
    if(counter && counter%10==0)
        printf("\n");

    printf("%5u ", n);
}

void print_primes_amount(unsigned max)
{
    for(unsigned i=2, j=0; j<max; i++)
        if(is_prime(i))
            print_prime(i,j++);
    
    printf("\n");
}

void print_primes_skip(unsigned max, unsigned skip)
{
    for(unsigned i=2, j=0, k=0; k<max; i++)
        if(is_prime(i) && (k++ % skip)==0)
            print_prime(i,j++);

    printf("\n");
}

void ex_1a()
{
    print_primes_amount(100);
}

void ex_1b()
{
    print_primes_skip(1000, 10);
}


/*
## Simple Bitwise.
2. a. Print an unsinged char as its binary representation.
   b. Print the binary representation of a number up to 64bits.
   Need to know how big the number is in bytes for B. sizeof() helps.
*/ 

void print_uc2bin(unsigned char c)
{
    unsigned bits = sizeof(c)*8;
    char mask = 1 << (bits-1);

    printf("char: '%c' (%d)  bin: ", c, c);

    for(char i=0; i<bits; i++, c<<=1)
    {
        if(i && i%4==0)
            printf(".");

        printf("%c", (c&mask) ? '1' : '0');
    }

    printf("\n");
}

void print_ll2bin(long long n, unsigned bytes)
{
    unsigned bits = bytes*8;
    unsigned long long mask = 1ull << (bits-1);

    printf("number: %lld (%u bits)\nbin: ", n, bits);

    for(unsigned i=0; i<bits; i++, n<<=1)
    {
        if(i)
        {   // formatting only for "reading" purposes
            if(i%32==0) printf(" + ");
            else if(i%8==0) printf("-");
            else if(i%4==0) printf(".");
        }

        printf("%c", (n&mask) ? '1' : '0');

    }

    printf("\n\n");
}

void ex_2a()
{
    print_uc2bin('0');
    print_uc2bin('A');
    print_uc2bin(' ');
    print_uc2bin('@');
}

void ex_2b()
{
    // 64 bits (8 bytes)
    int64_t n1 = 0x0000000000000001;
    print_ll2bin(n1, sizeof(n1));
    int64_t n2 = 0x8000000000000000;
    print_ll2bin(n2, sizeof(n2));
    int64_t n3 = 0x8888888811111111;
    print_ll2bin(n3, sizeof(n3));
    int64_t n4 = 0x7FFFFFFFFFFFFFFF; // biggest positive
    print_ll2bin(n4, sizeof(n4));
    int64_t n5 = 0x80008000F0001000;
    print_ll2bin(n5, sizeof(n5));

    // 32 bits (4 bytes)
    int32_t n6 = 1;
    print_ll2bin(n6, sizeof(n6));
    int32_t n7 = 0xFF000000;
    print_ll2bin(n7, sizeof(n7));

    // 16 bits (2 bytes)
    int16_t n8 = 0x0001;
    print_ll2bin(n8, sizeof(n8));
    int16_t n9 = 0x8000;
    print_ll2bin(n9, sizeof(n9));

    // 8 bits (1 byte)
    int8_t n10 = 1;
    print_ll2bin(n10, sizeof(n10));
    int8_t n11 = 0x80;
    print_ll2bin(n11, sizeof(n11));
    int8_t n12 = 0x7F;
    print_ll2bin(n12, sizeof(n12));
}

/*
## Reversing
3. a. Reverse a string with a maximum of 213 letters.
   b. Reverse the bit order of unsinged char. ie 1000 0000 -> 0000 0001
*/

void print_reverse_string(char *str)
{
    char rev[214]; // WARNING: no memory verification
    unsigned len = strlen(str);

    printf("before: %s\n", str);

    for(unsigned i=0;i<len;i++)
        rev[i] = str[len-i-1];

    rev[len]=0;
    printf("after: %s\n", rev);
}

void print_reverse_char(char chr)
{
    char rev = 0;
    unsigned bits = sizeof(chr)*8;

    printf("before --> ");
    print_uc2bin(chr);

    for(char i=0; i<bits; i++)
    {
        rev <<= 1;
        rev |= chr&1;
        chr >>= 1;
    }

    printf("after  --> ");
    print_uc2bin(rev);

    printf("\n");
}

void ex_3a()
{   
    print_reverse_string("A");
    print_reverse_string("AB");
    print_reverse_string("ABC");
    print_reverse_string("ABD-1234");
    print_reverse_string("1234567890ABCDEFGHI");
}

void ex_3b()
{
    print_reverse_char('A');
    print_reverse_char('#');
    print_reverse_char('z');
}

/*
## Sorting
4. Sort an array of unsigned ints. Make two functions, one Ascending, one Descending.
   To get you started: sorting.c
*/

// randomize the content of the array
void rand_array(unsigned *arr, unsigned size)
{
    srand(time(NULL));
    for(unsigned i=0; i<size; i++)
        arr[i] = rand() % 10000; // cap to 10000 just for testing purposes
}

void print_array(unsigned *arr, unsigned size)
{
    for(unsigned i=0; i<size; i++)
    {
        if(i && i%10==0) 
            printf("\n");

        printf("%4u, ", arr[i]);
    }

    printf("\n\n");
}

// swap the content of two variables
void swap(unsigned *a, unsigned *b)
{
    unsigned c = *a;
    *a = *b;
    *b = c;
}

// simple bubble sort algorithm
void sort_asc(unsigned *src, unsigned size)
{
    for(unsigned i=0; i<size; i++)
    for(unsigned j=i+1; j<size; j++)
    if(src[i]>src[j])
        swap(src+i,src+j);
}

// simple bubble sort algorithm
void sort_desc(unsigned *src, unsigned size)
{
    for(unsigned i=0; i<size; i++)
    for(unsigned j=i+1; j<size; j++)
    if(src[i]<src[j])
        swap(src+i,src+j);
}

void ex_4()
{
    // WARNING: no memmory verification
    unsigned size = 50;
    unsigned *src = (unsigned*)malloc(size*sizeof(unsigned));

    printf("Original array:\n");
    rand_array(src, size);
    print_array(src, size);

    printf("Sort ascending:\n");
    sort_asc(src, size);
    print_array(src, size);

    printf("Sort descending:\n");
    sort_desc(src, size);
    print_array(src, size);
 
    free(src);
}

int main()
{


    printf("\n\n\n\n\n\n\n");

    printf("## Prime numbers.\n");
    printf("1. a. Printout the first 100 primes.\n\n");
    ex_1a();
    printf("\n");

    printf("## Prime numbers.\n");
    printf("1. b. Printout every tenth prime of the first 1000 primes.\n\n");
    ex_1b();
    printf("\n");

    printf("## Simple Bitwise.\n");
    printf("2. a. Print an unsinged char as its binary representation.\n\n");
    ex_2a();
    printf("\n");

    printf("## Simple Bitwise.\n");
    printf("2. b. Print the binary representation of a number up to 64bits.\n\n");
    ex_2b();
    printf("\n");

    printf("## Reversing\n");
    printf("3. a. Reverse a string with a maximum of 213 letters.\n\n");
    ex_3a();
    printf("\n");

    printf("## Reversing\n");
    printf("3. b. Reverse the bit order of unsinged char. ie 1000 0000 -> 0000 0001\n\n");
    ex_3b();
    printf("\n");

    printf("## Sorting\n");
    printf("4. Sort an array of unsigned ints. Make two functions, one Ascending, one Descending.\n\n");
    ex_4();
    printf("\n");

    printf("bye bye!\n\n");
    return 0;
}