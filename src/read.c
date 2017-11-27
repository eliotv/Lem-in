/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:16:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/17 16:12:51 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int ant_count(t_lem *lem)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	// ft_printf("%s\n", line);
	lem->ants = ft_atoi(line);
	if(lem->ants < 1)
		error_handling();
	ft_strdel(&line);
	return (0);
}

void	check_format(t_lem *lem)
{
	char *line;
	int i;
	
	while(get_next_line(0, &line) > 0)
	{
		i = 0;
		if (!ft_strncmp(line, "##start", 7))
			lem->flag++;
		else if(!ft_strncmp(line, "##end", 5))
			lem->flag++;
		else if (ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == '-')
				link_store(lem, line);
			else if (line[i] == ' ')
				room_store(lem, line);
			else
				error_handling();
		}
		ft_strdel(&line);
		
	}
	// ft_printf("%d\n", lem->flag);
	if (lem->flag != 2)
		error_handling();
}