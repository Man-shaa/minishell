/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:01:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/14 18:42:33 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	first_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

int	char_count_env(char *str, char set, int pos)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (pos == 0)
		return (first_sep(str, set));
	i = first_sep(str, set);
	while (str[i])
	{
		i++;
		k++;
	}
	return (k);
}

char	*ft_putword_env(char *str, char *tab, char set, int pos)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	if (pos == 0)
	{
		while (++i < first_sep(str, set))
		{
			tab[k] = str[i];
			k++;
		}
	}
	else
	{
		i = first_sep(str, set);
		while (str[i++])
		{
			tab[k] = str[i];
			k++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

char	**ft_split_env(char	*str, char set)
{
	// int		i;
	int		j;
	char	**tab;

	// i = 0;
	j = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char *), 3);
	if (!tab)
		return (NULL);
	while (j < 2)
	{
		tab[j] = ft_calloc(1, char_count_env(str, set, j) + 1);
		if (!tab[j])
			return (free_tab(tab), NULL);
		tab[j] = ft_putword_env(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
