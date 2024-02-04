#include <stdio.h>

#include "../src/my_string.h"
#include "unity/unity.h"
#include "string/my_memchr.h"
#include "string/my_memcmp.h"
#include "string/my_memcpy.h"
#include "string/my_memmove.h"
#include "string/my_memset.h"
#include "string/my_strcat.h"

void setUp(void) {
  // global setup stuff up here
}

void tearDown(void) {
  // global cleanup stuff up here
}

void print_header(char const * title)
{
  printf("\n");
  printf("- testing %s\n", title);
  printf("-------------------\n");
}

int main(void) {
  UNITY_BEGIN();

  /**********/
  /* string */
  /**********/

  // memchr
  print_header("my_memchr");
  RUN_TEST(test_my_memchr_character_present);
  RUN_TEST(test_my_memchr_character_not_present);
  RUN_TEST(test_my_memchr_character_is_first);
  RUN_TEST(test_my_memchr_character_is_last);
  RUN_TEST(test_my_memchr_n_equal_to_string_length);
  RUN_TEST(test_my_memchr_n_greater_than_string_length);
  RUN_TEST(test_my_memchr_n_is_zero);
  RUN_TEST(test_my_memchr_special_characters);
  RUN_TEST(test_my_memchr_binary_data);

  // memcmp
  print_header("my_memcmp");
  RUN_TEST(test_my_memcmp_identical_blocks);
  RUN_TEST(test_my_memcmp_different_blocks);
  RUN_TEST(test_my_memcmp_blocks_differ_one_byte);
  RUN_TEST(test_my_memcmp_zero_size);

  // memcpy
  print_header("my_memcpy");
  RUN_TEST(test_my_memcpy_normal);
  RUN_TEST(test_my_memcpy_zero_bytes);

  // memmove
  print_header("my_memmove");
  RUN_TEST(test_my_memmove_non_overlap);
  RUN_TEST(test_my_memmove_zero_bytes);
  RUN_TEST(test_my_memmove_overlap_src_before_dest);
  RUN_TEST(test_my_memmove_overlap_dest_before_src);

  // memset
  print_header("my_memset");
  RUN_TEST(test_my_memset_null_pointer);
  RUN_TEST(test_my_memset_zero_count);
  RUN_TEST(test_my_memset_set_bytes);
  RUN_TEST(test_my_memset_check_return_value);

  // strcat
  print_header("my_strcat");
  RUN_TEST(test_my_strcat_normal_use);
  RUN_TEST(test_my_strcat_empty_source);
  RUN_TEST(test_my_strcat_empty_destination);
  RUN_TEST(test_my_strcat_null_source);
  RUN_TEST(test_my_strcat_check_return_value);

  return UNITY_END();
}
