# The Makefile to build and run the test

CC := gcc
CFLAGS := -Wall

LIB_DIR := lib
TEST_DIR := test
TEST_EXE := test
BUILD_DIR := build

INCLUDES := $(addprefix -I./,$(wildcard $(LIB_DIR)/*))
OBJECTS := $(notdir $(wildcard $(LIB_DIR)/*/*.c) $(wildcard $(TEST_DIR)/*.c))
OBJECTS := $(addprefix $(BUILD_DIR)/,$(OBJECTS:.c=.o))

all:
	@clear
	@echo "************ The Targets *************"
	@echo "** clean: to clean"
	@echo "** check: to build and test the module"
	@echo "**************************************"

$(TEST_EXE): $(OBJECTS)
	$(CC) $^ -o $(BUILD_DIR)/$@

LIB_SRC := $(LIB_DIR)/*
$(BUILD_DIR)/%.o: $(LIB_SRC)/%.c
# -MMD Generates the dependencies automatically. E.g. build/datetime.d
	$(CC) -MMD $(CFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.c
	$(CC) -MMD $(CFLAGS) -o $@ $(INCLUDES) -c $<

check: mkbuild $(TEST_EXE)
	@echo ""
	@echo "**************************************"
	@echo "********** Run The Test **************"
	@echo "**************************************"
	@echo ""
	@./$(BUILD_DIR)/$(TEST_EXE)

# Include automatically generated dependencies
-include $(OBJECTS:.o=.d)

.PHONY: clean mkbuild check all

clean:
	@rm -rf $(BUILD_DIR)

mkbuild:
	@mkdir -p $(BUILD_DIR)
