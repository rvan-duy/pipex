/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 10:34:40 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/27 10:37:26 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities_bonus.h"
#include "libft.h"

int	open_tmp_file(char *name)
{
	int	file_descriptor;

	file_descriptor = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_descriptor == -1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	return (file_descriptor);
}
