/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:59 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/18 21:45:37 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	unset_option(t_data *data, char *arg)
{
	t_envp	*before;
	t_envp	*node;

	before = data->envp;
	node = search_node(data->envp, arg);
	if (node)
	{
		while (before->next && !ft_strcmp(before->next->tab[0], arg))
			before = before->next;
		if (!before->next)
			data->envp = node->next;
		else
			before->next = node->next;
		free_tab(node->tab);
		ft_free(node);
	}
}

// Retire les node du tableau de string args dans t_envp s'ils existent,
// sinon ne fait rien
int	ft_unset(t_data *data, char **args)
{
	int		i;

	i = 0;
	if (!args || !args[0])
		return (0);
	while (args[i])
	{
		unset_option(data, args[i]);
		i++;
	}
	return (0);
}
