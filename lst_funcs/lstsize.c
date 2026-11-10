/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:21:11 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/05 21:24:33 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	lstsize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
/**
* Create the first node or add a new node at the end of the linked list
* @param lst list that will recieve a new node
* @param value number, which will be owned by the new node
* @return -1: it wasn't complete successfully or the index where it was add.
*
*/
ssize_t add_node(t_stack **lst,int value)
{
	t_stack *last_node;
	t_stack *new_node;
	size_t index;

	if(!lst)
		return -1;
	new_node = malloc(sizeof(t_stack));
	if(!new_node)
		return -1;
	new_node->value=value;
	new_node->before=NULL;
	new_node->next=NULL;
	if(!*lst)
	{
		*lst=new_node;
		return 0;
	}
	last_node=*lst;
	index=0;
	while(last_node->next)
		(last_node=last_node->next,index++);
	new_node->before=last_node;
	last_node->next=new_node;
	return index+1;
}
