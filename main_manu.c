/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/02 18:58:31 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

// Quand export [VAR]=  le split tej le '=' donc pas moyen d'afficher juste "VAR="
// Comment gerer echo $(pwd), echo ${PWD}, bref echo d'une variable d'env ????

// echo $(pwd)
// echo $PWD
// echo ${PWD}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	char	*str;

	str = ft_strndup("$PWD", 0);
	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	echo(data, str);
	free_data(data);
	return (0);
}
