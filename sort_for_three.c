#include "push_swap.h"
#include "./libft/libft.h"

static t_stack	*find_biggest(t_stack *stk)
{
	int	big;
	t_stack	*biggest;

	if (stk == NULL)
		return (NULL);
	big = -2147483648;
	
	while (stk)
	{
		if (stk->val > big)
		{
			big = stk->val;
			biggest = stk;
		}
		stk = stk->next;
	}
	return (biggest);
}

void	sort_for_three(t_stack **a)
{
	t_stack *biggest;

	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a, 1);
	else if ((*a)->next == biggest)
		rra(a, 1);
	if ((*a)->val > (*a)->next->val)
		sa(a, 1);
}