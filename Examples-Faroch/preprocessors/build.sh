# Clear the terminal, make build directory and clean the content of build
clear && mkdir -p build && rm -rf ./build/*

# BUFSIZE is defined as 10 in during compilation

## It is possible to compile multiple source files in a command
## We can specify the directory path to the header files which are used by the program. -I<directory> is the flag we can use. 
gcc main.c ./lib/mylib.c -DBUFSIZE=10 -I./lib -o ./build/main

## Even it is possible to compile the source files one by one and then link them to make the program.
# gcc -c main.c -DBUFSIZE=10 -I./lib -o ./build/main.o
# gcc -c ./lib/mylib.c -o ./build/mylib.o
# gcc ./build/mylib.o ./build/main.o -o ./build/main

# Run the program
./build/main
