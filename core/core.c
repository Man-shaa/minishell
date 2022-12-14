/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/10 19:31:19 by mfroissa         ###   ########.fr       */
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
	if (data->proc)
		ft_free(data->proc->pid);
}

// Affiche un prompt different selon la valeur de retour precedente 
char	*get_readline(t_data *data, char *str)
{
	if (!data->return_val)
		str = readline("Manuo ✖✖ ");
	else
		str = readline("✖Manuo✖ ");
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
		if (!check_quotes(str))
			return (ft_putstr("quote is not closed\n"), get_prompt(envp));
		if (!ft_split(str, data))
			return (printf("problem : split unsuccesfull\n"), get_prompt(envp));
		if (!parsing(data))
			return (printf("problem : parsing\n"), get_prompt(envp));
		if (!get_cmd_struct(data))
			return (printf("problem : t_cmd\n"), free_data(data));
		if (!execution(data))
			return (printf("problem : execution\n"), free_data(data));
		reset_data(data, str);
	}
	free_data(data);
}
