#include <string.h>
#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memmove.h"

// Test for moving normal block of memory with no overlap
void test_my_memmove_non_overlap(void) {
    char source[] = "Hello, World!";
    char destination[50]; // Ensure large enough to hold source

    void *result = my_memmove(destination, source, sizeof(source)); // Include null terminator

    TEST_ASSERT_EQUAL_PTR(destination, result);
    TEST_ASSERT_EQUAL_STRING(source, destination);
}

// Test for moving zero bytes
void test_my_memmove_zero_bytes(void) {
    char source[] = "Hello, World!";
    char destination[50] = ""; // Initialize with empty string

    void *result = my_memmove(destination, source, 0);

    TEST_ASSERT_EQUAL_PTR(destination, result);
    TEST_ASSERT_EQUAL_STRING("", destination);
}

// Test for moving with overlapping regions (source starts before destination)
void test_my_memmove_overlap_src_before_dest(void) {
    char buffer[100] = "Initial Data";
    // Move "Initial Data" to a position overlapping the original
    void *result = my_memmove(buffer + 5, buffer, strlen(buffer) + 1); // Include null terminator

    TEST_ASSERT_EQUAL_PTR(buffer + 5, result);
    TEST_ASSERT_EQUAL_STRING("Initial Data", buffer + 5);
}

// Test for moving with overlapping regions (destination starts before source)
void test_my_memmove_overlap_dest_before_src(void) {
    char buffer[100] = "Initial Data";
    // Copy buffer into itself at a starting position that overlaps
    void *result = my_memmove(buffer, buffer + 8, strlen(buffer + 8)+ 1); // Include null terminator

    TEST_ASSERT_EQUAL_PTR(buffer, result);
    TEST_ASSERT_EQUAL_STRING("Data", buffer);
}
