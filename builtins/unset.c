/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:59 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 18:22:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Retire le node str dans t_envp s'il existe, sinon ne fait rien
void	ft_unset(t_data *data, char *str)
{
	t_envp	*before;
	t_envp	*node;

	if (!str || !str[0])
		return ;
	before = data->envp;
	node = search_node(data->envp, str);
	if (!node)
		return ;
	while (before->next && !ft_strcmp(before->next->tab[0], str))
		before = before->next;
	if (!before->next)
		data->envp = node->next;
	else
		before->next = node->next;
	free_tab(node->tab);
	ft_free(node);
}
