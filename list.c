/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:17 by jhermon-          #+#    #+#             */
/*   Updated: 2022/03/04 14:57:09 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Liste	*initialisation(t_Element *liste)
{
	t_Liste	*premier;

	premier = malloc(sizeof(*premier));
	if (!premier)
		exit (-1);
	liste->suivant = NULL;
	return (premier);
}

void	insertion(t_Liste *liste, char *nvNbre)
{
	t_Element	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit (-1);
	if (ft_isuniq(liste, ft_atoi(nvNbre)))
	{
		nouveau->nombre = ft_atoi(nvNbre);
		nouveau->suivant = liste->premier;
		liste->premier = nouveau;
	}
	else
		ft_error();
}

void	push_insertion(t_Liste *liste, int nbr)
{
	t_Element	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit (-1);
	nouveau->nombre = nbr;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

void	suppression(t_Liste *liste)
{
	t_Element	*asupprimer;

	if (liste == NULL)
		exit(-1);
	if (liste->premier != NULL)
	{
		asupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(asupprimer);
	}
}

/*void	afficherliste(t_Liste *liste)
{
	t_Element	*actuel;

	if (liste == NULL)
		exit (-1);
	actuel = liste->premier;
	while (actuel != NULL)
	{
		printf("%d ->", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}*/
