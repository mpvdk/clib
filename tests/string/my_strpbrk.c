#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strpbrk.h"

// Test for checking behavior with an empty string
void test_my_strpbrk_empty_string(void) {
    // Checks behavior with the first string being empty
    TEST_ASSERT_NULL(my_strpbrk("", "abc"));
}

// Test for checking when there's no match
void test_my_strpbrk_no_match(void) {
    // Verifies function when no characters in str1 are found in str2
    TEST_ASSERT_NULL(my_strpbrk("hello", "xyz"));
}

// Test for checking when the first character matches
void test_my_strpbrk_first_char_match(void) {
    // Checks when the first character in str1 is found in str2
    TEST_ASSERT_EQUAL_PTR(&my_strpbrk("ahello", "a")[0], &"ahello"[0]);
}

// Test for checking normal operation
void test_my_strpbrk_normal_operation(void) {
    // Tests typical usage scenario where a match occurs in the middle
    TEST_ASSERT_EQUAL_PTR(&my_strpbrk("hello world", " w")[0], &"hello world"[5]);
}

// Test for checking match at the end of the string
void test_my_strpbrk_match_at_end(void) {
    // Verifies function when the matching character is at the end of str1
    TEST_ASSERT_EQUAL_PTR(&my_strpbrk("hello", "o")[0], &"hello"[4]);
}

