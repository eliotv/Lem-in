/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:16:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/27 14:46:27 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int ant_count(t_lem *lem)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	lem->ants = ft_atoi(line);
	if(lem->ants < 1)
		error_handling();
	ft_strdel(&line);
	return (0);
}

void check_format_2(t_lem *lem, char *str)
{
	int link;
	int room;
	int i;

	i = 0;
	room = 0;
	link = 0;
	while (str[i])
	{
		if (str[i] == '-')
			link = 1;
		if (str[i] == ' ')
			room = 1;
		i++;
	}
	// ft_printf("%d\n", link);
	if (link == 1)
		lem->link = link_store(lem, str);
	if (room == 1)
		lem->room = room_store(lem, str);
}

void	check_format(t_lem *lem)
{
	char *line;
	t_link *tmp;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "##start", 7))
			lem->flag++;
		else if(!ft_strncmp(line, "##end", 5))
			lem->flag++;
		else if (line[0] != '#')
			check_format_2(lem, line);
		ft_strdel(&line);
	}
	tmp = lem->link;
	while (tmp)
	{
		ft_printf("%s\t%s\n", tmp->a, tmp->b);
		tmp = tmp->next;
	}
	if (lem->flag != 2)
		error_handling();
}