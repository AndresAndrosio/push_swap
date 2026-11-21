
#include <assert.h>
#include <stdio.h>
#include "../ft_push_swap.h"

static void	print_success(const char *message)
{
	printf("\033[32mOK! %s\033[0m\n", message);
}

static void	assert_check_arg(int argc, char *argv[], int expected)
{
	assert(check_arg(argc, argv) == expected);
}

/* Valid arguments */

static void	test_positive_numbers(void)
{
	char *argv[] = {"push_swap", "+1213 +12345 +12346", NULL};

	assert_check_arg(2, argv, 1);
	print_success("check_arg accepts positive numbers with signs.");
}

static void	test_negative_numbers(void)
{
	char *argv[] = {"push_swap", "-1213 -12345 -12346", NULL};

	assert_check_arg(2, argv, 1);
	print_success("check_arg accepts negative numbers.");
}

static void	test_numbers_without_sign(void)
{
	char *argv[] = {"push_swap", "1213 12345 12346", NULL};

	assert_check_arg(2, argv, 1);
	print_success("check_arg accepts positive numbers without signs.");
}

static void	test_numbers_with_spaces(void)
{
	char *argv[] = {"push_swap", "1213         12345 12346", "     1", NULL};

	assert_check_arg(3, argv, 1);
	print_success("check_arg accepts positive numbers without signs and with spaces.");
}

/* Invalid number formats */

static void	test_consecutive_opposite_signs(void)
{
	char *argv[] = {"push_swap", "-+1213 12345 12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects consecutive opposite signs.");
}

static void	test_multiple_signs_before_number(void)
{
	char *argv[] = {"push_swap", "1213 +++12345 --12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects multiple consecutive signs.");
}

static void	test_double_negative_sign(void)
{
	char *argv[] = {"push_swap", "1213 --12345 12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects double negative signs.");
}

static void	test_signs_without_spaces(void)
{
	char *argv[] = {"push_swap", "+1213---12345 12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects consecutive signs without spaces.");
}

static void	test_numbers_without_separators(void)
{
	char *argv[] = {"push_swap", "+1213-12345-12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects numbers without separators.");
}

static void	test_plus_without_separators(void)
{
	char *argv[] = {"push_swap", "+1213+12345+12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects plus signs without separators.");
}

static void	test_multiple_signs_without_separators(void)
{
	char *argv[] = {"push_swap", "+1213+++12345+++12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects multiple signs without separators.");
}

static void	test_mixed_signs_without_separators(void)
{
	char *argv[] = {"push_swap", "+1213+-+12345+-+12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects mixed consecutive signs.");
}

static void	test_signs_separated_by_spaces(void)
{
	char *argv[] = {"push_swap", "+1213+ +12345+ +12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects signs separated from their numbers.");
}

static void	test_negative_signs_separated_by_spaces(void)
{
	char *argv[] = {"push_swap", "1213- -12345- -12346", NULL};

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects negative signs separated by spaces.");
}

/* Empty arguments */

static void	test_empty_argument_with_valid_arguments(void)
{
	char *argv[] = {
		"push_swap",
		"  ",
		"12343",
		"21223 +4325",
		NULL
	};

	assert_check_arg(4, argv, 1);
	print_success("check_arg accepts valid arguments even with an empty argument present.");
}

static void	test_only_empty_arguments(void)
{
	char *argv[] = {"push_swap", "  ", "", "    ", NULL};

	assert_check_arg(4, argv, 0);
	print_success("check_arg rejects arguments containing only spaces.");
}

static void	test_duplicate_numbers_with_empty_argument(void)
{
	char *argv[] = {"push_swap", "1 1", "    ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg rejects duplicate numbers and empty arguments.");
}

static void	test_duplicate_numbers_with_empty_argument_again(void)
{
	char *argv[] = {"push_swap", "1 1", "    ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg rejects duplicate numbers in different arguments.");
}

static void	test_duplicate_numbers_with_spaces(void)
{
	char *argv[] = {"push_swap", "1", "  1  ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg rejects duplicate numbers across arguments.");
}

