/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:09 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/01 20:12:20 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_a_sorted(t_stacks *liste)
{
	t_Element	*stack;

	stack = liste->premiera->premier;
	if (stack->suivant == NULL)
		return (0);
	while (stack->suivant != NULL)
	{
		if (stack->nombre > stack->suivant->nombre)
			return (0);
		stack = stack->suivant;
	}
	return (1);
}

void	ft_sort_2(t_stacks *liste)
{
	t_Element	*stack;

	stack = liste->premiera->premier;
	if (stack->nombre > stack->suivant->nombre)
		ft_sa(liste);
}

void	ft_sort_3(t_stacks *liste, t_data *data)
{
	t_Element	*stack;

	stack = liste->premiera->premier;
	if (stack->nombre > stack->suivant->nombre)
	{
		ft_sa(liste);
	}
	if (stack->suivant->nombre > stack->suivant->suivant->nombre)
	{
		ft_rra(liste, data);
	}
	if (stack->nombre > stack->suivant->nombre)
		ft_sa(liste);
}

void	ft_sort_4(t_stacks *liste, t_data *data)
{
	ft_pb(liste);
	ft_sort_3(liste, data);
	ft_pa(liste);
	if (liste->premiera->premier->nombre
		> liste->premiera->premier->suivant->nombre)
	{
		if (liste->premiera->premier->nombre
			> liste->premiera->premier->suivant->suivant->nombre)
		{
			if (liste->premiera->premier->nombre
				< liste->premiera->premier->suivant->suivant->suivant->nombre)
			{
				ft_rra(liste, data);
				ft_sa(liste);
				ft_ra(liste);
				ft_ra(liste);
			}
			else
				ft_ra(liste);
		}
		else
			ft_sa(liste);
	}
}

void	ft_sort_5(t_stacks *liste, t_data *data)
{
	ft_issmaller(liste);
	ft_sort_4(liste, data);
	ft_pa(liste);
	ft_rra(liste, data);
	if (liste->premiera->premier->nombre
		> liste->premiera->premier->suivant->nombre)
	{
		if (liste->premiera->premier->nombre
			> liste->premiera->premier->suivant->suivant->nombre)
		{
			if (liste->premiera->premier->nombre < liste
				->premiera->premier->suivant->suivant->suivant->suivant->nombre)
			{
				ft_moveit(liste, data);
			}
			else
				ft_ra(liste);
		}
		else
			ft_sa(liste);
	}
}
