#include "push_swap.h"
#include "./libft/libft.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*first_to_last;

	if (*a == NULL || a == NULL || stack_size(*a) < 2)
		return ;
	first_to_last = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	while (*a)
		*a = (*a)->next;
	(*a)->next = first_to_last;
	first_to_last->prev = *a;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*first_to_last;

	if (*b == NULL || b == NULL || stack_size(*b) < 2)
		return ;
	first_to_last = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	while (*b)
		*b = (*b)->next;
	(*b)->next = first_to_last;
	first_to_last->prev = *b;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}