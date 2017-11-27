/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/16 16:35:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int error_handling(void)
{
	int i;

	i = 6;
	ft_printf( YELLOW "ERROR: INVALID FILE \n" END);
	sleep(1);
	ft_printf( CYAN "THIS PROGRAM WILL SELF DESTRUCT IN 5 SECONDS\n" END);
	sleep(1);
	while(--i > 0)
	{
		ft_printf(YELLOW "%d\t" END, i);
		sleep(1);
	}
	ft_printf(RED "BOOOOOOOM!!!\n" END);
	exit(0);
}

int		main(void)
{
	t_lem	*lem;
	lem = init_struct();
	ant_count(lem);
	check_format(lem);
	// ft_printf("1\n");
}