#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strcat.h"

// Test for concatenating two normal strings
void test_my_strcat_normal_use(void) {
    char dest[20] = "Hello, ";
    const char src[] = "World!";
    my_strcat(dest, src);
    TEST_ASSERT_EQUAL_STRING("Hello, World!", dest);
}

// Test for concatenating with an empty source string
void test_my_strcat_empty_source(void) {
    char dest[20] = "Hello";
    const char src[] = "";
    my_strcat(dest, src);
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
}

// Test for concatenating to an empty destination string
void test_my_strcat_empty_destination(void) {
    char dest[20] = "";
    const char src[] = "World!";
    my_strcat(dest, src);
    TEST_ASSERT_EQUAL_STRING("World!", dest);
}

// Test for handling a NULL source
void test_my_strcat_null_source(void) {
    char dest[20] = "Hello";
    const char* src = NULL;
    // my_strcat handles NULL src by not modifying dest
    my_strcat(dest, src);
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
}

// Test to check the return value
void test_my_strcat_check_return_value(void) {
    char dest[20] = "Hello, ";
    const char src[] = "World!";
    char* result = my_strcat(dest, src);
    TEST_ASSERT_EQUAL_PTR(dest, result);
}

