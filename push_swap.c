/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:16:10 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/08 18:12:19 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	next_move(t_stack *a)
{
	t_stack	*small;
	t_stack	*current;
	int		cont;
	int		ret;

	current = a;
	small = find_small(a);
	cont = 1;
	while (current->val != small->val && current != NULL)
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
	while (stack_size(b) != 0)
	{
		pa(a, b);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		mid;
	int 	move;
	t_stack	*small;
	t_stack	*current;

	if (*a == NULL || a == NULL)
		return ;
	mid = stack_size(*a) / 2;
	current = *a;
	while (stack_size(*a) > 3)
	{
		small = find_small(*a);
		move = next_move(*a);
		move_up_or_down(a, small, move);
		pb(b, a);
	}
	if (stack_size(a) == 3)
		sort_for_three(a);
	turn_to_a(a, b);
}