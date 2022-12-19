/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:04:26 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 13:12:38 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// history
// "echo $dsdg(pas dans env) hello" met un espace avant hello (qui devrait pas)

int	ft_exit(t_data *data, char **args)
{
	int		return_val;

	if (!args)
		return_val = 0;
	else if (args[0] && args[1])
		return_val = 1; //msg erreur too many machin
	else if (args[0])
		return_val = ft_atoi(args[0]);
	else
		return_val = 0;
	free_data(data);
	return (err_msg("exit ", NULL, NULL, return_val));
}
