/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:59:14 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/09 16:37:00 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_lem		*init_struct(void)
{
	t_lem	*lem;

	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->ants = 0;
	lem->sflag = 0;
	lem->eflag = 0;
	lem->start = "\0";
	lem->end = "\0";
	lem->room = NULL;
	lem->path = NULL;
	lem->room_size = 0;
	lem->namelen = 0;
	lem->pathid = 1;
	lem->aryid = 0;
	lem->len = 0;
	return (lem);
}

// int compare_path(t_path *path, t_path *p_next)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	while (i < path->len)
// 	{
// 		j = 1;
// 		while (j < p_next->len)
// 		{
// 			if (!ft_strcmp(path->valid[i], p_next->valid[j]))
// 			{
// 				return (-1);
// 			}
			
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

void ft_print2d(char **ary, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		ft_printf(YELLOW"%s\t" END, ary[i]);
		i++;
	}
}

