/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:52:26 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/20 18:09:38 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef struct	s_stack
{
	int				val;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//init_stack.c
void	init_stack(t_stack **a, char **argv, int flag);

//stack_utils.c
t_stack *find_last(t_stack *stack);
void	push_element_at_final(t_stack **stack, int nbr);
t_stack	*find_small(t_stack *stack);
int		stack_size(t_stack *stack);

//errors.c
int		syntax_error(char *s);
int		rep_error(t_stack *a, int nbr);
void	error_free(t_stack **a, char **argv, int flag);

//swap.c
void	sa(t_stack **a, int flag)
void	sa(t_stack **b, int flag)
void	ss(t_stack **a, t_stack **b);

//push.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//rotate.c
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);

#endif