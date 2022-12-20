/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:06:50 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/20 15:09:42 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_proc(t_data *data)
{
	data->proc = ft_calloc(1, sizeof(t_proc));
	if (!data->proc)
		return (0);
	data->proc->fd_in = 0;
	data->proc->fd_out = 0;
	data->proc->pid = -1
}

