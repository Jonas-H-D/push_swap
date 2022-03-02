/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:25 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/02 13:40:14 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_Element
{
	struct s_Element	*suivant;
	int					nombre;
}	t_Element;

typedef struct s_Liste
{
	t_Element	*premier;
}	t_Liste;

typedef struct s_stacks
{
	t_Element	*listea;
	t_Element	*listeb;
	t_Liste		*premiera;
	t_Liste		*premierb;
}	t_stacks;

typedef struct s_data
{
	int	*copy;
	int	*input;
	int	arg_size;
	int	top;
	int	topa;
	int	max_num;
	int	max_bits;
}	t_data;

long	ft_putnbr_binary(int n);
void	ft_error(void);
long	ft_atoi(char *str);
void	ft_issmaller(t_stacks *liste);
void	ft_moveit(t_stacks *liste, t_data *data);
char	**ft_split(char *s, char c);
char	*ft_itoa(long n);
int		ft_strlen(char *s);
int		ft_isuniq(t_Liste	*liste, int nbr);
int		ft_a_sorted(t_stacks *liste);
void	insertion(t_Liste *liste, char *nvNbre);
void	push_insertion(t_Liste *liste, int nbr);
void	suppression(t_Liste *liste);
void	afficherliste(t_Liste *liste);
void	ft_check_args(char **argv, t_stacks *stacks, t_data *data);
void	assign_index_value(t_stacks *liste, t_data *data);
void	sort_numbers_ascending(t_stacks *liste, t_data *data);
void	ft_sort_small(t_stacks *liste, t_data *data);
void	ft_sort_5(t_stacks *liste, t_data *data);
void	ft_sort_4(t_stacks *liste, t_data *data);
void	ft_sort_3(t_stacks *liste, t_data *data);
void	ft_sort_2(t_stacks *liste);
void	ft_sa(t_stacks *liste);
void	ft_sb(t_stacks *liste);
void	ft_ss(t_stacks *stacks);
void	ft_ra(t_stacks *liste);
void	ft_rb(t_stacks *liste);
void	ft_rr(t_stacks *stack);
void	ft_rra(t_stacks *liste, t_data *data);
void	ft_rrb(t_stacks *liste, t_data *data);
void	ft_rrr(t_stacks *stack, t_data *data);
void	ft_pa(t_stacks *liste);
void	ft_pb(t_stacks *liste);
void	ft_sort_2(t_stacks *liste);
void	ft_printtab(char	**tab);
void	bitwise(t_data *data, t_stacks *liste);
void	ft_add_missing_0(t_stacks *liste, t_data *data);
t_Liste	*initialisation(t_Element *liste);

#endif