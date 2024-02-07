#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strncat.h"
#include "string.h"

// Test for normal use case
void test_my_strncat_normal_use(void) {
    char dest[20] = "Hello, ";
    const char append[] = "World!";
    my_strncat(dest, append, strlen(append) + 1); // +1 to copy the null terminator
    TEST_ASSERT_EQUAL_STRING("Hello, World!", dest);
}

// Test for appending less characters than count
void test_my_strncat_append_less_than_count(void) {
    char dest[20] = "Hello";
    const char append[] = ", there";
    my_strncat(dest, append, 10); // Count is more than append length
    TEST_ASSERT_EQUAL_STRING("Hello, there", dest);
}

// Test for appending more characters than count
void test_my_strncat_append_more_than_count(void) {
    char dest[20] = "Hello";
    const char append[] = ", beautiful world!";
    my_strncat(dest, append, 5); // Only part of append should be concatenated
    TEST_ASSERT_EQUAL_STRING("Hello, bea", dest);
}

// Test for count being zero
void test_my_strncat_count_zero(void) {
    char dest[20] = "Hello";
    const char append[] = " world";
    my_strncat(dest, append, 0); // No characters should be appended
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
}

// Test to check the return value
void test_my_strncat_check_return_value(void) {
    char dest[20] = "Hello, ";
    const char append[] = "World!";
    char* result = my_strncat(dest, append, strlen(append) + 1);
    TEST_ASSERT_EQUAL_PTR(dest, result);
}
