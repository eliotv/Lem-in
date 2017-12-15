/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/14 16:17:25 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			error_handling(t_lem *lem, char *str)
{
	int		i;

	i = 6;
	ft_printf(YELLOW "ERROR: %s\n" END, str);
	sleep(1);
	ft_printf(CYAN "THIS PROGRAM WILL SELF DESTRUCT IN 5 SECONDS\n" END);
	sleep(1);
	while (--i > 0)
	{
		ft_printf(YELLOW "%d\t" END, i);
		sleep(1);
	}
	ft_printf(RED "BOOOOOOOM!!!\n" END);
	free_ant(lem);
	exit(0);
}

int			main(void)
{
	t_lem	*lem;

	lem = init_struct();
	ant_count(lem);
	read_input(lem);
	start_path(lem);
	find_optimal_path(lem);
	remove_paths(lem);
	print_read(lem);
	shortest_opt_path(lem);
	free_ant(lem);
	free(lem);
	return (0);
}
