/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/08 18:35:54 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

# define USAGE "usage:\n./lem_in < \"map-file\" or ./lem_in -m \"map-file\"\n\
		\nOptions:\n-h : print usage (only print usage)\
		\n-i : print input\n-m : enter a file-name\n"

void		print_usage(t_lemin *env)
{
	ft_putendl(USAGE);
	if (env->fd)
		close(env->fd);
	exit(0);
}

void		open_map_file(t_lemin *env, int *i, char **av)
{
	(*i)++;
	if (!isatty(env->fd) || env->fd)
		error_msg(env, "Only one map can be specified");
	if ((env->fd = open(av[*i], O_RDONLY)) == -1)
		error_msg(env, "ERROR : map_file cannot be opened");
	(*i)++;
}

void	check_arg(t_lemin *env, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-h"))
			print_usage(env);
		else if (ft_strequ(av[i], "-i"))
			env->log = PRINT_LOG;
		else if (ft_strequ(av[i], "-m"))
			open_map_file(env, &i, av);
		else
		{
			ft_printf("error: wrong option \"%s\"\n\n", av[i]);
			print_usage(env);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_lemin		env;

	ft_bzero(&env, sizeof(env));
	if (ac != 1)
		check_arg(&env, av, ac);
	parse_input(&env);
	if (env.fd)
		close(env.fd);
	free_room_map(&env);
	return (0);
}
