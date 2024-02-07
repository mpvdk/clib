#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strcmp.h"

// Test for comparing two equal strings
void test_my_strcmp_equal_strings(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Hello, World!";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_EQUAL(0, result);
}

// Test for when the first string is greater (lexicographically)
void test_my_strcmp_first_string_greater(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Hello, World";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_GREATER_THAN(0, result);
}

// Test for when the second string is greater (lexicographically)
void test_my_strcmp_second_string_greater(void) {
    const char* lhs = "Hello, World";
    const char* rhs = "Hello, World!";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_LESS_THAN(0, result);
}

// Test for comparing an empty first string with a non-empty second string
void test_my_strcmp_empty_first_string(void) {
    const char* lhs = "";
    const char* rhs = "Hello, World!";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_LESS_THAN(0, result);
}

// Test for comparing a non-empty first string with an empty second string
void test_my_strcmp_empty_second_string(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_GREATER_THAN(0, result);
}

// Test for comparing two empty strings
void test_my_strcmp_both_empty_strings(void) {
    const char* lhs = "";
    const char* rhs = "";
    int result = my_strcmp(lhs, rhs);
    TEST_ASSERT_EQUAL(0, result);
}

