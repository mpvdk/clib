#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memcpy.h"

// Test for copying normal block of memory
void test_my_memcpy_normal(void) {
  char source[] = "Hello, World!";
  char destination[50]; // Ensure large enough to hold source

  void *result = my_memcpy(destination, source, sizeof(source)); // Include null terminator

  TEST_ASSERT_EQUAL_PTR(destination, result);
  TEST_ASSERT_EQUAL_STRING(source, destination);
}

// Test for copying zero bytes
void test_my_memcpy_zero_bytes(void) {
  char source[] = "Hello, World!";
  char destination[50] = ""; // Initialize with empty string

  void *result = my_memcpy(destination, source, 0);

  TEST_ASSERT_EQUAL_PTR(destination, result);
  TEST_ASSERT_EQUAL_STRING("", destination);
}
