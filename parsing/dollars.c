/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:24:48 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/14 19:35:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*replace_dollar(t_envp *envp, char *str)
{
	int		i;
	char	*res;
	t_envp	*env;

	i = 1;
	while (str[i] && !is_sep((int)str[i]))
		i++;
	res = ft_substr(str + 1, i - 1);
	if (!res)
		return (NULL);
	res = ignore_charset(res, "{}()", 1);
	env = search_node(envp, res);
	ft_free(res);
	if (!env)
		return (NULL);
	res = ft_strndup(env->tab[1], 0);
	if (!res)
		return (NULL);
	return (res);
}

char	*new_str(char *big_str, char *res, int *index)
{
	char	*new;
	char	*before;
	char	*after;
	size_t	i;

	i = *index;
	before = ft_strdup_until(big_str, *index);
	new = ft_strjoin(before, res);
	ft_free(before);
	if (res)
		ft_free(res);
	if (!new)
		return (NULL);
	before = ft_strndup(new, 0);
	if (!before)
		return (NULL);
	ft_free(new);
	i++;
	while (i < ft_strlen(big_str) && big_str[i] && !is_sep((int)big_str[i]))
		i++;
	after = ft_strndup(&big_str[i], 0);
	new = ft_strjoin(before, after);
	*index = ft_strlen(new) - ft_strlen(after) - 1;
	return (ft_free(before), ft_free(after), new);
}

void	handle_dollar(t_envp *envp, t_list *list)
{
	char	*res;
	int		dollar_count;
	int		i;

	i = 0;
	dollar_count = 0;
	if (!count_dollars(list->str))
		return ;
	while (i < (int)ft_strlen(list->str) && list->str[i])
	{
		if (list->str[i] == '$')
		{
			if (list->dollar[dollar_count] == 1)
			{
				res = replace_dollar(envp, &list->str[i]);
				res = new_str(list->str, res, &i);
				ft_free(list->str);
				list->str = res;
			}
			dollar_count++;
		}
		i++;
	}
}
