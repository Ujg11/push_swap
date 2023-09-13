/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:16:10 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/13 15:25:06 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

/*static int	next_move(t_stack *a)
{
	t_stack	*small;
	t_stack	*current;
	int		cont;
	int		ret;

	current = a;
	small = find_small(a);
	cont = 1;
	ret = 0;
	while (current != NULL && current->val != small->val)
	{
		current = current->next;
		cont++;
	}
	if (cont > stack_size(a) / 2)
		ret = 2;
	else if (cont <= stack_size(a) / 2)
		ret = 1;
	return (ret);
}

static void	move_up_or_down(t_stack **a, t_stack *small, int move)
{
	while (*a != small)
	{
		if (move == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

static void	turn_to_a(t_stack **a, t_stack **b)
{
	while (stack_size(*b) != 0)
		pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		mid;
	int		move;
	t_stack	*small;
	t_stack	*current;

	if (*a == NULL || a == NULL)
		return ;
	mid = stack_size(*a) / 2;
	current = *a;
	while (stack_size(*a) > 3 && !stack_is_sorted(*a))
	{
		small = find_small(*a);
		move = next_move(*a);
		ft_printf("farem el move_up_down\n");
		move_up_or_down(a, small, move);
		ft_printf("move_up_down fet\n");
		pb(b, a);
	}
	if (stack_size(*a) == 3)
		sort_for_three(a);
	turn_to_a(a, b);
}*/

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		size_a;

	size_a = stack_size(*a);
	while (size_a > 3)
	{
		pb(b, a);
		size_a--;
	}
	while (*b)
	{
		init_nodes
	}
}






// Función para encontrar el número mínimo en una pila
int find_min(t_stack *stack) {
    int min_val = stack->val;
    while (stack) {
        if (stack->val < min_val) {
            min_val = stack->val;
        }
        stack = stack->next;
    }
    return min_val;
}

// Función para contar el número de elementos en una pila
int count_elements(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

// Función para realizar una operación de push_swap
void push_swap_sort(t_stack **stack_a, t_stack **stack_b) {
    while (*stack_a != NULL) {
        int min_val = find_min(*stack_a);
        int min_index = count_elements(*stack_a) - 1;

        // Paso 2: Encontrar el número más barato
        while ((*stack_a)->val != min_val || (*stack_a)->index != min_index) {
            if ((*stack_a)->val == min_val) {
                // Realizar una rotación inversa en A
                rra(stack_a);
            } else {
                // Realizar una rotación en A
                ra(stack_a);
            }
        }

        // Empujar el número más barato a B
        pb(stack_a, stack_b);
    }

    // Paso 3: Últimos tres elementos
    if (count_elements(*stack_b) == 3) {
        // Realizar operaciones especiales en B
        special_operations(stack_b);
    }

    // Paso 4: Regresar a A
    while (*stack_b != NULL) {
        int max_val = find_max(*stack_b);
        int max_index = count_elements(*stack_b) - 1;

        // Encontrar el número más caro en B
        while ((*stack_b)->val != max_val || (*stack_b)->index != max_index) {
            if ((*stack_b)->val == max_val) {
                // Realizar una rotación inversa en B
                rrb(stack_b);
            } else {
                // Realizar una rotación en B
                rb(stack_b);
            }
        }

        // Empujar el número más caro a A
        pa(stack_b, stack_a);
    }

    // Paso 5: Arreglo final
    int min_val = find_min(*stack_a);
    while ((*stack_a)->val != min_val) {
        ra(stack_a);
    }
}
