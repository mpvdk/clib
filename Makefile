CC := gcc
CFLAGS := -Wall -Werror -g
LDFLAGS :=

# Directories
SRC_DIR := src
TESTS_DIR := tests
UNITY_DIR := $(TESTS_DIR)/unity
BUILD_DIR := bld
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin

# Automatically find source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
UNITY_FILES := $(wildcard $(UNITY_DIR)/*.c)
STRING_TEST_FILES := $(wildcard $(TESTS_DIR)/string/*.c)
STDIO_TEST_FILES := $(wildcard $(TESTS_DIR)/stdio/*.c)
TEST_RUNNER := $(TESTS_DIR)/test_runner.c

# Object files
SRC_OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
UNITY_OBJ_FILES := $(UNITY_FILES:$(UNITY_DIR)/%.c=$(OBJ_DIR)/%.o)
STRING_TEST_OBJ_FILES := $(STRING_TEST_FILES:$(TESTS_DIR)/string/%.c=$(OBJ_DIR)/%.o)
STDIO_TEST_OBJ_FILES := $(STDIO_TEST_FILES:$(TESTS_DIR)/stdio/%.c=$(OBJ_DIR)/%.o)
TEST_RUNNER_OBJ := $(TEST_RUNNER:$(TESTS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Test targets
STRING_TESTS := $(BIN_DIR)/string_tests
STDIO_TESTS := $(BIN_DIR)/stdio_tests

.PHONY: all clean string_tests stdio_tests

all: string stdio

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNITY_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TESTS_DIR)/string/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TESTS_DIR)/stdio/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TESTS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

string: _prepare_dirs $(SRC_OBJ_FILES) $(UNITY_OBJ_FILES) $(STRING_TEST_OBJ_FILES) $(TEST_RUNNER_OBJ)
	$(CC) $(LDFLAGS) -o $(STRING_TESTS) $(SRC_OBJ_FILES) $(UNITY_OBJ_FILES) $(STRING_TEST_OBJ_FILES) $(TEST_RUNNER_OBJ)
	@echo 
	@echo ==== SUCCESS =====
	@echo test runner built: ./tests/bld/bin/string_tests

stdio: _prepare_dirs $(SRC_OBJ_FILES) $(UNITY_OBJ_FILES) $(STDIO_TEST_OBJ_FILES) $(TEST_RUNNER_OBJ)
	$(CC) $(LDFLAGS) -o $(STDIO_TESTS) $(SRC_OBJ_FILES) $(UNITY_OBJ_FILES) $(STDIO_TEST_OBJ_FILES) $(TEST_RUNNER_OBJ)
	@echo 
	@echo ==== SUCCESS =====
	@echo test runner built: ./tests/bld/bin/stdio_tests

# Ensure directories are created before compiling anything
_prepare_dirs: $(OBJ_DIR) $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
