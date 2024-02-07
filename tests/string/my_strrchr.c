#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strrchr.h"
#include "string.h"

// Test for finding the last occurrence of a character that exists within the string
void test_my_strrchr_char_found(void) {
    const char str[] = "Hello, World!";
    int ch = 'o';
    char* result = my_strrchr(str, ch);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_PTR(&str[8], result); // "o" in "World"
}

// Test for not finding a character that does not exist within the string
void test_my_strrchr_char_not_found(void) {
    const char str[] = "Hello, World!";
    int ch = 'x';
    char* result = my_strrchr(str, ch);
    TEST_ASSERT_NULL(result);
}

// Test for searching the null terminator, which should always be found
void test_my_strrchr_search_for_null_terminator(void) {
    const char str[] = "Hello, World!";
    int ch = '\0';
    char* result = my_strrchr(str, ch);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_PTR(&str[strlen(str)], result); // Points to '\0'
}

// Test for searching within an empty string
void test_my_strrchr_empty_string(void) {
    const char str[] = "";
    int ch = 'H';
    char* result = my_strrchr(str, ch);
    TEST_ASSERT_NULL(result);
}

// Test for finding a character that appears only once within the string
void test_my_strrchr_char_appears_once(void) {
    const char str[] = "Hello, World!";
    int ch = 'H';
    char* result = my_strrchr(str, ch);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_PTR(&str[0], result); // "H" at the start
}

