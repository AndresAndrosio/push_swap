#include "ft_push_swap.h"

int clear_lst(t_stack **lst)
{
    t_stack *tmp;
    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
    *lst = NULL;
    return (1);
}