/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:31:08 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/06 16:03:54 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	syntax_error(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	return (0);
}

int	rep_error(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->val == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_arguments(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*now;

	if (stack == NULL)
		return ;
	now = *stack;
	while (now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **argv, int flag)
{
	free_stack(a);
	if (flag == 1)
	{
		ft_printf("fem el free\n");
		free_arguments(argv);
	}
	write (2, "ERROR\n", 6);
	exit(1);
}
