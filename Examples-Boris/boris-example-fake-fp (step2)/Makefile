CC := gcc
CFLAGS := -Wall -Werror
OBJECTS := build/get_uint32.o build/play.o build/test_uint32.o build/test_play.o build/main.o

help: 
	@echo ""
	@echo "************ The Targets ************"
	@echo "clean: to clean"
	@echo "main: to run the main program"
	@echo "check_uint: to run and test the module get_uint32"
	@echo "check_play: to run and test the module play"
	@echo "*************************************"
	@echo ""

# link: the main program
build/main: build/main.o build/get_uint32.o build/play.o
	$(CC) $^ --coverage -o $@

# link: test get_uint32
build/test_uint32: build/test_uint32.o build/get_uint32.o
	$(CC) $^ --coverage -lunity -o $@

# link: test play
build/test_play: build/test_play.o build/play.o
	$(CC) $^ --coverage -lunity -o $@

# compile: all object files
build/%.o: %.c
	$(CC) -MMD --coverage $(CFLAGS) -o $@ -c $<

# target: main
main: .mkbuild build/main
	@echo ""
	@echo "**************************************"
	@echo "Run the main program"
	@echo "**************************************"
	@echo ""
	@./build/main

# target: check_uint
check_uint: .mkbuild build/test_uint32
	@echo ""
	@echo "**************************************"
	@echo "Run the TEST for get_uint32"
	@echo "**************************************"
	@echo ""
	@./build/test_uint32; \
	gcovr -r . --html-details -o build/index.html

# target: check_play
check_play: .mkbuild build/test_play
	@echo ""
	@echo "**************************************"
	@echo "Run the TEST for play"
	@echo "**************************************"
	@echo ""
	@./build/test_play; \
	gcovr -r . --html-details -o build/index.html

# Include automatically generated dependencies
-include $(OBJECTS:.o=.d)

.PHONY: clean .mkbuild check_uint check_play main help

clean:
	@rm -rf build

.mkbuild:
	@mkdir -p build
