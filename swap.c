/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:11:24 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/20 18:16:32 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	swap(t_stack **a)
{
	t_stack *aux;

	aux = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = aux;
	return (1);
}

void	sa(t_stack **a, int flag)
{
	int	aux;

	if (*a == NULL || a == NULL)
		return ;
	if (stack_size(*a) < 2)
		return ;
	aux = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = aux;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int	aux;

	if (*b == NULL || b == NULL)
		return ;
	if (stack_size(*b) < 2)
		return ;
	aux = (*b)->val;
	(*b)->val = (*b)->next->val;
	(*b)->next->val = aux;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}