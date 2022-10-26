/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:59 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/26 17:04:47 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	unset(t_envp *envp, char *str)
{
	t_envp	*before;
	t_envp	*node;

	if (!str || !str[0])
		return ;
	before = envp;
	node = search_node(envp, str);
	if (!node)
		return ;
	while (before->next && !ft_strcmp(before->next->tab[0], str))
		before = before->next;
	before->next = node->next;
	free_tab(node->tab);
}
