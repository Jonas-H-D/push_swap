/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:27:27 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 14:59:56 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_printtab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

void	ft_issmaller(t_stacks *liste)
{
	while (liste->premiera->premier->nombre != 0)
	{
		ft_ra(liste);
	}
	ft_pb(liste);
}

void	ft_moveit(t_stacks *liste, t_data *data)
{
	ft_rra(liste, data);
	ft_sa(liste);
	ft_rra(liste, data);
	ft_sa(liste);
	ft_rra(liste, data);
	ft_rra(liste, data);
}
