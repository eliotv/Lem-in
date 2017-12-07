/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/06 18:57:23 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_path	*store_path(t_lem *lem, int len, char **rlist)
{
    t_path *new;
    t_path *tmp;
    int i;

    i = 0;
    tmp = lem->path;
    if (!(new = malloc(sizeof(t_path))))
        return NULL;
    new->valid = (char**)malloc(sizeof(char*) * lem->room_size + 1);
    new->len = len;
    new->weight = 0;
    new->flag = 0;
    while (i <= len)
    {
        new->valid[i] = ft_strdup(rlist[i]);
        i++;
    }
    new->valid[i] = NULL;
    new->next = NULL;
    if (!tmp)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (lem->path);
}

t_link       *append_link(t_room *r1, t_room *r2, char *name)
{
    t_link *link;
    t_link *new;
    int x;
    int y;

    while (r2->next && ft_strcmp(name, r2->name))
        r2 = r2->next;
    x = r1->x - r2->x;
    y = r1->y - r2->y;
    if (!(new = malloc(sizeof(t_link))))
        return NULL;
    new->dist = sqrt((x * x) + (y * y));
    new->room = r2;
    new->next = NULL;
    if (!r1->link)
        return(new);
    link = r1->link;
    while (link->next)
    {
        if (!ft_strcmp(link->room->name, name))
            return (r1->link);
        link = link->next;
    }
    if(ft_strcmp(link->room->name, name))
    {
        link->next = new;       
    }
    return (r1->link);
}

void        link_store(t_lem *lem, char *line)
{
    char**str;
    char *r1;
    char *r2;
    t_room *room;

    str = ft_strsplit(line, '-');
    if (valid_room(lem, str[0], str[1]) != 2)
        error_handling();
    r1 = str[0];
    r2 = str[1];
    room = lem->room;
    while (room)
    {
        if (!ft_strcmp(r1, room->name))
            room->link = append_link(room, lem->room, r2);
        else if (!ft_strcmp(r2, room->name))
            room->link = append_link(room, lem->room, r1);
        room = room->next;
    }
}

t_room    *room_store(t_lem *lem, char *line)
{
    char **str;
    t_room *tmp;
    t_room *new;
    
    new = NULL;
    tmp = lem->room;
    if(line[0] == 'L')
        error_handling();
    if (!(new = (t_room*)malloc(sizeof(t_room))))
        return NULL;
    str = ft_strsplit(line, ' ');
    if (lem->sflag == 1 || lem->eflag == 1)
        check_startend(lem,str[0]);
    // lem->namelen = (ft_strlen(str[0]) > lem->namelen) ? ft_strlen(str[0]) : lem->namelen;
    new->name = str[0];
    if (!check_xy_format(str[1]) && !check_xy_format(str[2]))
    {
        new->x = ft_atoi(str[1]);
        new->y = ft_atoi(str[2]);
    }
    else
        error_handling();
    new->link = NULL;
    new->next = NULL;
    lem->room_size++;
    if (tmp == NULL)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (lem->room);
}