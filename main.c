/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  main.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:52:11 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/20 17:57:46 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2 && argv[1][0] == '\0')
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');//ens poden pasar tots els nums en el argv[1]
	init_stack(&a, argv + 1, argc == 2);//ens pasen cada num com un argument
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_for_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}