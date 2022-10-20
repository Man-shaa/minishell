/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:16:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/20 18:30:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Malloc et initialise a NULL la struct t_data
t_data	*create_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->envp = NULL;
	data->cmd = NULL;
	data->list = NULL;
	if (!create_env(data, envp))
		return (NULL);	
	return (data);
}

int	create_env(t_data *data, char **envp)
{
	t_envp	*env;
	int		i;
	int		env_lgt;

	env_lgt = env_lenght(envp);
	i = 0;
	env = data->envp;
	if (!*envp)
		return (0);
		// create_my_env()
	else
	{
		while (i < env_lgt)
		{
			env = add_last_env(data, envp[i]);
			i++;
		}
	}
	return(1);
}

// Ajouter le resulat du split dans la structure t_list
t_list	*add_to_list(t_data *data, char *str)
{
	data->list = add_last(data->list, str);
	if (!data->list)
		return (NULL);
	return (data->list);
}
