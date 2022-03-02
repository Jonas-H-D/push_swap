/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:21 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/02 13:47:21 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stacks *liste, t_data *data)
{
	t_Element	*stack;

	stack = liste->premiera->premier;
	if (stack->suivant->suivant == NULL)
		ft_sort_2(liste);
	else if (stack->suivant->suivant->suivant == NULL)
		ft_sort_3(liste, data);
	else if (stack->suivant->suivant->suivant->suivant == NULL)
		ft_sort_4(liste, data);
	else
		ft_sort_5(liste, data);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = malloc(sizeof(*stacks));
		stacks->listea = malloc(sizeof(*stacks->listea));
		stacks->listeb = malloc(sizeof(*stacks->listeb));
		stacks->premiera = initialisation(stacks->listea);
		stacks->premierb = initialisation(stacks->listeb);
		ft_check_args(argv, stacks, &data);
		if (data.arg_size == 1)
			return (0);
		if (!ft_a_sorted(stacks))
		{
			sort_numbers_ascending(stacks, &data);
			assign_index_value(stacks, &data);
			if (data.arg_size < 6)
				ft_sort_small(stacks, &data);
			else
				bitwise(&data, stacks);
		}
	}
	return (0);
}
