/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:07:52 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/07 17:49:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// changer oldpwd et pwd avec replace...

int	cd(t_data *data, char *str)
{
	(void)data;
	str = getcwd(NULL, 0);
	printf("AVANT : %s\n", str);
	chdir("../../../../../../../../../../../..");
	ft_free(str);
	str = getcwd(NULL, 0);
	printf("APRES : %s\n", str);
	ft_free(str);
	return (1);
}
