/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:59:14 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/30 10:42:56 by evanheum         ###   ########.fr       */
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
	lem->room_size = 0;
	lem->pathz = NULL;
	lem->namelen = 0;
	lem->pathid = 0;
	lem->aryid = 0;
	return (lem);
}

