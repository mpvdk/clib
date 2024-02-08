#include <string.h>
#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strncpy.h"

// Test for basic string copy functionality
void test_my_strncpy_basic_copy(void) {
    char dest[20];
    const char src[] = "Hello, World!";
    my_strncpy(dest, src, strlen(src) + 1); // Include null terminator
    TEST_ASSERT_EQUAL_STRING(src, dest);
}

// Test for partial copy when count is less than the length of src
void test_my_strncpy_partial_copy(void) {
    char dest[20] = "Initial Value";
    const char src[] = "Hello, World!";
    my_strncpy(dest, src, 5); // Copy first 5 characters
    TEST_ASSERT_EQUAL_MEMORY("Hello", dest, 5);
}

// Test for copying with count greater than the length of src, should pad with '\0'
void test_my_strncpy_excess_count(void) {
    char dest[20];
    const char src[] = "Hello";
    my_strncpy(dest, src, 10); // Excess count
    TEST_ASSERT_EQUAL_STRING(src, dest);
    TEST_ASSERT_EQUAL(dest[5], '\0'); // Check for null padding
    TEST_ASSERT_EQUAL(dest[9], '\0'); // Last character of padding
}

// Test for copying with zero count, dest should remain unchanged
void test_my_strncpy_zero_count(void) {
    char dest[20] = "Initial";
    const char src[] = "Hello";
    my_strncpy(dest, src, 0); // Zero count
    TEST_ASSERT_EQUAL_STRING("Initial", dest);
}

// Test to verify the return value is the destination string
void test_my_strncpy_return_value(void) {
    char dest[20];
    const char src[] = "Hello, World!";
    char* result = my_strncpy(dest, src, strlen(src) + 1);
    TEST_ASSERT_EQUAL_PTR(dest, result);
}

