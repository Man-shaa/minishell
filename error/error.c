/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:19:29 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 15:57:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	err_msg(char *start, char *str, char *end, int fd)
{
	write(fd, start, ft_strlen(start));
	write(fd, str, ft_strlen(str));
	write(fd, end, ft_strlen(end));
}
