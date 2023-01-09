/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:59 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/09 17:48:54 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Retire les node du tableau de string args dans t_envp s'ils existent,
// sinon ne fait rien
void	ft_unset(t_data *data, char **args)
{
	int		i;
	t_envp	*before;
	t_envp	*node;

	i = 0;
	if (!args || !args[0])
		return ;
	while (args[i])
	{
		before = data->envp;
		node = search_node(data->envp, args[i]);
		if (node)
		{
			while (before->next && !ft_strcmp(before->next->tab[0], args[i]))
				before = before->next;
			if (!before->next)
				data->envp = node->next;
			else
				before->next = node->next;
			free_tab(node->tab);
			ft_free(node);
		}
		i++;
	}
}
