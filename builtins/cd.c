/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:07:52 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/07 15:47:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// changer oldpwd et pwd avec replace...

int	ft_cd(t_data *data, char *str)
{
	(void)data;
	str = getcwd(NULL, 0);
	printf("AVANT : %s\n", str);
	chdir("../../../../../../../../../../../..");
	ft_free(str);
	str = getcwd(NULL, 0);
	printf("APRES : %s\n", str);
	ft_free(str);
	return (0);
}
