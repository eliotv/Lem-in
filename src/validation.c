/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:28:22 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/29 12:18:28 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	check_startend(t_lem *lem, char *str)
{
	if (lem->sflag == 1)
	{
		lem->start = str;
		lem->sflag++;
	}
	else if (lem->eflag == 1)
	{
		lem->end = str;
		lem->eflag++;
	}
	else
		error_handling();
}

void check_format(t_lem *lem, char *str)
{
	int link;
	int room;
	int i;
	t_room *tmp;

	i = 0;
	room = 0;
	link = 0;
	while (str[i])
	{
		if (str[i] == '-')
			link = 1;
		else if (str[i] == ' ')
			room = 1;
		i++;
	}
	if (link == 1)
		link_store(lem, str);
	if (room == 1)
		lem->room = room_store(lem, str);
}

int         valid_room(t_lem *lem, char *a, char *b)
{
    int flag;
    t_room *tmp;
	
	tmp = lem->room;
    flag = 0;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, a))
            flag++;
        else if (!ft_strcmp(tmp->name, b))
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