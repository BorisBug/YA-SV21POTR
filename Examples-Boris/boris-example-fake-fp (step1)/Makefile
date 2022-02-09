CC := gcc
CFLAGS := -Wall -Werror
OBJECTS := build/module.o build/test.o build/main.o

help: 
	@echo ""
	@echo "************ The Targets ************"
	@echo "clean: to clean"
	@echo "main: to run the main program"
	@echo "check: to run the test"
	@echo "*************************************"
	@echo ""

build/main: build/main.o build/module.o
	$(CC) $^ --coverage -o $@

build/test: build/test.o build/module.o
	$(CC) $^ --coverage -lunity -o $@

build/%.o: %.c
	$(CC) -MMD --coverage $(CFLAGS) -o $@ -c $<

main: .mkbuild build/main
	@echo ""
	@echo "**************************************"
	@echo "Run the main program"
	@echo "**************************************"
	@echo ""
	@./build/main

check: .mkbuild build/test
	@echo ""
	@echo "**************************************"
	@echo "Run the TEST"
	@echo "**************************************"
	@echo ""
	@./build/test
	@gcovr -r . --html-details -o build/index.html
#if you have problems with gcovr you can use the code below and use 'lcov' together with 'genhtml'
	@lcov -c -d build -o build/coverage.info
	@lcov -r build/coverage.info "*Xcode.app*" "*unity*" -o build/coverage-filtered.info
	@genhtml build/coverage-filtered.info -o build/HTML


# Include automatically generated dependencies
-include $(OBJECTS:.o=.d)

.PHONY: clean .mkbuild check main help

clean:
	@rm -rf build

.mkbuild:
	@mkdir -p build
