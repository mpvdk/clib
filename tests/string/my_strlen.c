#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strlen.h"

// Test for calculating the length of an empty string
void test_my_strlen_empty_string(void) {
    const char* str = "";
    size_t result = my_strlen(str);
    TEST_ASSERT_EQUAL(0, result);
}

// Test for calculating the length of a basic string
void test_my_strlen_basic_string(void) {
    const char* str = "Hello";
    size_t result = my_strlen(str);
    TEST_ASSERT_EQUAL(5, result);
}

// Test for calculating the length of a string that includes spaces
void test_my_strlen_string_with_spaces(void) {
    const char* str = "Hello, World!";
    size_t result = my_strlen(str);
    TEST_ASSERT_EQUAL(13, result);
}

