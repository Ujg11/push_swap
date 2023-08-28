#include "push_swap.h"
#include "./libft/libft.h"

void	rra(t_stack **a, int flag)
{
	t_stack *last_to_first;
	t_stack *new_last;

	if (*a == NULL || a == NULL || stack_size(*a) < 2)
		return ;
	last_to_first = find_last(*a);
	new_last = last_to_first->prev;
	(*a)->prev = last_to_first;
	last_to_first->next = *a;
	last_to_first->prev = NULL;
	new_last->next = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	t_stack *last_to_first;
	t_stack *new_last;

	if (*b == NULL || b == NULL || stack_size(*b) < 2)
		return ;
	last_to_first = find_last(*b);
	new_last = last_to_first->prev;
	(*b)->prev = last_to_first;
	last_to_first->next = *b;
	last_to_first->prev = NULL;
	new_last->next = NULL;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write (1, "rrr\n", 4);
}