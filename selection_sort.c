/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:28 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/05 21:10:38 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	selection_sort(t_list a, t_list b)
{
	t_list	*min;
	int		i;
	int		total_size;

	i = 0;
	total_size = ft_lstsize(&a);
	while (i < total_size)
	{
		min = find_min(&a);
		while (min != &a)
			rotate_a();
		pb(a);
		i++;
	}
	i = 0;
	while (i < total_size)
	{
		pa(b);
		i++;
	}
	return (a);
}

t_list	*find_min(t_list *lst)
{
	t_list	*min;
	t_list	*next;

	if (lst == NULL)
		return (NULL);
	min = lst;
	next = lst->next;
	while (next != NULL)
	{
		if (min->value > next->value)
			min = next;
		next = next->next;
	}
	return (min);
}
