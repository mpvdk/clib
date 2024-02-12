#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strlcat.h"

// Basic concatenation
void test_my_strlcat_basic_concatenation(void) {
    char dest[20] = "Hello, ";
    const char* append = "World!";
    size_t result = my_strlcat(dest, append, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("Hello, World!", dest);
    TEST_ASSERT_EQUAL(13, result);
}

// Buffer exactly filled
void test_my_strlcat_buffer_exactly_filled(void) {
    char dest[11] = "Hello";
    const char* append = ", World";
    size_t result = my_strlcat(dest, append, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("Hello, Wor", dest); // Last character is not appended due to null terminator
    TEST_ASSERT_EQUAL(12, result); // Total length it tried to create
}

// Test buffer overflow prevention
void test_my_strlcat_buffer_overflow(void) {
    char dest[10] = "12345";
    const char* append = "67890";
    size_t result = my_strlcat(dest, append, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("123456789", dest); // Last character cannot be appended
    TEST_ASSERT_EQUAL(10, result);
}

// Append an empty string
void test_my_strlcat_append_empty_string(void) {
    char dest[10] = "Test";
    const char* append = "";
    size_t result = my_strlcat(dest, append, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("Test", dest);
    TEST_ASSERT_EQUAL(4, result);
}

// Destination is an empty string
void test_my_strlcat_dest_empty_string(void) {
    char dest[10] = "";
    const char* append = "Test";
    size_t result = my_strlcat(dest, append, sizeof(dest));
    TEST_ASSERT_EQUAL_STRING("Test", dest);
    TEST_ASSERT_EQUAL(4, result);
}

// count is zero, should not append
void test_my_strlcat_count_zero(void) {
    char dest[10] = "Initial";
    const char* append = "Test";
    size_t result = my_strlcat(dest, append, 0);
    TEST_ASSERT_EQUAL_STRING("Initial", dest);
    TEST_ASSERT_EQUAL(4, result); // Length of "InitialTest" had there been enough space
}
