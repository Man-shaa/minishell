/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:49:30 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/29 18:18:48 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Determine si il faut concatener une variable d'environnement (s'il y a "+=")
// Si oui, effectue la concatenation
// Return 1 si la valeur de la variable dans t_envp a ete concatenee, sinon 0
int	is_concat(t_envp *node, char **tab)
{
	int		i;
	char	*tab_1;

	i = 0;
	tab_1 = ft_strdup(node->tab[1]);
	if (!tab_1)
		return (0);
	while (tab[0][i])
	{
		if (tab[0][i] == '+' && !tab[0][i + 1])
		{
			ft_free(node->tab[1]);
			node->tab[1] = ft_strjoin(tab_1, tab[1]);
			ft_free(tab_1);
			if (!node->tab[1])
				return (0);
			return (1);
		}
		i++;
	}
	ft_free(tab_1);
	return (0);
}

// parsing de ce la variable d'env que veut definir l'utilisateur
// Return 1 si c'est conforme, sinon 0 + msg d'erreur
int	is_valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum((int)str[i]))
			if (str[i] != '=' && (str[i] != '+' || str[i + 1] != '='))
				return (0);
		i++;		
	}
	return (1);
}

// Remplace la valeur d'uen variable dans t_envp si elle existe deja 
// et est redefinie par l'utilisateur
// Return 1 si tout s'est bien passe, sinon 0 (probleme de malloc strdup)
int	replace_value(t_envp *node, char *value)
{
	ft_free(node->tab[1]);
	node->tab[1] = ft_strdup(value);
	if (!node->tab[1])
		return (0);
	return (1);
}

