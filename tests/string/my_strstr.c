#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strstr.h"

// Test searching for a substring at the start of a string
void test_find_substring_at_start(void) {
    char* result = my_strstr("hello world", "hello");
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("hello world", result);
}

// Test searching for a substring in the middle of a string
void test_find_substring_in_middle(void) {
    char* result = my_strstr("hello world", "lo wo");
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("lo world", result);
}

// Test searching for a substring at the end of a string
void test_find_substring_at_end(void) {
    char* result = my_strstr("hello world", "world");
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("world", result);
}

// Test when the substring is not found
void test_substring_not_found(void) {
    char* result = my_strstr("hello world", "universe");
    TEST_ASSERT_NULL(result);
}

// Test searching with an empty substring
void test_empty_substring(void) {
    char* result = my_strstr("hello world", "");
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("hello world", result);
}

// Test when haystack is NULL should return NULL
void test_null_haystack_returns_null(void) {
    char* result = my_strstr(NULL, "world");
    TEST_ASSERT_NULL(result);
}

// Test when needle is NULL, should return the original haystack
void test_null_needle_returns_haystack(void) {
    char* haystack = "hello world";
    char* result = my_strstr(haystack, NULL);
    TEST_ASSERT_EQUAL_PTR(haystack, result);
}
