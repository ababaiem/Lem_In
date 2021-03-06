/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:54:59 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/08 18:35:52 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static	int		isnbr(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == ' '))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

void			parse_ants(t_lemin *env)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		if (isnbr(line) == 1)
		{
			if ((env->nb_ants = ft_atoi(line)) <= 0)
				error_free_str(env,
					"ERROR numbers of ants is negative or null\n", line);
			ft_printf("%s\n", line);
			break ;
		}
		else if (line[0] == '#')
			get_comment(line);
		else
			error_free_str(env, "ERROR wrong format for ants number\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ret == -1 || ret == 0)
		error_msg(env, "ERROR: file error or empty file\n", 1);
}
