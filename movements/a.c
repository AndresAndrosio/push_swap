#include "../ft_push_swap.h" 
int sa(t_stack *first_ele ){
    t_stack *second_ele;
    if(!first_ele->next || first_ele->before)
        return 0;
    int temp_val;    
    temp_val=first_ele->value;
    second_ele->value=temp_val;
    return 1;

}

int pa(t_stack **lst_a ,t_stack **lst_b ){
    t_stack *first_node_b = *lst_b;
    t_stack *first_node_a = *lst_a;
    
    if(!lst_a || !lst_b || !*lst_b)
        return 0;
    first_node_a= *lst_a;
    first_node_b= *lst_b;
    if((first_node_b)->before)
        return 0;
    if(first_node_a)
        first_node_a->before=first_node_b;
    first_node_b->next=first_node_a;
    lst_a=first_node_b;
    if(first_node_b->next)
        lst_b=first_node_b->next;
    else
        lst_b=NULL;
    return 1;
}
int ra(t_stack **lst_a)
{
    t_stack *node;
    t_stack *last_node;
    node =*lst_a; 
    while(node->next)
        last_node=node->next;
    last_node->before;
}