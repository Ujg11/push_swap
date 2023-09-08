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

static int	choose_pivot(t_stack *a)
{
	int		pivot;
	t_stack	*aux;

	pivot = 0;
	aux = a;
	while (pivot < stack_size(a) / 2)
	{
		aux = aux->next;
		pivot++;
	}
	pivot = (a->val * aux->val * find_last(a)->val) / 3;
	return (pivot);
}

static void	divide_in_two(t_stack **a, t_stack **b, int pivot)
{
	t_stack	*iterator;

	iterator = *a;
	while (iterator->next)
	{
		if (iterator->val < pivot)
			pb(b, a);
		else
			iterator = iterator->next;
	}
}

static void	sort_in_ascendent(t_stack	**a)
{
	while (!stack_is_sorted(a))
	{
		if ((*a)->val )
	}
}

static void	sort_in_descendent(t_stack **b)
{
	while (!stack_is_sorted(b))
	{
		
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = choose_pivot(*a);
	divide_in_two(a, b, pivot);
	sort_in_ascendent(a);
	sort_in_descendent(b);
	while ((*b)->next)
		pa(a, b);
}