/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:51:28 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/02 13:13:27 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a, swap 2 first element of stack a.
void	ft_sa(t_stacks *liste)
{
	int			toswap1;
	t_Element	*stack;

	if (liste != NULL)
	{
		stack = liste->premiera->premier;
		if (stack != NULL && stack->suivant != NULL)
		{
			toswap1 = stack->suivant->nombre;
			stack->suivant->nombre = stack->nombre;
			stack->nombre = toswap1;
			printf("sa\n");
		}
	}
}

// (rotate a) shift up all elements of stack A, first becomes last
void	ft_ra(t_stacks *liste)
{
	t_Element	*current;
	t_Element	*temp;
	int			top;

	if (liste != NULL)
	{
		current = liste->premiera->premier;
		if (current->suivant != NULL)
		{
			temp = liste->premiera->premier;
			top = current->nombre;
			while (current->suivant != NULL)
			{
				current->nombre = temp->suivant->nombre;
				current = current->suivant;
				temp = temp->suivant;
			}
			current->nombre = top;
			printf("ra\n");
		}
	}
}

int	ft_tab_lena(t_stacks *liste, t_data *data)
{
	t_Element	*current;
	int			i;

	current = liste->premiera->premier;
	i = 1;
	while (current->suivant != NULL)
	{
		current = current->suivant;
		i++;
	}
	data->topa = current->nombre;
	return (i);
}

// rra reverse - rotate A - Shift down all elements 
//of stack a by 1 The last element becomes the first one.
void	ft_rra(t_stacks *liste, t_data *data)
{
	t_Element	*current;
	int			*temp;
	int			i;

	if (liste != NULL)
	{
		temp = malloc(sizeof(int) * ft_tab_lena(liste, data) + 2);
		current = liste->premiera->premier;
		temp[0] = data->topa;
		i = 1;
		while (current->suivant != NULL)
		{
			temp[i++] = current->nombre;
			current = current->suivant;
		}
		current = liste->premiera->premier;
		i = 0;
		while (current->suivant != NULL)
		{
			current->nombre = temp[i++];
			current = current->suivant;
		}
		current->nombre = temp[i];
		free (temp);
		printf("rra\n");
	}
}
