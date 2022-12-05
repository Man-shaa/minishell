/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/05 17:04:12 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)

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

// Cherche la variable d'env correspondant a args[i] sans "${}()" et la print
// si elle existe, sinon ne print rien
void	echo_env_var(t_data *data, char **args, int i)
{
	char	*res;
	t_envp	*node;

	res = ignore_charset(args[i], "$(){}", 0);
	node = data->envp;
	node = search_node(data->envp, res);
	if (res)
		ft_free(res);
	if (!node)
		return ;
	ft_putstr(node->tab[1]);
}

void	ft_echo(t_data *data, char **args)
{
	int		i;
	int		boule;

	boule = 0;
	i = 0;
	if (!args)
		return ;
	while (args[i] && is_option_n(args[i]))
	{
		i++;
		boule = 1;
	}
	while (args[i])
	{
		if (args[i][0] != '$')
			ft_putstr(args[i]);
		else
			echo_env_var(data, args, i);
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (boule == 0)
		write(1, "\n", 1);
}
