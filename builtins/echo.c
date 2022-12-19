/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 13:21:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	trot(t_data *data, char **args, int i)
{
	int		j;
	int		ret;
	char	**one;

	while (args[i])
	{
		one = ft_split_normal(args[i], ' ');
		if (!one)
			return (free_tab(one), 1);
		j = 0;
		while (one[j])
		{
			ret = ft_putstr_echo(data, one, j);
			j++;
			if (one[j] && ret != 0)
				write(STDOUT_FILENO, " ", 1);
		}
		i++;
		free_tab(one);
		if (args[i] && ret != 0)
			write(STDOUT_FILENO, " ", 1);
	}
	return (0);
}

void	ft_echo(t_data *data, char **args)
{
	int		i;
	int		ret;
	int		boule;

	boule = 0;
	i = 0;
	while (args[i] && is_option_n(args[i]))
	{
		i++;
		boule = 1;
	}
	ret = trot(data, args, i);
	if (boule == 0)
		write(STDOUT_FILENO, "\n", 1);
	data->return_val = 0;
}
