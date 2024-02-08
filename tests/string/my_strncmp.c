#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strncmp.h"

// Test for comparing two equal strings within the specified count
void test_my_strncmp_equal_strings(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Hello, World!";
    int result = my_strncmp(lhs, rhs, 13); // Full length
    TEST_ASSERT_EQUAL(0, result);
}

// Test for when the first string is greater (lexicographically) within the specified count
void test_my_strncmp_first_string_greater(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Hello, World";
    int result = my_strncmp(lhs, rhs, 13); // Full length
    TEST_ASSERT_GREATER_THAN(0, result);
}

// Test for when the second string is greater (lexicographically) within the specified count
void test_my_strncmp_second_string_greater(void) {
    const char* lhs = "Hello, World";
    const char* rhs = "Hello, World!";
    int result = my_strncmp(lhs, rhs, 13); // Full length
    TEST_ASSERT_LESS_THAN(0, result);
}

// Test for comparing zero characters, which should always be equal
void test_my_strncmp_compare_zero_characters(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Goodbye, World!";
    int result = my_strncmp(lhs, rhs, 0); // Zero characters
    TEST_ASSERT_EQUAL(0, result);
}

// Test for comparing a part of the strings
void test_my_strncmp_compare_partial(void) {
    const char* lhs = "Hello, World!";
    const char* rhs = "Hello, there!";
    int result = my_strncmp(lhs, rhs, 7); // Compare "Hello, "
    TEST_ASSERT_EQUAL(0, result);
}

// Test for specifying a count longer than both strings
void test_my_strncmp_length_greater_than_strings(void) {
    const char* lhs = "Hello";
    const char* rhs = "Hello";
    int result = my_strncmp(lhs, rhs, 10); // Count exceeds string lengths
    TEST_ASSERT_EQUAL(0, result);
}

