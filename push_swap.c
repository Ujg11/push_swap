/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:16:10 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/15 11:44:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static void	rr_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	rrr_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	put_on_top(t_stack	**stack, t_stack *top, char a_or_b)
{
	while (*stack != top)
	{
		if (a_or_b == 'a')
		{
			if (top->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (a_or_b == 'b')
		{
			if (top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

static void	movements(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = *b;
	while (cheapest->cheapest == 0)
		cheapest = cheapest->next;
	if (cheapest->above_median && cheapest->target->above_median)
		rr_stacks(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rrr_stacks(a, b, cheapest);
	put_on_top(a, cheapest->target, 'a');
	put_on_top(b, cheapest, 'b');
	pa(a, b);
}


void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_size(*a);
	while (len_a-- > 3)
		pb(b, a);
	sort_for_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		movements(a, b);
	}
	set_position(*a);
	smallest = find_small(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}

/*static int	next_move(t_stack *a)
{
	t_stack	*small;
	t_stack	*current;
	int		cont;
	int		ret;

	current = a;
	small = find_small(a);
	cont = 1;
	ret = 0;
	while (current != NULL && current->val != small->val)
	{
		current = current->next;
		cont++;
	}
	if (cont > stack_size(a) / 2)
		ret = 2;
	else if (cont <= stack_size(a) / 2)
		ret = 1;
	return (ret);
}

static void	move_up_or_down(t_stack **a, t_stack *small, int move)
{
	while (*a != small)
	{
		if (move == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

static void	turn_to_a(t_stack **a, t_stack **b)
{
	while (stack_size(*b) != 0)
		pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		mid;
	int		move;
	t_stack	*small;
	t_stack	*current;

	if (*a == NULL || a == NULL)
		return ;
	mid = stack_size(*a) / 2;
	current = *a;
	while (stack_size(*a) > 3 && !stack_is_sorted(*a))
	{
		small = find_small(*a);
		move = next_move(*a);
		ft_printf("farem el move_up_down\n");
		move_up_or_down(a, small, move);
		ft_printf("move_up_down fet\n");
		pb(b, a);
	}
	if (stack_size(*a) == 3)
		sort_for_three(a);
	turn_to_a(a, b);
}*/