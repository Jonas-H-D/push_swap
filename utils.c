/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:49:07 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 12:03:13 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_tabcount(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	ft_check_args(char **argv, t_stacks *stacks, t_data *data)
{
	int		i;
	int		j;
	char	**args;

	i = ft_tabcount(argv) - 1;
	data->arg_size = i;
	while (i > 0)
	{
		if (ft_strichr(argv[i], ' '))
		{
			data->arg_size--;
			args = ft_split(argv[i], ' ');
			j = ft_tabcount(args) - 1;
			while (j > -1)
			{
				insertion(stacks->premiera, args[j]);
				data->arg_size++;
				j--;
			}
		}
		else
			insertion(stacks->premiera, argv[i]);
		i--;
	}
}

int	ft_isuniq(t_Liste *liste, int nbr)
{
	t_Element	*actuel;

	actuel = liste->premier;
	while (actuel != NULL)
	{
		if (actuel->nombre == nbr)
			return (0);
		actuel = actuel->suivant;
	}
	return (1);
}
