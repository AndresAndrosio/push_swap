#include "ft_push_swap.h"

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
