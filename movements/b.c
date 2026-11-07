#include "../ft_push_swap.h"
int sb(t_stack **lst ){
    t_stack *first_ele;
    t_stack *second_ele;
    if(!lst || !*lst)
        return 0;

    first_ele=*lst;
    if(!first_ele->next || first_ele->before)
    return 0;
    second_ele=first_ele->next;
    first_ele->next=second_ele->next;
    first_ele->before=second_ele;
    second_ele->before=NULL;
    second_ele->next=first_ele;
    *lst=second_ele;
    return 1;

}
/**
 * first element of a go to first element of b
 */
int pb(t_stack **lst_a ,t_stack **lst_b ){
    t_stack *first_node_b;
    t_stack *first_node_a;

    if(!lst_a || !lst_b || !*lst_a)
        return 0;
    first_node_a= *lst_a;
    first_node_b= *lst_b;
    if(first_node_a->before)
        return 0;
    if(first_node_b)
        first_node_b->before=first_node_a;
    *lst_b=first_node_a;
    *lst_a=first_node_a->next;
    first_node_a->next=first_node_b;
    return 1;
}
/**
 * the first go to last position
 */
int rb(t_stack **lst)
{
    t_stack *last_node;
    t_stack *first_node;
    if(!lst || !*lst)
        return 0;
    first_node = *lst;
    last_node =*lst;
    while(last_node->next)
        last_node=last_node->next;
    if(last_node==first_node)
        return 0;
    last_node->next=first_node;
    *lst=first_node->next;
    (*lst)->before=NULL;
    first_node->next=NULL;
    first_node->before=last_node;
    return 1;
}
/**
 * the last element go to first position
 */
int rrb(t_stack **lst)
{
    t_stack *last_node;
    t_stack *first_node;
    if(!lst || !*lst)
        return 0;
    first_node = *lst;
    last_node =*lst;
    while(last_node->next)
        last_node=last_node->next;
    if(last_node==first_node)
        return 0;
    last_node->next=first_node;
    last_node->before->next=NULL;
    last_node->before=NULL;
    first_node->before=last_node;
    *lst=last_node;
    return 1;
}
