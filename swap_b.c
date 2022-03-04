/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:51:24 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 14:58:33 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap b, swap 2 first element of stack b.
void	ft_sb(t_stacks *liste)
{
	t_Element	*stack;
	int			toswap1;

	if (liste != NULL)
	{
		stack = liste->premierb->premier;
		if (stack != NULL && stack->suivant != NULL)
		{
			toswap1 = stack->suivant->nombre;
			stack->suivant->nombre = stack->nombre;
			stack->nombre = toswap1;
			write(1, "sb\n", 3);
		}
	}
}

// (rotate b) shift up all elements of stack B, first becomes last
void	ft_rb(t_stacks *liste)
{
	t_Element	*current;
	t_Element	*temp;
	int			top;

	if (liste != NULL)
	{
		current = liste->premierb->premier;
		temp = liste->premierb->premier;
		top = current->nombre;
		while (current->suivant != NULL)
		{
			current->nombre = temp->suivant->nombre;
			current = current->suivant;
			temp = temp->suivant;
		}
		current->nombre = top;
		write(1, "rb\n", 3);
	}
}

int	ft_tab_lenb(t_stacks *liste, t_data *data)
{
	t_Element	*current;
	int			i;

	current = liste->premierb->premier;
	i = 1;
	while (current->suivant != NULL)
	{
		current = current->suivant;
		i++;
	}
	data->top = current->nombre;
	return (i);
}

void	ft_tempb(t_stacks *liste, int *temp)
{
	t_Element	*current;
	int			i;

	current = liste->premierb->premier;
	i = 0;
	while (current->suivant != NULL)
	{
		current->nombre = temp[i++];
		current = current->suivant;
	}
	current->nombre = temp[i];
}

// rrb reverse - rotate B - Shift down all 
//elements of stack b by 1 The last element becomes the first one.
void	ft_rrb(t_stacks *liste, t_data *data)
{
	t_Element	*current;
	int			*temp;
	int			i;

	if (liste != NULL)
	{
		temp = malloc(sizeof(int) * ft_tab_lenb(liste, data) + 2);
		current = liste->premierb->premier;
		temp[0] = data->top;
		i = 1;
		while (current->suivant != NULL)
		{
			temp[i++] = current->nombre;
			current = current->suivant;
		}
		ft_tempb(liste, temp);
		write(1, "rrb\n", 4);
	}
}
