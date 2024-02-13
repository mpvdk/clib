#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strtok.h"

// Test tokenization with a single character as delimiter
void test_single_char_delim(void) {
    char str[] = "hello world example";
    char* token = my_strtok(str, " ");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("hello", token);
    token = my_strtok(NULL, " ");
    TEST_ASSERT_EQUAL_STRING("world", token);
}

// Test tokenization with multiple characters as delimiters
void test_multi_char_delim(void) {
    char str[] = "hello, world; example";
    char* token = my_strtok(str, ",; ");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("hello", token);
    token = my_strtok(NULL, ",; ");
    TEST_ASSERT_EQUAL_STRING("world", token);
}

// Test when no delimiter is present in the string
void test_no_delim_in_str(void) {
    char str[] = "helloworld";
    char* token = my_strtok(str, " ");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("helloworld", token);
}

// Test with an empty string
void test_empty_str(void) {
    char str[] = "";
    char* token = my_strtok(str, " ");
    TEST_ASSERT_NULL(token);
}

// Test passing NULL to `str` on subsequent calls
void test_null_str_on_subsequent_calls(void) {
    char str[] = "hello world example";
    my_strtok(str, " "); // First call with the string
    char* token = my_strtok(NULL, " "); // Subsequent call with NULL
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("world", token);
}

// Test delimiter at the start and end of the string
void test_delim_at_start_and_end(void) {
    char str[] = " hello world ";
    char* token = my_strtok(str, " ");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("hello", token);
    token = my_strtok(NULL, " ");
    TEST_ASSERT_EQUAL_STRING("world", token);
}

// Test handling of consecutive delimiters
void test_consecutive_delimiters(void) {
    char str[] = "hello,,world";
    char* token = my_strtok(str, ",");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("hello", token);
    token = my_strtok(NULL, ",");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("world", token);
    TEST_ASSERT_NULL(my_strtok(NULL, ","));
}

// Test when the string consists only of delimiters
void test_only_delimiters(void) {
    char str[] = ",,,";
    char* token = my_strtok(str, ",");
    TEST_ASSERT_NULL(token); // Should return NULL since no tokens are present
}

// Test a delimiter at the end of the string
void test_delimiter_at_end(void) {
    char str[] = "hello world,";
    char* token = my_strtok(str, ",");
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL_STRING("hello world", token);
    token = my_strtok(NULL, ",");
    TEST_ASSERT_NULL(token); // No more tokens after the delimiter at the end
}

