/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:37 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 18:13:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

int	word_count_normal(char *str, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (j);
}

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
			if (j == pos)
				k++;
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (k);
}

char	*putword_normal(char *str, char *tab, char set, int pos)
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
			if (j == pos)
			{
				tab[k] = str[i];
				k++;
			}
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

void	free_tab_split(char **tab, int i)
{
	int	j;

	j = 0;
	while (i < j)
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
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
	tab = ft_calloc(word_count_normal(str, set) + 1, sizeof(char *));
	if (!tab)
		return (ft_free(tab), NULL);
	while (j < word_count_normal(str, set))
	{
		tab[j] = ft_calloc(char_count_normal(str, set, j) + 1, 1);
		if (!tab[j])
			return (free_tab_split(tab, j), NULL);
		tab[j] = putword_normal(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
