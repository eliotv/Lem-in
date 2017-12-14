/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:16:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 14:52:43 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			ant_count(t_lem *lem)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	if (check_xy_format(line))
		error_handling(lem, "Invalid ant count");
	lem->antcount = ft_atoi(line);
	if (lem->antcount < 1)
		error_handling(lem, "Invalid ant count");
	while (++i <= lem->antcount)
		lem->ant = store_ants(lem, i);
	lem->read = store_file(lem, line);
	return (0);
}

void		read_input(t_lem *lem)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "##start", 7))
			lem->sflag++;
		else if (!ft_strncmp(line, "##end", 5))
			lem->eflag++;
		else if (line[0] != '#')
			check_format(lem, line);
		lem->read = store_file(lem, line);
	}
	if (lem->eflag != 2 || lem->sflag != 2)
		error_handling(lem, "Invalid number of starts or ends");
}

t_read		*store_file(t_lem *lem, char *str)
{
	t_read	*new;
	t_read	*read;

	if (!(new = (t_read*)malloc(sizeof(t_read))))
		return (NULL);
	new->str = str;
	new->next = NULL;
	if (!lem->read)
		return (new);
	read = lem->read;
	while (read->next)
		read = read->next;
	read->next = new;
	return (lem->read);
}
