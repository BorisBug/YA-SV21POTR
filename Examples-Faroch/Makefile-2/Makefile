# An example Makefile using variables, pattern rules and functions

# The compiler
CC = gcc

# The compiler flags
CFLAG = -Wall

# Buil directory to store the object files
BUILDDIR = build

# Name of the executable program
PROGRAM_EXE = app.exe

# Using wildcard and addprefix functions to get the list of the .c files
SOURCES := $(wildcard *.c)

# Using variable substitution to get name of the object files
OBJECTS := $(SOURCES:.c=.o)

# Using addprefix to prepend $(BUILDDIR)/ to the object files
# Note that if OBJECT is a recursively expanded variable the following assignment is an endless assignment
OBJECTS := $(addprefix $(BUILDDIR)/, $(OBJECTS))

# A macro to clean the project
define CLEAN_PROJECT
	@rm -rf $(BUILDDIR)
	@echo $(BUILDDIR) directory was deleted
endef

all: mkbuild $(PROGRAM_EXE)

# Build the executable file
$(PROGRAM_EXE): $(OBJECTS)
	$(CC) $(CFLAG) -o $@ $^

# Compile the source files
$(BUILDDIR)/%.o: %.c 
	$(CC) $(CFLAG) -c $< -o $@

# Phony targets
.PHONY: all clean mkbuild

clean:
#   Using the macro
	$(CLEAN_PROJECT)

# Make directory build
mkbuild:
	@mkdir -p $(BUILDDIR)

# OS detection
OS_NAME = Windows
ifneq ($(OS), Windows_NT)
	UNAME = $(shell uname -s)
	ifeq ($(UNAME), Linux)
		OS_NAME = Linux
	else
		OS_NAME = Unknown
	endif
endif

run: all
	@echo ""
	@echo "**************************"
	@echo "*** OS: $(OS_NAME)"
	@echo "*** Run The Program"
	@echo "**************************"
	@echo ""
#	Run the program
	@./$(PROGRAM_EXE)
