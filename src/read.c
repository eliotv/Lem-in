/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:16:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/30 08:39:15 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int ant_count(t_lem *lem)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	if (check_xy_format(line))
		error_handling();
	lem->ants = ft_atoi(line);
	if(lem->ants < 1)
		error_handling();
	ft_strdel(&line);
	return (0);
}

void	read_input(t_lem *lem)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "##start", 7))
			lem->sflag++;
		else if(!ft_strncmp(line, "##end", 5))
			lem->eflag++;
		else if (line[0] != '#')
			check_format(lem, line);
		ft_strdel(&line);
	}
	if(lem->eflag != 2 || lem->sflag != 2)
		error_handling();
}