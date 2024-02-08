#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strspn.h"

// Test when all characters in lhs are found in rhs at the beginning
void test_my_strspn_all_chars_found(void) {
    const char* lhs = "abcde12345";
    const char* rhs = "abcde";
    size_t result = my_strspn(lhs, rhs);
    TEST_ASSERT_EQUAL(5, result);
}

// Test when no characters in lhs are found in rhs
void test_my_strspn_no_chars_found(void) {
    const char* lhs = "12345abcde";
    const char* rhs = "xyz";
    size_t result = my_strspn(lhs, rhs);
    TEST_ASSERT_EQUAL(0, result);
}

// Test when only some characters in lhs are found in rhs at the beginning
void test_my_strspn_some_chars_found(void) {
    const char* lhs = "abcde12345";
    const char* rhs = "abcd123";
    size_t result = my_strspn(lhs, rhs);
    TEST_ASSERT_EQUAL(4, result);
}

// Test with an empty lhs string
void test_my_strspn_empty_lhs(void) {
    const char* lhs = "";
    const char* rhs = "abcde";
    size_t result = my_strspn(lhs, rhs);
    TEST_ASSERT_EQUAL(0, result);
}

// Test with an empty rhs string
void test_my_strspn_empty_rhs(void) {
    const char* lhs = "abcde";
    const char* rhs = "";
    size_t result = my_strspn(lhs, rhs);
    TEST_ASSERT_EQUAL(0, result);
}

