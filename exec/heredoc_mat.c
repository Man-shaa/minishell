/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:56:39 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/13 17:04:06 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strcpy(char *str)
{
	int	i;
	char	*res;
	
	i = 0;
	if (!str)
		return (NULL);
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (i < (int)ft_strlen(str))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_tablen(char **tab)
{
	int	i;
	
	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**tabjoin(char **tab, char *str)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(ft_tablen(tab) + 2, sizeof(char *));
	if (!res)
		return (NULL);
	while (i < ft_tablen(tab))
	{
		res[i] = tab[i];
		i++;
	}
	res[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!res[i])
		return (NULL);
	while (j < (int)ft_strlen(str))
	{
		res[i][j] = str[j];
		j++;
	}
	res[i][j] = '\0';
	res[i + 1] = 0;
	free(tab);
	return (res);
}

char	**heredok(char *eof)
{
	char	*str;
	char	**tab;
	
	str = NULL;
	tab = NULL;
	while (42)
	{
		str = readline("> ");
		if (!str)
			return (NULL);
		if (is_same(str, eof))
			return (tab);
		tab = tabjoin(tab, str);
	}
	return (tab);
}