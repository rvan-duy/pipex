/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/20 00:17:36 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/26 22:17:16 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities_bonus.h"
#include "libft.h"

void	close_fd(int fd)
{
	if (close(fd) < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": Close (fd: ", 2);
		ft_putnbr_fd(fd, 2);
		ft_putendl_fd(")", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_and_exit(char *message)
{
	if (message)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
	exit(EXIT_FAILURE);
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("Error", 2);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	open_file_with_read_permissions(char *argv)
{
	int	file_descriptor;

	file_descriptor = open(argv, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	return (file_descriptor);
}

int	open_file_with_write_permissions(char *argv)
{
	int	file_descriptor;

	file_descriptor = open(argv, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (file_descriptor == -1)
	{
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	return (file_descriptor);
}