static void	test_duplicate_positive_numbers_with_spaces(void)
{
	char *argv[] = {"push_swap", "+1", "  1  ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg detects duplicates regardless of positive signs.");
}

static void	test_duplicate_negative_numbers_with_spaces(void)
{
	char *argv[] = {"push_swap", "-1", "  -1  ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg detects duplicates regardless of negative signs.");
}

static void	test_duplicate_numbers_in_different_arguments(void)
{
	char *argv[] = {"push_swap", "-1123 -1123", "  -1  ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg rejects duplicate numbers inside an argument.");
}

static void	test_duplicate_large_numbers_with_spaces(void)
{
	char *argv[] = {"push_swap", "12345", "  12345  ", NULL};

	assert_check_arg(3, argv, 0);
	print_success("check_arg rejects duplicate numbers across arguments.");
}

/* Empty arguments */

static void	test_all_arguments_contain_spaces(void)
{
	char *argv[] = {"push_swap", "  ", "  ", "    ", NULL};

	assert_check_arg(4, argv, 0);
	print_success("check_arg rejects multiple arguments containing spaces.");
}

static void	test_all_arguments_are_empty(void)
{
	char *argv[] = {"push_swap", "", "", "", NULL};

	assert_check_arg(4, argv, 0);
	print_success("check_arg rejects multiple empty arguments.");
}

static void	test_all_arguments_contain_only_spaces(void)
{
	char *argv[] = {"push_swap", "   ", "   ", "   ", NULL};

	assert_check_arg(4, argv, 0);
	print_success("check_arg rejects arguments containing only whitespace.");
}
#include <limits.h>

/* Integer limits */

static void	test_int_max(void)
{
	char argv[3][32];
	char *args[] = {"push_swap", argv[1], NULL};

	snprintf(argv[1], sizeof(argv[1]), "%d", INT_MAX);

	assert_check_arg(2, args, 1);
	print_success("check_arg accepts INT_MAX.");
}

static void	test_int_min(void)
{
	char argv[3][32];
	char *args[] = {"push_swap", argv[1], NULL};

	snprintf(argv[1], sizeof(argv[1]), "%d", INT_MIN);

	assert_check_arg(2, args, 1);
	print_success("check_arg accepts INT_MIN.");
}

static void	test_overflow_int_max(void)
{
	char number[32];
	char *argv[] = {"push_swap", number, NULL};

	snprintf(number, sizeof(number), "%lld", (long long)INT_MAX + 1);

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects INT_MAX + 1.");
}

static void	test_underflow_int_min(void)
{
	char number[32];
	char *argv[] = {"push_swap", number, NULL};

	snprintf(number, sizeof(number), "%lld", (long long)INT_MIN - 1);

	assert_check_arg(2, argv, 0);
	print_success("check_arg rejects INT_MIN - 1.");
}
int	main(void)
{
	printf("Starting integration tests for check_arg...\n\n");

	test_positive_numbers();
	test_negative_numbers();
	test_numbers_without_sign();
	test_numbers_with_spaces();

	test_consecutive_opposite_signs();
	test_multiple_signs_before_number();
	test_double_negative_sign();
	test_signs_without_spaces();
	test_numbers_without_separators();
	test_plus_without_separators();
	test_multiple_signs_without_separators();
	test_mixed_signs_without_separators();
	test_signs_separated_by_spaces();
	test_negative_signs_separated_by_spaces();
    
	test_empty_argument_with_valid_arguments();
	test_only_empty_arguments();
	test_duplicate_numbers_with_empty_argument();
	test_duplicate_numbers_with_empty_argument_again();
	test_duplicate_numbers_with_spaces();
	test_duplicate_positive_numbers_with_spaces();
	test_duplicate_negative_numbers_with_spaces();
	test_duplicate_numbers_in_different_arguments();
	test_duplicate_large_numbers_with_spaces();

	test_all_arguments_contain_spaces();
	test_all_arguments_are_empty();
	test_all_arguments_contain_only_spaces();

	test_int_max();
	test_int_min();
	test_overflow_int_max();
	test_underflow_int_min();
	printf("\nAll check_arg tests passed!\n");
	return 0;
}
