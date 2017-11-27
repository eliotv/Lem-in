/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/17 16:13:39 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void    link_store(t_lem *lem, char *line)
{

}

void    room_store(t_lem *lem, char *line)
{
    char **str;
    t_room *new;

    while (lem->room)
        lem->room = lem->room->next;
    str = ft_strsplit(line, ' ');
    lem->room->name = str[0];
    lem->room->x = ft_atoi(str[1]);
    lem->room->y = ft_atoi(str[2]);
    new = (t_room*)malloc(sizeof(t_link));
    new = lem->room->next;
    lem->room = lem->room->next;

    // lem->room = lem->room->next;
    ft_printf("%s\n%d\t%d\n", lem->room->name, lem->room->x, lem->room->y);

}