/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/27 14:46:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int         valid_room(t_lem *lem, char *a, char *b)
{
    int flag;

    flag = 0;
    t_room *tmp = lem->room;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, a))
            flag++;
        else if(!ft_strcmp(tmp->name, b))
            flag++;
        tmp = tmp->next;
    }
    return (flag);
}

int        check_xy_format(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (0);
}

t_link		*link_store(t_lem *lem, char *line)
{
    char **str;
    t_link *tmp = lem->link;

    t_link *new = NULL;
    if (!(new = (t_link*)malloc(sizeof(t_link))))
        return NULL;
    str = ft_strsplit(line, '-');
    if (valid_room(lem, str[0], str[1]) != 2)
        error_handling();
    new->a = str[0];
    new->b = str[1];
    new->next = NULL;
    if (tmp == NULL)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return(lem->link);
}

t_room    *room_store(t_lem *lem, char *line)
{
    char **str;
    t_room *tmp = lem->room;

    if(line[0] == 'L')
        error_handling();
    t_room *new = NULL;
    if (!(new = (t_room*)malloc(sizeof(t_room))))
        return NULL;
    str = ft_strsplit(line, ' ');
    new->name = str[0];
    if (!check_xy_format(str[1]) && !check_xy_format(str[2]))
    {
        new->x = ft_atoi(str[1]);
        new->y = ft_atoi(str[2]);
    }
    else
        error_handling();
    new->next = NULL;
    if (tmp == NULL)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (lem->room);
}