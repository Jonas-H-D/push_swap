/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:14 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 14:59:42 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_bitwise(t_data *data, t_stacks *liste)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = data->arg_size;
	if (!liste)
		ft_error();
	max_num = size - 1;
	max_bits = 0;
	data->max_num = max_num;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	data->max_bits = max_bits;
}

void	ft_emptyb(t_stacks *liste)
{
	t_Element	*stackb;

	stackb = liste->premierb->premier;
	while (stackb != NULL)
	{
		ft_pa(liste);
		stackb = stackb->suivant;
	}
}

void	ft_shift(int i, t_stacks *liste)
{
	int			num;

	num = liste->premiera->premier->nombre;
	if (((num >> i) & 1) == 1)
		ft_ra(liste);
	else
		ft_pb(liste);
}

void	bitwise(t_data *data, t_stacks *liste)
{
	int			size;
	int			i;
	int			j;

	ft_init_bitwise(data, liste);
	i = 0;
	size = data->arg_size;
	while (i < data->max_bits)
	{
		j = 0;
		while (j < size)
		{
			ft_shift(i, liste);
			j++;
		}
		ft_emptyb(liste);
		i++;
	}
}
