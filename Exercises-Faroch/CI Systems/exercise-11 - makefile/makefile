

all: clean mkbuild main.exe

main.exe: build/main.o build/fizzbuzz.o
	gcc build/main.o build/fizzbuzz.o -o build/main.exe

test.exe: build/unity.o build/fizzbuzz.o build/test.o
	gcc build/unity.o build/fizzbuzz.o build/test.o -o build/test.exe

build/main.o: build/fizzbuzz.o src/main.c lib/fizzbuzz/fizzbuzz.h
	gcc -c src/main.c -Ilib/fizzbuzz -o build/main.o

build/unity.o: lib/unity/unity.c lib/unity/unity.h
	gcc -c lib/unity/unity.c -o build/unity.o

build/fizzbuzz.o: lib/fizzbuzz/fizzbuzz.c lib/fizzbuzz/fizzbuzz.h
	gcc -c lib/fizzbuzz/fizzbuzz.c -o build/fizzbuzz.o

build/test.o: build/fizzbuzz.o test/test.c lib/unity/unity.h lib/fizzbuzz/fizzbuzz.h 
	gcc -c test/test.c -Ilib/unity -Ilib/fizzbuzz -o build/test.o

##################

.PHONY: all clean mkbuild check

clean:
	clear && rm -rf build

mkbuild:
	mkdir -p build

check: clean mkbuild test.exe
	./build/test.exe

