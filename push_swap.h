/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:52:26 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/08 15:52:39 by ojimenez         ###   ########.fr       */
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

typedef struct s_stack
{
	int				val;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//init_stack.c
void	init_stack(t_stack **a, char **argv, int flag);

//stack_utils.c
t_stack	*find_last(t_stack *stack);
void	push_element_at_final(t_stack **stack, int nbr, int pos);
t_stack	*find_small(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stk);

//errors.c
int		syntax_error(char *s);
int		rep_error(t_stack *a, int nbr);
void	free_arguments(char **argv);
void	free_stack(t_stack **stack);
void	error_free(t_stack **a, char **argv, int flag);

//swap.c
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b);

//push.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//rotate.c
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);

//reverse_rotate.c
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);

//sort_for_three.c
void	sort_for_three(t_stack **a);

//sort_for_five.c
void	sort_for_five(t_stack **a, t_stack **b);

//push_swap.c
void	push_swap(t_stack **a, t_stack **b);

#endif