#include "../unity/unity.h"
#include "../../src/my_string.h"
#include "my_memset.h"

// Test for setting to null pointer
void test_my_memset_null_pointer(void)
{
  TEST_ASSERT_NULL(my_memset(NULL, 'a', 5));
}

// Test for setting with zero count
void test_my_memset_zero_count(void)
{
  char buffer[10] = "123456789";
  my_memset(buffer, 'a', 0);
  TEST_ASSERT_EQUAL_STRING("123456789", buffer);
}

// Test for normal use, checking value
void test_my_memset_set_bytes(void)
{
  char buffer[10];
  my_memset(buffer, 'A', 9); // Intentionally not setting the last byte to '\0'
  buffer[9] = '\0'; // Manually null-terminating for comparison
  TEST_ASSERT_EQUAL_STRING("AAAAAAAAA", buffer);
}

// Test for normal use, checking equality argument and return pointer
void test_my_memset_check_return_value(void)
{
  char buffer[10];
  TEST_ASSERT_EQUAL_PTR(buffer, my_memset(buffer, 'A', 9));
}
