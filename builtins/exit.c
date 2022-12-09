/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:04:26 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/09 17:33:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_exit(t_data *data, char **args)
{
	int		return_val;

	if (args[0] && args[1])
		return_val = 1; //msg erreur too many machin
	else if (args[0])
		return_val = ft_atoi(args[0]);
	else
		return_val = 0;
	err_msg("exit ", NULL, NULL, 2);
	free_data(data);
	return (return_val);
}
