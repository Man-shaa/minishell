/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/24 23:49:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Affiche le dossier dans lequel on est
void	print_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
	ft_free(buf);
}

void	replace_oldpwd_my_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	tmp = search_node(envp, "OLDPWD");
	if (!tmp)
		return ;
	if (tmp->tab[1])
		ft_free(tmp->tab[1]);
	tmp->tab[1] = ft_strdup(search_node(envp, "PWD")->tab[1]);
}

void	replace_pwd_my_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	replace_oldpwd_my_env(envp);
	tmp = search_node(envp, "PWD");
	if (!tmp)
		return ;
	if (tmp->tab[1])
		ft_free(tmp->tab[1]);
	tmp->tab[1] = getcwd(NULL, 0);
}