#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_strtok_r.h"

// Test parsing a string with a single token
void test_my_strtok_r_single_token(void) {
    char input[] = "token";
    char* token;
    char* saveptr;
    token = my_strtok_r(input, " ", &saveptr);
    TEST_ASSERT_EQUAL_STRING("token", token);
}

// Test parsing a string with multiple tokens
void test_my_strtok_r_multiple_tokens(void) {
    char input[] = "token1 token2 token3";
    char* saveptr;
    TEST_ASSERT_EQUAL_STRING("token1", my_strtok_r(input, " ", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token2", my_strtok_r(NULL, " ", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token3", my_strtok_r(NULL, " ", &saveptr));
}

// Test parsing a string with no tokens
void test_my_strtok_r_no_tokens(void) {
    char input[] = "      ";
    char* saveptr;
    TEST_ASSERT_NULL(my_strtok_r(input, " ", &saveptr));
}

// Test delimiters at the start and end of the string
void test_my_strtok_r_delimiters_at_start_and_end(void) {
    char input[] = "  token1 token2 token3  ";
    char* saveptr;
    TEST_ASSERT_EQUAL_STRING("token1", my_strtok_r(input, " ", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token2", my_strtok_r(NULL, " ", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token3", my_strtok_r(NULL, " ", &saveptr));
}

// Test a string with continuous delimiters
void test_my_strtok_r_continuous_delimiters(void) {
    char input[] = "token1,,token2,,token3";
    char* saveptr;
    TEST_ASSERT_EQUAL_STRING("token1", my_strtok_r(input, ",", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token2", my_strtok_r(NULL, ",", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token3", my_strtok_r(NULL, ",", &saveptr));
    TEST_ASSERT_NULL(my_strtok_r(NULL, ",", &saveptr));
}

// Test NULL str on subsequent calls
void test_my_strtok_r_null_str_on_subsequent_calls(void) {
    char input[] = "token1 token2";
    char* saveptr;
    TEST_ASSERT_EQUAL_STRING("token1", my_strtok_r(input, " ", &saveptr));
    TEST_ASSERT_EQUAL_STRING("token2", my_strtok_r(NULL, " ", &saveptr));
    TEST_ASSERT_NULL(my_strtok_r(NULL, " ", &saveptr)); // No more tokens
}
