#include <assert.h>
#include <stdio.h>
#include "../ft_push_swap.h"

static void	print_success(const char *message)
{
	printf("\033[32mOK! %s\033[0m\n", message);
}

static void	add_values(t_stack **stack, const int *values, size_t size)
{
	size_t	index;

	index=0;
	while(index < size)
	{
		assert(add_node(stack, values[index]) >= 0);
		index++;
	}
}
static void	assert_stack(t_stack *stack, const int *values, size_t size)
{
	t_stack	*previous;
	size_t	index;

	previous=NULL;
	index=0;
	while(index < size)
	{
		assert(stack != NULL);
		assert(stack->value == values[index]);
		assert(stack->before == previous);
		if(previous)
			assert(previous->next == stack);
		previous=stack;
		stack=stack->next;
		index++;
	}
	assert(stack == NULL);
	if(previous)
		assert(previous->next == NULL);
}
void create_the_stack_with_highest_disorder(t_stack **stack,int **expected_values,size_t len)
{
	*expected_values=malloc(sizeof(int)*len);
	if(!*expected_values)
		return;
	while(len!=0)
	{
		len--;
		assert(add_node(stack,len)>=0);
		(*expected_values)[len]=(int)len;
	}
}
static void	free_stack(t_stack **stack)
{
	t_stack	*next;

	while(*stack)
	{
		next=(*stack)->next;
		free(*stack);
		*stack=next;
	}
}

static void	test_empty_stack(void)
{
	t_stack	*a;
	t_stack	*b;

	a=NULL;
	b=NULL;
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == NULL);
	assert(a == NULL);
	assert(b == NULL);
	print_success("selection_sort handles an empty stack.");
}

static void	test_single_node_stack(void)
{
	t_stack	*a;
	t_stack	*b;
	int		input[] = {42};

	a=NULL;
	b=NULL;
	add_values(&a, input, 1);
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, input, 1);
	assert(b == NULL);
	free_stack(&a);
	print_success("selection_sort preserves a single-node stack.");
}

static void	test_unsorted_stack(void)
{
	t_stack	*a;
	t_stack	*b;
	int		input[] = {3, 1, 4, 2};
	int		expected[] = {1, 2, 3, 4};

	a=NULL;
	b=NULL;
	add_values(&a, input, 4);
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, expected, 4);
	assert(b == NULL);
	free_stack(&a);
	print_success("selection_sort sorts an unsorted stack in ascending order.");
}

static void	test_already_sorted_stack(void)
{
	t_stack	*a;
	t_stack	*b;
	int		input[] = {1, 2, 3, 4};

	a=NULL;
	b=NULL;
	add_values(&a, input, 4);
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, input, 4);
	assert(b == NULL);
	free_stack(&a);
	print_success("selection_sort preserves an already sorted stack.");
}

static void	test_reverse_sorted_stack(void)
{
	t_stack	*a;
	t_stack	*b;
	int		input[] = {4, 3, 2, 1};
	int		expected[] = {1, 2, 3, 4};

	a=NULL;
	b=NULL;
	add_values(&a, input, 4);
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, expected, 4);
	assert(b == NULL);
	free_stack(&a);
	print_success("selection_sort sorts a reverse-ordered stack.");
}

static void	test_duplicates_and_negative_values(void)
{
	t_stack	*a;
	t_stack	*b;
	int		input[] = {0, -3, 2, -3, 0};
	int		expected[] = {-3, -3, 0, 0, 2};

	a=NULL;
	b=NULL;
	add_values(&a, input, 5);
	int		operation_amount = 0;

	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, expected, 5);
	assert(b == NULL);
	free_stack(&a);
	print_success("selection_sort handles duplicate and negative values.");
}
static void	test_worst_case_operations_with_100_values(void)
{
	t_stack	*a;
	t_stack	*b;
	int		*expected;
	int		operation_amount;

	a=NULL;
	b=NULL;
	expected=NULL;
	create_the_stack_with_highest_disorder(&a, &expected, 100);
	assert(expected != NULL);
	operation_amount=0;
	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, expected, 100);
	assert(b == NULL);
	free_stack(&a);
	free(expected);
	printf("Operations: %d\n", operation_amount);
	assert(operation_amount <= 2000);
	print_success("selection_sort stays within 5150 operations for 100 descending values.");
}

static void	test_worst_case_operations_with_500_values(void)
{
	t_stack	*a;
	t_stack	*b;
	int		*expected;
	int		operation_amount;

	a=NULL;
	b=NULL;
	expected=NULL;
	create_the_stack_with_highest_disorder(&a, &expected, 500);
	assert(expected != NULL);
	operation_amount=0;
	assert(selection_sort(&a, &b, &operation_amount) == a);
	assert_stack(a, expected, 500);
	assert(b == NULL);
	free_stack(&a);
	free(expected);
	printf("Operations: %d\n", operation_amount);
	assert(operation_amount <= 12000);
	print_success("selection_sort stays within 125750 operations for 500 descending values.");
}

int	main(void)
{
	printf("Starting tests for selection_sort...\n");
	test_empty_stack();
	test_single_node_stack();
	test_unsorted_stack();
	test_already_sorted_stack();
	test_reverse_sorted_stack();
	test_duplicates_and_negative_values();
	test_worst_case_operations_with_100_values();
	test_worst_case_operations_with_500_values();
	return 0;
}
