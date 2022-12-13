/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:27:16 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/13 16:27:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return 1 si l'affichage de la variable d'environnement a reussi, sinon 0
int	ft_putstr_echo(t_data *data, char **str, int i)
{
	int	j;

	j = 0;
	while (str[i][j])
	{
		if (str[i][j] == '$')
		{
			if (!echo_env_var(data, str, i, j))
				return (0);
			while (str[i][j] && str[i][j] != ' ')
				j++;
		}
		else
		{
			write(1, &str[i][j], 1);
			j++;
		}
	}
	return (1);
}

// Cherche la variable d'env correspondant a args[i] sans "${}()" et la print
// si elle existe, sinon ne print rien
// Return 1 si la variable d'environnement existe, sinon 0
int	echo_env_var(t_data *data, char **args, int i, int j)
{
	char	*res;
	t_envp	*node;

	if (is_same(args[i], "$?"))
		ft_putnbr(data->return_val);
	else
	{
		res = ignore_charset(&args[i][j], "$(){}", 0);
		node = data->envp;
		node = search_node(data->envp, res);
		if (res)
			ft_free(res);
		if (!node)
			return (0);
		ft_putstr(node->tab[1]);
	}
	return (1);
}

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