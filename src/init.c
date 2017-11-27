/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:59:14 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/27 14:45:33 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_lem		*init_struct(void)
{
	t_lem	*lem;

	lem = (t_lem*)malloc(sizeof(t_lem));
	// init_link(lem);
	// ft_printf("1\n");
	// init_room(lem);
	lem->ants = 0;
	lem->flag = 0;
	lem->room = NULL;
	lem->link = NULL;
	return (lem);
}

