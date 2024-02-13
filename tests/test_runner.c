#include <stdio.h>

#include "../src/my_string.h"
#include "unity/unity.h"
#include "string/my_memchr.h"
#include "string/my_memcmp.h"
#include "string/my_memcpy.h"
#include "string/my_memmove.h"
#include "string/my_memset.h"
#include "string/my_strcat.h"
#include "string/my_strncat.h"
#include "string/my_strchr.h"
#include "string/my_strcmp.h"
#include "string/my_strlen.h"
#include "string/my_strncmp.h"
#include "string/my_strrchr.h"
#include "string/my_strcpy.h"
#include "string/my_strncpy.h"
#include "string/my_strspn.h"
#include "string/my_strcspn.h"
#include "string/my_strpbrk.h"
#include "string/my_strstr.h"
#include "string/my_strtok.h"
#include "string/my_memccpy.h"
#include "string/my_strdup.h"
#include "string/my_strlcat.h"
#include "string/my_strlcpy.h"
#include "string/my_strtok_r.h"

void setUp(void) {
}

void tearDown(void) {
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

  // strncat
  print_header("my_strncat");
  RUN_TEST(test_my_strncat_normal_use);
  RUN_TEST(test_my_strncat_append_less_than_count);
  RUN_TEST(test_my_strncat_append_more_than_count);
  RUN_TEST(test_my_strncat_count_zero);
  RUN_TEST(test_my_strncat_check_return_value);

  // strchr
  print_header("my_strchr");
  RUN_TEST(test_my_strchr_char_found);
  RUN_TEST(test_my_strchr_char_not_found);
  RUN_TEST(test_my_strchr_search_for_null_terminator);
  RUN_TEST(test_my_strchr_empty_string);

  // strrchr
  print_header("my_strrchr");
  RUN_TEST(test_my_strrchr_char_found);
  RUN_TEST(test_my_strrchr_char_not_found);
  RUN_TEST(test_my_strrchr_search_for_null_terminator);
  RUN_TEST(test_my_strrchr_empty_string);
  RUN_TEST(test_my_strrchr_char_appears_once);

  // strcmp
  print_header("my_strcmp");
  RUN_TEST(test_my_strcmp_equal_strings);
  RUN_TEST(test_my_strcmp_first_string_greater);
  RUN_TEST(test_my_strcmp_second_string_greater);
  RUN_TEST(test_my_strcmp_empty_first_string);
  RUN_TEST(test_my_strcmp_empty_second_string);
  RUN_TEST(test_my_strcmp_both_empty_strings);

  // strncmp
  print_header("my_strncmp");
  RUN_TEST(test_my_strncmp_equal_strings);
  RUN_TEST(test_my_strncmp_first_string_greater);
  RUN_TEST(test_my_strncmp_second_string_greater);
  RUN_TEST(test_my_strncmp_compare_zero_characters);
  RUN_TEST(test_my_strncmp_compare_partial);
  RUN_TEST(test_my_strncmp_length_greater_than_strings);

  // strcpy
  print_header("my_strcpy");
  RUN_TEST(test_my_strcpy_basic_copy);
  RUN_TEST(test_my_strcpy_return_value);
  RUN_TEST(test_my_strcpy_empty_source);

  // strncpy
  print_header("my_strncpy");
  RUN_TEST(test_my_strncpy_basic_copy);
  RUN_TEST(test_my_strncpy_partial_copy);
  RUN_TEST(test_my_strncpy_excess_count);
  RUN_TEST(test_my_strncpy_zero_count);
  RUN_TEST(test_my_strncpy_return_value);

  // strlen
  print_header("my_strlen");
  RUN_TEST(test_my_strlen_empty_string);
  RUN_TEST(test_my_strlen_basic_string);
  RUN_TEST(test_my_strlen_string_with_spaces); 

  // strspn
  print_header("my_strspn");
  RUN_TEST(test_my_strspn_all_chars_found);
  RUN_TEST(test_my_strspn_no_chars_found);
  RUN_TEST(test_my_strspn_some_chars_found);
  RUN_TEST(test_my_strspn_empty_lhs);
  RUN_TEST(test_my_strspn_empty_rhs);

  // strcspn
  print_header("my_strcspn");
  RUN_TEST(test_my_strcspn_empty_string);
  RUN_TEST(test_my_strcspn_no_match);
  RUN_TEST(test_my_strcspn_all_chars_match);
  RUN_TEST(test_my_strcspn_first_char_match);
  RUN_TEST(test_my_strcspn_normal_operation);
  RUN_TEST(test_my_strcspn_normal_operation_two);

  // strpbrk
  print_header("my_strpbrk");
  RUN_TEST(test_my_strpbrk_empty_string);
  RUN_TEST(test_my_strpbrk_no_match);
  RUN_TEST(test_my_strpbrk_first_char_match);
  RUN_TEST(test_my_strpbrk_normal_operation);
  RUN_TEST(test_my_strpbrk_match_at_end);

  // strstr
  print_header("my_strstr");
  RUN_TEST(test_find_substring_at_start);
  RUN_TEST(test_find_substring_in_middle);
  RUN_TEST(test_find_substring_at_end);
  RUN_TEST(test_substring_not_found);
  RUN_TEST(test_empty_substring);
  RUN_TEST(test_null_haystack_returns_null);
  RUN_TEST(test_null_needle_returns_haystack);

  // strtok
  print_header("my_strtok");
  RUN_TEST(test_single_char_delim);
  RUN_TEST(test_multi_char_delim);
  RUN_TEST(test_no_delim_in_str);
  RUN_TEST(test_empty_str);
  RUN_TEST(test_null_str_on_subsequent_calls);
  RUN_TEST(test_delim_at_start_and_end);    
  RUN_TEST(test_consecutive_delimiters);
  RUN_TEST(test_only_delimiters);
  RUN_TEST(test_delimiter_at_end);

  // memccpy
  print_header("my_memccpy");
  RUN_TEST(test_copy_without_specified_character);
  RUN_TEST(test_copy_with_specified_character_early);
  RUN_TEST(test_copy_exact_count_bytes);
  RUN_TEST(test_copy_with_specified_character_at_last);
  RUN_TEST(test_return_value_with_found_character);
  RUN_TEST(test_return_value_with_not_found_character);

  // strdup
  print_header("my_strdup");
  RUN_TEST(test_my_strdup_null_ptr);
  RUN_TEST(test_my_strdup_empty_string);
  RUN_TEST(test_my_strdup_basic_string);
  RUN_TEST(test_my_strdup_long_string);

  // strlcat
  print_header("my_strlcat");
  RUN_TEST(test_my_strlcat_basic_concatenation);
  RUN_TEST(test_my_strlcat_buffer_exactly_filled);
  RUN_TEST(test_my_strlcat_buffer_overflow);
  RUN_TEST(test_my_strlcat_append_empty_string);
  RUN_TEST(test_my_strlcat_dest_empty_string);
  RUN_TEST(test_my_strlcat_count_zero);

  // strlcpy
  print_header("my_strlcpy");
  RUN_TEST(test_my_strlcpy_null_terminated_result);
  RUN_TEST(test_my_strlcpy_exact_buffer_size);
  RUN_TEST(test_my_strlcpy_buffer_too_small);
  RUN_TEST(test_my_strlcpy_empty_source);
  RUN_TEST(test_my_strlcpy_empty_dest);
  RUN_TEST(test_my_strlcpy_large_source);

  // strtok_r
  print_header("my_strtok_r");
  RUN_TEST(test_my_strtok_r_single_token);
  RUN_TEST(test_my_strtok_r_multiple_tokens);
  RUN_TEST(test_my_strtok_r_no_tokens);
  RUN_TEST(test_my_strtok_r_delimiters_at_start_and_end);
  RUN_TEST(test_my_strtok_r_continuous_delimiters);
  RUN_TEST(test_my_strtok_r_null_str_on_subsequent_calls);

  return UNITY_END();
}
