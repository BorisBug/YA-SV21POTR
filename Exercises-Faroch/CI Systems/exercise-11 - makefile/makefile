

all: clean mkbuild main.exe

main.exe: main.o fizzbuzz.o
	gcc build/main.o build/fizzbuzz.o -o build/main.exe

test.exe: unity.o fizzbuzz.o test.o
	gcc build/unity.o build/fizzbuzz.o build/test.o -o build/test.exe

main.o: fizzbuzz.o
	gcc -c src/main.c -Ilib/fizzbuzz -o build/main.o

unity.o:
	gcc -c lib/unity/unity.c -o build/unity.o

fizzbuzz.o:
	gcc -c lib/fizzbuzz/fizzbuzz.c -o build/fizzbuzz.o

test.o: fizzbuzz.o
	gcc -c test/test.c -Ilib/unity -Ilib/fizzbuzz -o build/test.o

.PHONY: all clean mkbuild check

clean:
	clear && rm -rf build

mkbuild:
	mkdir -p build

check: test.exe
	./build/test.exe

