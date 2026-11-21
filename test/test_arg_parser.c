
#include "../ft_push_swap.h"
#include <stdio.h>

static void	print_success(const char *message)
{
	printf("\033[32mOK! %s\033[0m\n", message);
}

static void	print_error(const char *message)
{
	printf("\033[31mERROR! %s\033[0m", message);
}

static void assert_check_arg(int argc, char *argv[], int expected[], size_t len)
{
	size_t i = 0;
	t_stack *nodes= NULL;
	t_stack *init_nodes = NULL;

	parser(argc, argv, &nodes);
    init_nodes = nodes;
	while (i < len)
	{
        if (nodes == NULL)
        {
            print_error("parser did not return all expected values.\n");
            clear_lst(&init_nodes);
            abort();
        }
		if ( nodes->value != expected[i])
		{
			print_error("parser did not return all expected values.\n");
			print_error(ft_itoa(nodes->value));
			print_error("!=");
			print_error(ft_itoa(expected[i]));
			clear_lst(&init_nodes);
			abort();
		}
        nodes = nodes->next;
		i++;
		if (nodes == NULL && i != len)
		{
			print_error("parser did not return all expected values.\n");
			clear_lst(&init_nodes);
			abort();
		}
	}
    if (nodes != NULL)
    {
        print_error("parser returned more values than expected.\n");
        print_error("Extra value: ");
        print_error(ft_itoa(nodes->value));
        print_error("\n");
        clear_lst(&init_nodes);
        abort();
    }
	clear_lst(&init_nodes);
}

/* Parser tests */

static void	test_multiple_arguments(void)
{
	char *argv[] = {
		"push_swap",
		"+1 -2 -3 +4",
		"         -6 -7 +8 -11      -20",
		NULL
	};
	int expected[] = {1, -2, -3, 4, -6, -7, 8, -11, -20};

	assert_check_arg(3, argv, expected, 9);
	print_success("parser handles multiple arguments.");
}

static void	test_leading_and_trailing_spaces(void)
{
	char *argv[] = {
		"push_swap",
		"      +1 -2 -3   +4       ",
		"         -6 -7 +8 -10      -11      ",
		NULL
	};
	int expected[] = {1, -2, -3, 4, -6, -7, 8, -10, -11};

	assert_check_arg(3, argv, expected, 9);
	print_success("parser handles leading and trailing spaces.");
}

static void	test_argument_with_only_spaces(void)
{
	char *argv[] = {
		"push_swap",
		"      +1 -2 -3   +4       ",
		"     ",
		"         -6 -7 +8 -10      -11      ",
		NULL
	};
	int expected[] = {1, -2, -3, 4, -6, -7, 8, -10, -11};

	assert_check_arg(4, argv, expected, 9);
	print_success("parser ignores arguments containing only spaces.");
}

static void	test_empty_argument(void)
{
	char *argv[] = {
		"push_swap",
		"      +1 -2 -3   +4       ",
		"",
		"         -6 -7 +8 -10      -11      ",
		NULL
	};
	int expected[] = {1, -2, -3, 4, -6, -7, 8, -10, -11};

	assert_check_arg(4, argv, expected, 9);
	print_success("parser ignores empty arguments.");
}

static void	test_numbers_without_positive_sign(void)
{
	char *argv[] = {
		"push_swap",
		"1 -2 -3   +4       ",
		"",
		"         -6 -7 +8 -10      -11      ",
		NULL
	};
	int expected[] = {1, -2, -3, 4, -6, -7, 8, -10, -11};

	assert_check_arg(4, argv, expected, 9);
	print_success("parser handles numbers without explicit positive signs.");
}

static void	test_negative_numbers(void)
{
	char *argv[] = {
		"push_swap",
		"-1 -2 -3   +4       ",
		"",
		"         -6 -7 +8 -10      -11      ",
		NULL
	};
	int expected[] = {-1, -2, -3, 4, -6, -7, 8, -10, -11};

	assert_check_arg(4, argv, expected, 9);
	print_success("parser handles negative numbers.");
}

int	main(void)
{
	printf("Starting parser tests...\n\n");

	test_multiple_arguments();
	test_leading_and_trailing_spaces();
	test_argument_with_only_spaces();
	test_empty_argument();
	test_numbers_without_positive_sign();
	test_negative_numbers();

	printf("\nAll parser tests passed!\n");
	return (0);
}
