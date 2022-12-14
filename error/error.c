/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:19:29 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/14 15:38:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	err_msg(char *start, char *str, char *end)
{
	if (start)
		write(STDERR_FILENO, start, ft_strlen(start));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	if (end)
		write(STDERR_FILENO, end, ft_strlen(end));
	write(STDERR_FILENO, "\n", 1);
}
