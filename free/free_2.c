/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:06:10 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/30 16:22:55 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	if (proc->pipe_fd)
		free_int_tab(proc->pipe_fd, proc->n_pipes + 1);
	ft_free(proc);
}
