/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:34:50 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/13 15:40:58 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

t_stack	*find_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void	push_element_at_final(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->val = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*find_small(t_stack *stack)
{
	int		small;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	small = INT_MAX;
	smallest_node = NULL;
	while (stack)
	{
		if (stack->val < small)
		{
			small = stack->val;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

int	stack_size(t_stack *stack)
{
	int	cont;

	cont = 0;
	while (stack)
	{
		cont++;
		stack = stack->next;
	}
	return (cont);
}

int	stack_is_sorted(t_stack *stk)
{
	while (stk->next)
	{
		if (stk->val > stk->next->val)
			return (0);
		stk = stk->next;
	}
	return (1);
}
