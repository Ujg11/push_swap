/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:31:55 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/08 14:41:29 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void	init_stack(t_stack **a, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 0;
	if (!flag)
		argv++;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, argv, flag);
		if (rep_error(*a, (int)nbr))
			error_free(a, argv, flag);
		push_element_at_final(a, (int)nbr, i);
		i++;
	}
	if (flag)
		free_arguments(argv);
}
