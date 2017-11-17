/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:16:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/17 14:40:38 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	start_command(t_lem *lem)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	if (ft_strncmp(line, "##start", 7))
		error_handling();
	ft_strdel(&line);
	return (0);
}

int ant_count(t_lem *lem)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	ft_printf("%s\n", line);
	lem->ants = ft_atoi(line);
	if(lem->ants < 1)
		error_handling();
	ft_strdel(&line);
	return (0);
}