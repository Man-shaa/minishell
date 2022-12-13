/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/13 16:22:56 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)

#include "../includes/minishell.h"

void	ft_echo(t_data *data, char **args)
{
	int		i;
	int		ret;
	int		boule;
	char	**one;

	boule = 0;
	i = 0;
	while (args[i] && is_option_n(args[i]))
	{
		i++;
		boule = 1;
	}
	while (args[i])
	{
		one = ft_split_normal(args[i], ' ');
		ret = ft_putstr_echo(data, args, i);
		i++;
		if (args[i] && ret != 0)
			write(1, " ", 1);
	}
	if (boule == 0)
		write(1, "\n", 1);
	data->return_val = 0;
}
