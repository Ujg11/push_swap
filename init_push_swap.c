#include "push_swap.h"
#include "./libft/libft.h"

void	set_position(t_stack *s)
{
	int	i;
	int	midle;

	i = 0;
	if (s == NULL)
		return ;
	midle = stack_size(s) / 2;
	while (s)
	{
		s->pos = i;
		if (i <= midle)
			s->above_median = true;
		else
			s->above_median = false;
		s->cheapest = false;
		s = s->next;
		i++;
	}
}

//best biger node
static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack *target;
	int		best_match_val;

	while (b)
	{
		best_match_val = 2147483647;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val && current_a->val < best_match_val)
			{
				best_match_val = current_a->val;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_val == 2147483647)
			b->target = find_small(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->price = b->pos;
		if (!(b->above_median))
			b->price = stack_size(b) - b->pos;
		if (b->target->above_median)
			b->price += b->target->pos;
		else
			b->price += stack_size(a) - b->target->pos;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long		best;
	t_stack	*best_mach_node;

	if (b == NULL)
		return ;
	best = 2147483648;
	while (b)
	{
		if (b->price < best)
		{
			best = b->price;
			best_mach_node = b;
		}
		b->next;
	}
	best_mach_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}