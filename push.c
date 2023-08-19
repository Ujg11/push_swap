#include "push_swap.h"
#include "./libft/libft.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*push_node;

	if (*b == NULL)
		return ;
	push_node = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	push_node->prev = NULL;
	if (*a == NULL)
	{
		*a = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *a;
		push_node->next->prev = push_node;
		*a = push_node;
	}
	write (1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*push_node;

	if (*a == NULL)
		return ;
	push_node = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	push_node->prev = NULL;
	if (*b == NULL)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->prev = push_node;
		*b = push_node;
	}
	write (1, "pb\n", 3);
}