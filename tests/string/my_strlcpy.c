#include <string.h>
#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strlcpy.h"

// Test copying into a buffer that perfectly fits the string plus null terminator
void test_my_strlcpy_null_terminated_result() {
    char dest[11];
    const char* src = "hello world";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("hello worl", dest);
    TEST_ASSERT_EQUAL(11, result);
}

// Test when the buffer size exactly matches the source length including null terminator
void test_my_strlcpy_exact_buffer_size() {
    char dest[12];
    const char* src = "hello world";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING(src, dest);
    TEST_ASSERT_EQUAL(11, result);
}

// Test with a buffer too small to hold the source string
void test_my_strlcpy_buffer_too_small() {
    char dest[5];
    const char* src = "hello world";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("hell", dest);
    TEST_ASSERT_EQUAL(11, result);
}

// Test copying an empty string into the destination buffer
void test_my_strlcpy_empty_source() {
    char dest[11];
    const char* src = "";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("", dest);
    TEST_ASSERT_EQUAL(0, result);
}

// Test destination buffer initially empty
void test_my_strlcpy_empty_dest() {
    char dest[1] = {0}; // Just to symbolize an empty dest but with space for null terminator
    const char* src = "hello world";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("", dest);
    TEST_ASSERT_EQUAL(11, result);
}

// Test with a large source string relative to the destination buffer size
void test_my_strlcpy_large_source() {
    char dest[20]; // Smaller than the source string
    const char* src = "a very long string much longer than the destination";
    size_t result = my_strlcpy(dest, src, sizeof(dest));
    TEST_ASSERT_EQUAL(strlen(src), result);
    TEST_ASSERT_EQUAL_CHAR('\0', dest[sizeof(dest) - 1]);
    TEST_ASSERT_EQUAL_MEMORY(src, dest, sizeof(dest) - 1);
}

