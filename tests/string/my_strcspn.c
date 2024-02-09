#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strcspn.h"

// Test for checking empty string and reject set
void test_my_strcspn_empty_string(void) {
    TEST_ASSERT_EQUAL(0, my_strcspn("", "abc"));
}

// Test for checking string with no matching characters
void test_my_strcspn_no_match(void) {
    TEST_ASSERT_EQUAL(5, my_strcspn("hello", "abc"));
}

// Test for checking string with all characters in reject set
void test_my_strcspn_all_chars_match(void) {
    TEST_ASSERT_EQUAL(0, my_strcspn("abc", "abc"));
}

// Test for checking string with first character match
void test_my_strcspn_first_char_match(void) {
    TEST_ASSERT_EQUAL(0, my_strcspn("ahello", "abc"));
}

// Test for checking normal operation
void test_my_strcspn_normal_operation(void) {
    TEST_ASSERT_EQUAL(5, my_strcspn("hello world", " d"));
}

// Test for checking normal operation
void test_my_strcspn_normal_operation_two(void) {
    TEST_ASSERT_EQUAL(10, my_strcspn("hello world", "d"));
}
