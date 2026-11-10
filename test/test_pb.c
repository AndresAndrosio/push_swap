#include <assert.h>
#include <stdio.h>
#include "../ft_push_swap.h"

static void	print_success(const char *message)
{
	printf("\033[32mOK! %s\033[0m\n", message);
}

static void	add_value(t_stack **stack, int value, size_t index)
{
	ssize_t	added_index;

	added_index=add_node(stack, value);
	assert(added_index >= 0);
	assert((size_t)added_index == index);
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

static void	test_null_stack_pointers(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a=NULL;
	stack_b=NULL;
	int		operation_amount = 0;

	assert(pb(NULL, &stack_b, &operation_amount) == 0);
	assert(pb(&stack_a, NULL, &operation_amount) == 0);
	assert(stack_a == NULL);
	assert(stack_b == NULL);
	print_success("pb safely rejects null stack pointers.");
}

static void	test_empty_source_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_b[] = {10, 20};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_b, 10, 0);
	add_value(&stack_b, 20, 1);
	int		operation_amount = 0;

	assert(pb(&stack_a, &stack_b, &operation_amount) == 0);
	assert(stack_a == NULL);
	assert_stack(stack_b, values_b, 2);
	free_stack(&stack_b);
	print_success("pb leaves stack B unchanged when stack A is empty.");
}

static void	test_move_to_empty_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_b[] = {7};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 7, 0);
	int		operation_amount = 0;

	assert(pb(&stack_a, &stack_b, &operation_amount) == 1);
	assert(stack_a == NULL);
	assert_stack(stack_b, values_b, 1);
	free_stack(&stack_b);
	print_success("pb moves the top node from A to an empty B.");
}

static void	test_move_to_nonempty_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {3};
	int		values_b[] = {1, 2};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 1, 0);
	add_value(&stack_a, 3, 1);
	add_value(&stack_b, 2, 0);
	int		operation_amount = 0;

	assert(pb(&stack_a, &stack_b, &operation_amount) == 1);
	assert_stack(stack_a, values_a, 1);
	assert_stack(stack_b, values_b, 2);
	free_stack(&stack_a);
	free_stack(&stack_b);
	print_success("pb pushes A's top node onto a nonempty B.");
}

static void	test_preserve_remaining_source_nodes(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {2, 3};
	int		values_b[] = {1, 4, 5};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 1, 0);
	add_value(&stack_a, 2, 1);
	add_value(&stack_a, 3, 2);
	add_value(&stack_b, 4, 0);
	add_value(&stack_b, 5, 1);
	int		operation_amount = 0;

	assert(pb(&stack_a, &stack_b, &operation_amount) == 1);
	assert_stack(stack_a, values_a, 2);
	assert_stack(stack_b, values_b, 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	print_success("pb preserves the remaining nodes and links in both stacks.");
}

static void	test_source_head_with_previous_node(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*first_a;
	int		values_b[] = {20};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 10, 0);
	add_value(&stack_a, 30, 1);
	add_value(&stack_b, 20, 0);
	first_a=stack_a;
	first_a->before=first_a;
	int		operation_amount = 0;

	assert(pb(&stack_a, &stack_b, &operation_amount) == 0);
	assert(stack_a == first_a);
	assert(first_a->value == 10);
	assert(first_a->next->value == 30);
	assert(first_a->before == first_a);
	assert_stack(stack_b, values_b, 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	print_success("pb rejects a source stack whose head has a previous node.");
}

int	main(void)
{
	printf("Starting tests for pb...\n");
	test_null_stack_pointers();
	test_empty_source_stack();
	test_move_to_empty_stack();
	test_move_to_nonempty_stack();
	test_preserve_remaining_source_nodes();
	test_source_head_with_previous_node();
	return 0;
}
