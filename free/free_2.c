/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:06:10 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/08 18:36:11 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//free un **tab  jusqu'a n
void	free_tab_n(char **tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < n)
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	ft_free(void *addr)
{
	if (addr)
		free(addr);
	addr = NULL;
}

// Free tab jussqu'a last
void	free_int_tab(int **tab, int last)
{
	int	i;

	i = 0;
	if (!tab || last <= 0)
		return ;
	while (i < last + 1)
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
	tab = NULL;
}

void	free_proc(t_proc *proc)
{
	if (proc->pid)
		ft_free(proc->pid);
	if (proc->pipe_fd)
		free_int_tab(proc->pipe_fd, proc->n_pipes);
	ft_free(proc);
}

// Free tout t_data sauf les variables dans t_proc
void	free_data_proc(t_data *data)
{
	if (!data)
		return ;
	if (data->list)
		free_list(data->list);
	if (data->cmd)
		free_cmd(data->cmd);
	if (data->envp)
		free_envp(data->envp);
	if (data->proc)
		ft_free(data->proc);
	ft_free(data);
	// rl_clear_history();
}
