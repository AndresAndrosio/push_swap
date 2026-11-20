/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:00:00 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/10 00:00:00 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	rotate_cost(int index, int size)
{
	int	back;

	back = size - index;
	if (index <= back)
		return (index);
	return (back);
}

int	max_index(t_stack *b)
{
	int	idx;
	int	max_idx;
	int	max_val;

	idx = 0;
	max_idx = 0;
	max_val = b->value;
	while (b)
	{
		if (b->value > max_val)
		{
			max_val = b->value;
			max_idx = idx;
		}
		b = b->next;
		idx++;
	}
	return (max_idx);
}

int	smaller_index(t_stack *b, int value)
{
	int	idx;
	int	found;
	int	best_idx;
	int	best_val;

	idx = 0;
	found = 0;
	best_idx = -1;
	best_val = 0;
	while (b)
	{
		if (b->value < value && (!found || b->value > best_val))
		{
			found = 1;
			best_val = b->value;
			best_idx = idx;
		}
		b = b->next;
		idx++;
	}
	return (best_idx);
}

int	target_b_index(t_stack *b, int value)
{
	int	idx;

	if (!b)
		return (0);
	idx = smaller_index(b, value);
	if (idx != -1)
		return (idx);
	return (max_index(b));
}
