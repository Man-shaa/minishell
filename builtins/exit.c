/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:04:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/20 18:02:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_exit_option(char **args, int *return_val)
{
	int	i;

	i = 0;
	while (args[0][i])
	{
		if ((args[0][i] == '-' || args[0][i] == '+') && i == 0)
			i++;
		if ((args[0][i] < '0' || args[0][i] > '9'))
		{
			*return_val = err_msg("minishell: exit: ", args[0],
					": numeric argument required", 2);
			break ;
		}
		i++;
	}
	if (*return_val != 2)
		*return_val = ft_atoi(args[0]);
}

// Return 2
int	check_exit_numeric(char **args, int *return_val)
{
	int	i;

	i = 0;
	while (args[0][i])
	{
		if ((args[0][i] == '-' || args[0][i] == '+') && i == 0)
			i++;
		if (args[0][i] < '0' || args[0][i] > '9')
		{
			*return_val = 2;
			return (1);
		}
		i++;
	}
	return (0);
}

// Free data et return 0 ou args[0] si il existe 
int	ft_exit(t_data *data, char **args)
{
	int		return_val;

	return_val = 0;
	if (!args)
		return_val = 0;
	if (args[0] && check_exit_numeric(args, &return_val))
		err_msg("minishell: exit: ",
			args[0], ": numeric argument required", -1);
	else if (args[0] && args[1])
		return (err_msg("minishell: exit: too many arguments", NULL, NULL, -1));
	else if (args[0])
		handle_exit_option(args, &return_val);
	else
		return_val = 0;
	if (return_val < 0 || return_val > 255)
		return_val = (return_val % 256) + 256;
	free_data(data);
	return (err_msg("exit ", NULL, NULL, return_val));
}
