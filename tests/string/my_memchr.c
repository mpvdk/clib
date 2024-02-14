#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memchr.h"

// Test with the character present in the string
void test_my_memchr_character_present(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_EQUAL_PTR(&str[7], my_memchr(str, 'w', sizeof(str)));
}

// Test with the character not present in the string
void test_my_memchr_character_not_present(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_NULL(my_memchr(str, 'x', sizeof(str)));
}

// Test when the character is the first in the string
void test_my_memchr_character_is_first(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_EQUAL_PTR(str, my_memchr(str, 'H', sizeof(str)));
}

// Test when the character is the last in the string
void test_my_memchr_character_is_last(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_EQUAL_PTR(&str[12], my_memchr(str, '!', sizeof(str)));
}

// Test when the character is the null terminator
void test_my_memchr_n_equal_to_string_length(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_EQUAL_PTR(&str[13], my_memchr(str, '\0', sizeof(str)));
}

// Test with n greater than the string length
// This is actually undefined if char does not occur in the 
// memory block being searched. But it's nice to make sure
// that it works if the character does occur. 
void test_my_memchr_n_greater_than_string_length(void) {
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstringop-overread"
  char str[] = "Hello, world!";
  TEST_ASSERT_EQUAL_PTR(&str[13], my_memchr(str, '\0', 15));
  #pragma GCC diagnostic pop
}

// Test with n is zero
void test_my_memchr_n_is_zero(void) {
  char str[] = "Hello, world!";
  TEST_ASSERT_NULL(my_memchr(str, 'H', 0));
}

// Test with special characters
void test_my_memchr_special_characters(void) {
  char str[] = "\n\tHello, world!\n";
  TEST_ASSERT_EQUAL_PTR(&str[0], my_memchr(str, '\n', sizeof(str)));
}

// Test with binary data
void test_my_memchr_binary_data(void) {
  unsigned char data[] = {0xFF, 0x00, 0xAA, 0xBB};
  TEST_ASSERT_EQUAL_PTR(&data[1], my_memchr(data, 0x00, sizeof(data)));
}
