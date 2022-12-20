/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:16:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/20 20:30:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Malloc et initialise a NULL la struct t_data
// Return pointeur sur data si la creation a reussie, sinon NULL
t_data	*create_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->return_val = 0;
	data->env_path = NULL;
	data->cmd = NULL;
	data->list = NULL;
	data->envp = NULL;
	if (!create_env(data, envp))
		return (free_data(data), NULL);
	data->proc = create_proc();
	if (!data->proc)
		return (free_data(data), NULL);
	return (data);
}
