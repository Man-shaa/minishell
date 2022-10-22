/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:01:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/22 20:28:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	word_count_normal(char *str, char set)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && str[i] == set)
// 			i++;
// 		while (str[i] && str[i] != set)
// 		{
// 			if (str[i + 1] == set || str[i + 1] == '\0')
// 				j++;
// 			i++;
// 		}
// 	}
// 	return (j);
// }

int	char_count_normal(char *str, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (pos == 0)
			{
				if (j == pos)
					k++;
			}
			else if (pos == 1)
			{
				if (j >= pos)
					k++;
			}
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (k);
}

char	*ft_putword(char *str, char *tab, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (pos == 0)
			{
				if (j == pos)
				{
					tab[k] = str[i];
					k++;
				}
			}
			else if (pos == 1)
			{
				if (j >= pos)
				{
					tab[k] = str[i];
					k++;
				}
			}
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

char	**ft_split_normal(char	*str, char set)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char *), 3);
	if (!tab)
		return (ft_free(tab), NULL);
	while (j < 2)
	{
		tab[j] = ft_calloc(1, char_count_normal(str, set, j) + 1);
		if (!tab[j])
			return (free_tab(tab), NULL);
		tab[j] = ft_putword(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
