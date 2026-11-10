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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a=NULL;
	stack_b=NULL;
	int		operation_amount = 0;

	assert(pa(NULL, &stack_b, &operation_amount) == 0);
	assert(pa(&stack_a, NULL, &operation_amount) == 0);
	assert(stack_a == NULL);
	assert(stack_b == NULL);
	print_success("pa safely rejects null stack pointers.");
}

static void	test_empty_source_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {10, 20};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 10, 0);
	add_value(&stack_a, 20, 1);
	int		operation_amount = 0;

	assert(pa(&stack_a, &stack_b, &operation_amount) == 0);
	assert_stack(stack_a, values_a, 2);
	assert(stack_b == NULL);
	free_stack(&stack_a);
	print_success("pa leaves stack A unchanged when stack B is empty.");
}

static void	test_move_to_empty_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {7};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_b, 7, 0);
	int		operation_amount = 0;

	assert(pa(&stack_a, &stack_b, &operation_amount) == 1);
	assert_stack(stack_a, values_a, 1);
	assert(stack_b == NULL);
	free_stack(&stack_a);
	print_success("pa moves the top node from B to an empty A.");
}

static void	test_move_to_nonempty_stack(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {1, 2, 3};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 2, 0);
	add_value(&stack_a, 3, 1);
	add_value(&stack_b, 1, 0);
	int		operation_amount = 0;

	assert(pa(&stack_a, &stack_b, &operation_amount) == 1);
	assert_stack(stack_a, values_a, 3);
	assert(stack_b == NULL);
	free_stack(&stack_a);
	print_success("pa pushes B's top node onto a nonempty A.");
}

static void	test_preserve_remaining_source_nodes(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values_a[] = {1, 4, 5};
	int		values_b[] = {2, 3};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 4, 0);
	add_value(&stack_a, 5, 1);
	add_value(&stack_b, 1, 0);
	add_value(&stack_b, 2, 1);
	add_value(&stack_b, 3, 2);
	int		operation_amount = 0;

	assert(pa(&stack_a, &stack_b, &operation_amount) == 1);
	assert_stack(stack_a, values_a, 3);
	assert_stack(stack_b, values_b, 2);
	free_stack(&stack_a);
	free_stack(&stack_b);
	print_success("pa preserves the remaining nodes and links in both stacks.");
}

static void	test_source_head_with_previous_node(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*first_b;
	int		values_a[] = {10};

	stack_a=NULL;
	stack_b=NULL;
	add_value(&stack_a, 10, 0);
	add_value(&stack_b, 20, 0);
	add_value(&stack_b, 30, 1);
	first_b=stack_b;
	first_b->before=first_b;
	int		operation_amount = 0;

	assert(pa(&stack_a, &stack_b, &operation_amount) == 0);
	assert_stack(stack_a, values_a, 1);
	assert(stack_b == first_b);
	assert(first_b->value == 20);
	assert(first_b->next->value == 30);
	assert(first_b->before == first_b);
	assert(first_b->next->before == first_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	print_success("pa rejects a source stack whose head has a previous node.");
}

int	main(void)
{
	printf("Starting tests for pa...\n");
	test_null_stack_pointer();
	test_empty_source_stack();
	test_move_to_empty_stack();
	test_move_to_nonempty_stack();
	test_preserve_remaining_source_nodes();
	test_source_head_with_previous_node();
	return 0;
}