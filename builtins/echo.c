/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/18 14:41:11 by msharifi         ###   ########.fr       */
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
	char	**one;

	while (args[i])
	{
		one = ft_split_normal(args[i], ' ');
		if (!one)
			return (1);
		j = 0;
		while (one[j])
		{
			ft_putstr(one[j]);
			j++;
			if (one[j])
				write(STDOUT_FILENO, " ", 1);
		}
		i++;
		free_tab(one);
		if (args[i])
			write(STDOUT_FILENO, " ", 1);
	}
	return (0);
}

// Affiche tous les arguments encoyes a la fonction (args) et mets a jour
// data->return_val
void	ft_echo(t_data *data, char **args)
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
	data->return_val = echo_each_arg(args, i);
	if (boule == 0)
		write(STDOUT_FILENO, "\n", 1);
}
