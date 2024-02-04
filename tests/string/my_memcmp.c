#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memcmp.h"

// Test for comparing two identical blocks
void test_my_memcmp_identical_blocks(void) {
    const char block1[] = "Hello, World!";
    const char block2[] = "Hello, World!";
    size_t size = sizeof(block1) - 1; // Exclude null terminator

    TEST_ASSERT_EQUAL_INT(0, my_memcmp(block1, block2, size));
}

// Test for comparing two different blocks
void test_my_memcmp_different_blocks(void) {
    const char block1[] = "Hello, World!";
    const char block2[] = "Hello, Unity!";
    size_t size = sizeof(block1) - 1; // Exclude null terminator

    TEST_ASSERT_GREATER_THAN(0, my_memcmp(block1, block2, size)); // W > U
}

// Test comparing blocks that differ in just one byte
void test_my_memcmp_blocks_differ_one_byte(void) {
    const char block1[] = "Hello, World!";
    const char block2[] = "Jello, World!";
    size_t size = sizeof(block1) - 1; // Exclude null terminator

    TEST_ASSERT_LESS_THAN(0, my_memcmp(block1, block2, size)); // H < J
}

// Test with size 0
void test_my_memcmp_zero_size(void) {
    const char block1[] = "Hello, World!";
    const char block2[] = "Goodbye, World!";
    size_t size = 0; // Comparing 0 bytes

    TEST_ASSERT_EQUAL_INT(0, my_memcmp(block1, block2, size));
}
