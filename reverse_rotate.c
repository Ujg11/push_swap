/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:33:29 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/08 14:19:07 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*last_to_first;

	if (*a == NULL || a == NULL || stack_size(*a) < 2)
		return ;
	last_to_first = find_last(*a);
	last_to_first->prev->next = NULL;
	last_to_first->next = *a;
	last_to_first->prev = NULL;
	*a = last_to_first;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*last_to_first;

	if (*b == NULL || b == NULL || stack_size(*b) < 2)
		return ;
	last_to_first = find_last(*b);
	last_to_first->prev->next = NULL;
	last_to_first->next = *b;
	last_to_first->prev = NULL;
	*b = last_to_first;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write (1, "rrr\n", 4);
}
