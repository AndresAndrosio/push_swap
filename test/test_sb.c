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

static void	test_null_stack_pointer(void)
{
	assert(sb(NULL) == 0);
	print_success("sb safely rejects a null stack pointer.");
}

static void	test_empty_stack(void)
{
	t_stack	*stack;

	stack=NULL;
	assert(sb(&stack) == 0);
	assert(stack == NULL);
	print_success("sb leaves an empty stack unchanged.");
}

static void	test_single_node_stack(void)
{
	t_stack	*stack;
	int		values[] = {42};

	stack=NULL;
	add_value(&stack, 42, 0);
	assert(sb(&stack) == 0);
	assert_stack(stack, values, 1);
	free_stack(&stack);
	print_success("sb leaves a single-node stack unchanged.");
}

static void	test_two_node_stack(void)
{
	t_stack	*stack;
	int		values[] = {20, 10};

	stack=NULL;
	add_value(&stack, 10, 0);
	add_value(&stack, 20, 1);
	assert(sb(&stack) == 1);
	assert_stack(stack, values, 2);
	free_stack(&stack);
	print_success("sb swaps the first two nodes in a two-node stack.");
}

static void	test_multi_node_stack(void)
{
	t_stack	*stack;
	int		values[] = {20, 10, 30, 40};

	stack=NULL;
	add_value(&stack, 10, 0);
	add_value(&stack, 20, 1);
	add_value(&stack, 30, 2);
	add_value(&stack, 40, 3);
	assert(sb(&stack) == 1);
	assert_stack(stack, values, 4);
	free_stack(&stack);
	print_success("sb swaps the first two nodes and preserves the remaining links.");
}

static void	test_head_with_previous_node(void)
{
	t_stack	*stack;
	t_stack	*first;

	stack=NULL;
	add_value(&stack, 10, 0);
	add_value(&stack, 20, 1);
	first=stack;
	first->before=first;
	assert(sb(&stack) == 0);
	assert(stack == first);
	assert(first->value == 10);
	assert(first->next->value == 20);
	assert(first->next->next == NULL);
	assert(first->before == first);
	free_stack(&stack);
	print_success("sb rejects a stack whose head has a previous node.");
}

int	main(void)
{
	printf("Starting tests for sb...\n");
	test_null_stack_pointer();
	test_empty_stack();
	test_single_node_stack();
	test_two_node_stack();
	test_multi_node_stack();
	test_head_with_previous_node();
	return 0;
}
