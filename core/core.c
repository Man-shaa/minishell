/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/23 15:04:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Reset les donnees necessaire a chaque nouveau prompt
void	reset_data(t_data *data, char *str)
{
	ft_free(str);
	if (data->list)
	{
		free_list(data->list);
		data->list = NULL;
	}
	if (data->cmd)
	{
		free_cmd(data->cmd);
		data->cmd = NULL;
	}
}

// Affiche un prompt different selon la valeur de retour precedente 
char	*get_readline(t_data *data, char *str)
{
	if (!data->return_val)
		str = readline("Manuo ✖✖ ");
	else
		str = readline("✖ Manuo ✖ ");
	if (!str)
		return (rl_clear_history(), ft_exit(data, NULL), NULL);
	add_history(str);
	return (str);
}

// Cree data, affiche un prompt et execute les commandes recues
void	get_prompt(char **envp)
{
	char	*str;
	t_data	*data;

	data = create_data(envp);
	str = NULL;
	while (42)
	{
		str = get_readline(data, str);
		if (!str)
			return ;
		ft_split(str, data);
		if (!parsing(data))
			return ;
		get_cmd_struct(data);
		if (!execution(data))
			return (free_data(data));
		reset_data(data, str);
	}
	free_data(data);
}
