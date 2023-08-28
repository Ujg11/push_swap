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

void	error_free(t_stack **a, char **argv, int flag)
{
	int i;

	i = 0;
	if (a != NULL && *a != NULL)
	{
		t_stack *tmp;

		while (*a != NULL)
		{
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
		}
		*a = NULL;
	}
	if (argv != NULL && *argv != NULL)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	write (1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}