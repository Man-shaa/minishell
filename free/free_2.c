/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:06:10 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/16 15:46:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free(void *addr)
{
	if (addr)
		free(addr);
	addr = NULL;
}

void	free_int_tab(int **tab, int last)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < last + 1)
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_proc(t_proc *proc)
{
	if (proc->pid)
		ft_free(proc->pid);
	if (proc->pipe_fd)
		free_int_tab(proc->pipe_fd, proc->n_pipes + 1);
	ft_free(proc);
}
