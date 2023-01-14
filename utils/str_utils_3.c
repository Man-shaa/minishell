/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:04:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/14 16:15:28 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_substr(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc(n + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

int	is_sep(int a)
{
	if (!ft_isalpha(a) && ft_strchr("{}()", a))
		return (1);
	return (0);
}

char	*ft_strdup_until(char *str, int n)
{
	int		i;
	char	*dup;

	i = 0;
	if (n <= 0)
		return (NULL);
	dup = ft_calloc(n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
