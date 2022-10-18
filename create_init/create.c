/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:16:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 23:02:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	*create_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd = NULL;
	data->list = NULL;
	return (data);
}

t_list	*add_to_list(t_data *data, char *str)
{
	data->list = add_last(data->list, str);
	if (!data->list)
		return (NULL);
	return (data->list);
}
