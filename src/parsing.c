/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:54:59 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/08 18:35:52 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		check_double_link(t_lemin *env, t_room *r_a, t_room *r_b)
{
	if (get_link_by_room(r_a, r_b) || r_a == r_b)
	{
		if (env->log == 1)
			ft_printf("Link already exist or link same room, skip to next\n");
		return (-1);
	}
	return (0);
}

int		countchar(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

void	get_comment(char *str)
{
	ft_putendl(str);
}

void	parse_input(t_lemin *env)
{
	if (isatty(env->fd))
		error_msg(env, "ERROR : No map file specified", 0);
	parse_ants(env);
	parse_rooms(env);
	if (env->start_room == 0 || env->end_room == 0)
	{
		ft_strdel(&env->line);
		error_msg(env, "ERROR : End room or start room missing", 1);
	}
	parse_links(env);
}
