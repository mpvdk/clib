#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strdup.h"
#include <stdlib.h>

// Test my_strdup with a NULL pointer
void test_my_strdup_null_ptr(void) {
    char* result = my_strdup(NULL);
    TEST_ASSERT_NULL(result);
}

// Test my_strdup with an empty string
void test_my_strdup_empty_string(void) {
    char* result = my_strdup("");
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("", result);
    free(result);
}

// Test my_strdup with a basic string
void test_my_strdup_basic_string(void) {
    char* original = "Hello, World!";
    char* result = my_strdup(original);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(original, result);
    free(result);
}

// Test my_strdup with a longer string
void test_my_strdup_long_string(void) {
    char* original = "This is a longer string that contains more characters.";
    char* result = my_strdup(original);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(original, result);
    free(result);
}

