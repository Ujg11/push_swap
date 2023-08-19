#include "push_swap.h"
#include "./libft/libft.h"

t_stack *find_last(t_stack *stack)
{
	t_stack	*last;

	if (stack == NULL)
		return (NULL);
	last = stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
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
		*stack == node;
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
	int cont;

	cont = 0;
	while (stack)
	{
		cont++;
		stack = stack->next;
	}
	return (cont);
}