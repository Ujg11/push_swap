/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:31:08 by ojimenez          #+#    #+#             */
/*   Updated: 2023/08/29 14:45:24 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	syntax_error(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	rep_error(t_stack *a, int nbr)
{
	if (a == NULL)
		return (1);
	while (a)
	{
		if (a->val == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

//En el cas que flag sigui true voldra dir que s'ha fet un split i s'ha de lliberar, sinó no
void	error_free(t_stack **a, char **argv, bool flag)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (a != NULL && *a != NULL)
	{
		while (*a != NULL)
		{
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
		}
	}
	if (argv != NULL && flag)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	write (2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
