#include <string.h>
#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memccpy.h"

// Test copying without encountering the specified character
void test_copy_without_specified_character(void) {
    char src[] = "Hello, world!";
    char dest[20];
    my_memccpy(dest, src, 'x', 13); // 'x' not in src
    TEST_ASSERT_EQUAL_STRING("Hello, world!", dest);
}

// Test copying with encountering the specified character early
void test_copy_with_specified_character_early(void) {
    char src[] = "Hello, world!";
    char dest[20];
    my_memccpy(dest, src, ',', 13);
    TEST_ASSERT_EQUAL_MEMORY("Hello,", dest, 5); // Includes ',' and stops
}

// Test copying exactly `count` bytes without finding the specified character
void test_copy_exact_count_bytes(void) {
    char src[] = "Hello, world!";
    char dest[20];
    my_memccpy(dest, src, 'x', 5); // 'x' not in the first 5 chars of src
    TEST_ASSERT_EQUAL_MEMORY("Hello", dest, 5);
}

// Test copying with the specified character at the last position
void test_copy_with_specified_character_at_last(void) {
    char src[] = "Hello, world!";
    char dest[20];
    my_memccpy(dest, src, '!', 13); // '!' is at the end
    TEST_ASSERT_EQUAL_MEMORY("Hello, world!", dest, 13);
}

// Test return value when the specified character is found
void test_return_value_with_found_character(void) {
    char src[] = "Find the char!";
    char dest[20];
    char *result = my_memccpy(dest, src, 't', strlen(src));
    // Expect result to point to 'h' in dest, which is right after the first 't'
    TEST_ASSERT_EQUAL_PTR(&dest[5], result);
}

// Test return value when the specified character is not found
void test_return_value_with_not_found_character(void) {
    char src[] = "No such char";
    char dest[20];
    char *result = my_memccpy(dest, src, 'x', strlen(src));
    // Expect result to be NULL since 'x' is not found
    TEST_ASSERT_NULL(result);
}
