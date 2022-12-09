/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:19:29 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/09 17:32:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	err_msg(char *start, char *str, char *end, int fd)
{
	if (start)
		write(fd, start, ft_strlen(start));
	if (str)
		write(fd, str, ft_strlen(str));
	if (end)
		write(fd, end, ft_strlen(end));
	write(2, "\n", 1);
}
