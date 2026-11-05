/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:28 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/05 21:32:28 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*next;

	if (stack == NULL)
		return (NULL);
	min = stack;
	next = stack->next;
	while (next != NULL)
	{
		if (min->value > next->value)
			min = next;
		next = next->next;
	}
	return (min);
}

t_stack	*selection_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		i;
	int		total_size;

	i = 0;
	total_size = lstsize(*a);
	while (i < total_size)
	{
		min = find_min(*a);
		while (*a != min)
			rotate_a(a);
		pb(a, b);
		i++;
	}
	while (*b != NULL)
		pa(a, b);
	return (*a);
}
