/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:24:48 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 17:33:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Replace $? par lla valeur de retour
// Return la chaine de caractere modifiee;
char	*replace_ret_val(char *str, int index)
{
	char	*res;
	char	*before;
	char	*after;
	char	*ret;

	ret = ft_itoa(g_return_val);
	if (!ret)
		return (str);
	before = ft_strdup_until(str, index);
	res = ft_strjoin(before, ret);
	ft_free(before);
	ft_free(ret);
	if (!res)
		return (err_msg("Malloc failed", NULL, NULL, 1), str);
	before = ft_strndup(res, 0);
	ft_free(res);
	after = ft_strndup(&str[index + 2], 0);
	res = ft_strjoin(before, after);
	if (!res)
		return (err_msg("Malloc failed", NULL, NULL, 1), str);
	ft_free(before);
	ft_free(after);
	return (res);
}

// Replace les variables d'env par leur valeur
// Return la chaine de caractere modifiee
char	*replace_dollar(t_envp *envp, char *big_str, int *index)
{
	int		i;
	char	*res;
	char	*str;
	char	*after;
	t_envp	*env;

	str = &big_str[*index];
	i = 1;
	while (str[i] && !is_sep((int)str[i]))
		i++;
	res = ft_substr(str + 1, i - 1);
	res = ignore_charset(res, "{}", 1);
	env = search_node(envp, res);
	ft_free(res);
	if (!env)
	{
		res = ft_strdup_until(big_str, *index);
		after = ft_strndup(&big_str[i + (*index)], 0);
		str = ft_strjoin(res, after);
		return ((*index)--, ft_free(res), ft_free(after), str);
	}
	res = ft_strndup(env->tab[1], 0);
	if (!res)
		return (NULL);
	return (new_str(big_str, res, index));
}

// Return la nouvelle chaine de caractere apres replace_dollar
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

// Gere tous les dollars recus en ligne de commande
void	handle_dollar(t_data *data, t_list *list)
{
	char	*res;
	int		dollar_count;
	int		i;

	i = 0;
	dollar_count = 0;
	while (i < (int)ft_strlen(list->str) && list->str[i])
	{
		if (list->str[i] == '$')
		{
			if (list->dollar[dollar_count] == 1)
			{
				if (list->str[i + 1] == '?')
					res = replace_ret_val(list->str, i);
				else
					res = replace_dollar(data->envp, list->str, &i);
				ft_free(list->str);
				list->str = res;
			}
			dollar_count++;
		}
		i++;
	}
}
