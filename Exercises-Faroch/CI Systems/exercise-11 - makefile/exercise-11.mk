
all: mkbuild program build_test

.PHONY: all mkbuild build_main build_test check clean

program: build/fizzbuzz.o build/main.o
	gcc -o build/main build/fizzbuzz.o build/main.o

build/main.o: src/main.c lib/fizzbuzz/fizzbuzz.h
	gcc -c src/main.c -Ilib/fizzbuzz -o build/main.o

build/fizzbuzz.o: lib/fizzbuzz/fizzbuzz.c lib/fizzbuzz/fizzbuzz.h
	gcc -c lib/fizzbuzz/fizzbuzz.c -o build/fizzbuzz.o

build_test: build/fizzbuzz.o build/unity.o build/test.o
	gcc -o build/test build/fizzbuzz.o build/unity.o build/test.o

build/test.o: test/test.c lib/fizzbuzz/fizzbuzz.h lib/unity/unity.h
	gcc -c test/test.c -Ilib/fizzbuzz -Ilib/unity -o build/test.o

build/unity.o: lib/unity/unity.c lib/unity/unity.h lib/unity/unity_internals.h
	gcc -c lib/unity/unity.c -Ilib/unity -o build/unity.o

mkbuild:
	mkdir -p build

clean:
	rm -rf build

check: mkbuild build_test
	@echo "******************"
	@echo "***Run the test***"
	@echo "******************"
	@./build/test

run: mkbuild program
	@echo "*********************"
	@echo "***Run the program***"
	@echo "*********************"
	@./build/main $(number)
