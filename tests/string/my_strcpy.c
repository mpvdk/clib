#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strncmp.h"

// Test for basic string copy functionality
void test_my_strcpy_basic_copy(void) {
    char dest[20];
    const char src[] = "Hello, World!";
    my_strcpy(dest, src);
    TEST_ASSERT_EQUAL_STRING(src, dest);
}

// Test to verify the return value is the destination string
void test_my_strcpy_return_value(void) {
    char dest[20];
    const char src[] = "Hello, World!";
    char* result = my_strcpy(dest, src);
    TEST_ASSERT_EQUAL_PTR(dest, result);
}

// Test copying an empty source string
void test_my_strcpy_empty_source(void) {
    char dest[20] = "Initial Value";
    const char src[] = "";
    my_strcpy(dest, src);
    TEST_ASSERT_EQUAL_STRING("", dest);
}

