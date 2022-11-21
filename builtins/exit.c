/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:04:26 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 17:59:38 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_exit(t_data *data, char **args)
{
	int		return_val;

	if (!args)
		return_val = 0;
	err_msg("exit \n", NULL, NULL, 2);
	free_data(data);
	return (return_val);
}
