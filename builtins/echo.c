/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/21 16:04:26 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return 1 si l'option -n est trouvee dans str, sinon 0
int	is_option_n(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	while (str[i] && str[i] == 'n')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

// affiche chaque argument envoye a echo
// Return 0 si tout s'est bien passe, sinon 1 (malloc failed) 
int	echo_each_arg(char **args, int i)
{
	int		j;
	int		boule;
	char	**one;

	while (args[i])
	{
		boule = 0;
		one = ft_split_echo(args[i], ' ');
		if (!one)
			return (1);
		j = 0;
		while (one[j])
		{
			ft_putstr(one[j]);
			boule = 1;
			j++;
		}
		i++;
		free_tab(one);
		if (args[i] && boule == 1)
			write(STDOUT_FILENO, " ", 1);
	}
	return (0);
}

// Affiche tous les arguments encoyes a la fonction (args) et mets a jour
// g_return_val
int	ft_echo(char **args)
{
	int		i;
	int		boule;

	boule = 0;
	i = 0;
	while (args[i] && is_option_n(args[i]))
	{
		i++;
		boule = 1;
	}
	g_return_val = echo_each_arg(args, i);
	if (boule == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

char	**ft_split_echo(char	*str, char set)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(word_count_echo(str, set) + 1, sizeof(char *));
	if (!tab)
		return (ft_free(tab), NULL);
	while (j < word_count_echo(str, set))
	{
		tab[j] = ft_calloc(char_count_echo(str, set, j) + 1, 1);
		if (!tab[j])
			return (free_tab_split(tab, j), NULL);
		tab[j] = putword_echo(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
