/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/13 18:05:52 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)

#include "../includes/minishell.h"

void	ft_echo(t_data *data, char **args)
{
	int		i;
	int		j;
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
		j = 0;
		while (one[j])
		{
			ret = ft_putstr_echo(data, one, j);
			j++;
			if (one[j] && ret != 0)
				write(1, " ", 1);
		}
		free_tab(one);
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (boule == 0)
		write(1, "\n", 1);
	data->return_val = 0;
}
