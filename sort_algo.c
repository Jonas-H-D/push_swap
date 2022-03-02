/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:03 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/02 13:48:17 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inputdata(t_data *data, t_stacks *liste)
{
	int			i;
	t_Element	*stack;

	stack = liste->premiera->premier;
	i = 0;
	while (stack != NULL)
	{
		stack->nombre = data->input[i];
		i++;
		stack = stack->suivant;
	}
}

void	assign_index_value(t_stacks *liste, t_data *data)
{
	int			i;
	int			j;
	int			size;

	i = 0;
	size = data->arg_size;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (data->input[i] == data->copy[j])
			{
				data->input[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_inputdata(data, liste);
}

void	ft_copy(int i, int j, t_data *data)
{
	int	k;
	int	temp;

	while (i <= data->arg_size)
	{
		data->copy[i] = data->input[i];
		i++;
	}
	while (j < data->arg_size)
	{
		k = j + 1;
		while (k < data->arg_size)
		{
			if (data->copy[j] > data->copy[k])
			{
				temp = data->copy[j];
				data->copy[j] = data->copy[k];
				data->copy[k] = temp;
			}
			k++;
		}
		j++;
	}
}

void	sort_numbers_ascending(t_stacks *liste, t_data *data)
{
	int			i;
	int			j;
	t_Element	*stack;

	stack = liste->premiera->premier;
	i = 0;
	data->input = (int *)malloc(sizeof(int) * data->arg_size + 2);
	while (stack != NULL)
	{
		data->input[i++] = stack->nombre;
		stack = stack->suivant;
	}
	j = 0;
	data->copy = (int *)malloc(sizeof(int) * data->arg_size + 2);
	i = 0;
	ft_copy(i, j, data);
}
