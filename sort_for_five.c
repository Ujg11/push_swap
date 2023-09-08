/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:18:26 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/08 16:12:42 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_for_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_val;
	int		i;

	i = 0;
	while (i < 2)
	{
		min_node = find_small(*a);
		min_val = min_node->val;
		if (min_node == find_last(*a))
			rra(a, 1);
		if ((*a)->val > min_val)
			ra(a, 1);
		else
		{
			pb(b, a);
			i++;
		}
	}
	sort_for_three(a);
	pa(a, b);
	pa(a, b);
}
