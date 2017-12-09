/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:00:34 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/09 14:17:47 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../lemin.h"

void remove_paths(t_lem *lem)
{
	t_path *cur;
	t_path *prev;
	t_path *tmp;
	if (!lem->path)
		return ;
	while(lem->path->flag != 1 && lem->path)
	{
		tmp = lem->path;
		lem->path = lem->path->next;
		free(tmp);
	}
	cur = lem->path;
	while (cur)
	{
		while(cur->next && cur->next->flag == 0)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
		}
		cur = cur->next;
	}
}