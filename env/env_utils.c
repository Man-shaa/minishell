/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/22 18:19:54 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	env_lenght(char **envp)
{
	int	i;

	i = 0;
	if (!*envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

t_envp	*ft_lstnew_env(char *str)
{
	t_envp	*new;

	new = ft_calloc(1, sizeof(t_envp));
	if (!new)
		return (0);
	new->tab = ft_split_normal(str, '=');
	new->next = NULL;
	return (new);
}

int	add_last_env(t_data *data, char *str)
{
	t_envp	*last;
	t_envp	*tmp;

	tmp = data->envp;
	last = ft_lstnew_env(str);
	if (!last)
		return (0);
	if (!data->envp)
	{
		data->envp = last;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	return (1);
}
