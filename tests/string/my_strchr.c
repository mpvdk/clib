#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strchr.h"
#include "string.h"

// Test for finding a character that exists within the string
void test_my_strchr_char_found(void) {
    const char str[] = "Hello, World!";
    int ch = 'W';
    char* result = my_strchr(str, ch);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_PTR(&str[7], result);
}

// Test for not finding a character that does not exist within the string
void test_my_strchr_char_not_found(void) {
    const char str[] = "Hello, World!";
    int ch = 'x';
    char* result = my_strchr(str, ch);
    TEST_ASSERT_NULL(result);
}

// Test for searching the null terminator, which should always be found
void test_my_strchr_search_for_null_terminator(void) {
    const char str[] = "Hello, World!";
    int ch = '\0';
    char* result = my_strchr(str, ch);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_PTR(&str[strlen(str)], result);
}

// Test for searching within an empty string
void test_my_strchr_empty_string(void) {
    const char str[] = "";
    int ch = 'H';
    char* result = my_strchr(str, ch);
    TEST_ASSERT_NULL(result);
}

