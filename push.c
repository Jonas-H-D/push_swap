/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:51:05 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 14:57:45 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PA, pushes first element of B and put it as first of A
void	ft_pa(t_stacks *liste)
{
	t_Liste	*stacka;
	t_Liste	*stackb;

	stacka = liste->premiera;
	stackb = liste->premierb;
	if (stackb->premier != NULL)
	{
		push_insertion(stacka, stackb->premier->nombre);
		suppression(stackb);
		write(1, "pa\n", 3);
	}
}

// PB, pushes first element of A and put it as first of B
void	ft_pb(t_stacks *liste)
{
	t_Liste	*stacka;
	t_Liste	*stackb;

	stacka = liste->premiera;
	stackb = liste->premierb;
	if (stacka->premier != NULL)
	{
		push_insertion(stackb, stacka->premier->nombre);
		suppression(stacka);
		write(1, "pb\n", 3);
	}
}
