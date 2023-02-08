/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/08 16:55:28 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Reset les donnees necessaire a chaque nouveau prompt
void	reset_data(t_data *data, char *str)
{
	t_envp	*tmp;

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
	{
		free_int_tab(data->proc->pipe_fd, data->proc->n_pipes);
		ft_free(data->proc->pid);
	}
	tmp = search_node(data->envp, "PATH");
	if (tmp)
		data->env_path = tmp->tab[1];
	else
		data->env_path = NULL;
}

// Affiche un prompt different selon la valeur de retour precedente 
char	*get_readline(t_data *data, char *str)
{
	if (!g_return_val)
		str = readline("Manuo ✖✖ ");
	else
		str = readline("✖Manuo✖ ");
	if (!str)
	{
		rl_clear_history();
		free_data_proc(data);
		write(STDERR_FILENO, "exit\n", 5);
		exit(127);
	}
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
		if (!check_quotes(str, 0))
			return (free_data_proc(data), get_prompt(envp));
		if (!ft_split(str, data))
			return (printf("problem: split unsuccesfull\n"), get_prompt(envp));
		if (!parsing(data))
		{
			free_data_proc(data);
			get_prompt(envp);
		}
		if (!get_cmd_struct(data))
			get_prompt(envp);
		print_struct_cmd(data);
		if (!execution(data))
			return (printf("problem: execution\n"), free_data(data));
		reset_data(data, str);
	}
}
