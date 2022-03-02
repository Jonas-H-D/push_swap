/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:51:19 by jhermon-          #+#    #+#             */
/*   Updated: 2022/02/28 16:03:38 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate A + B at the same time, first element becomes last
void	ft_rr(t_stacks *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}

// swap A + B at the same time, swap 2 first element of stacks a + b.
void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks);
}

// rotate A + B at the same time, last element becomes first

void	ft_rrr(t_stacks *stack, t_data *data)
{
	ft_rra(stack, data);
	ft_rrb(stack, data);
}
