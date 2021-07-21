/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:35:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 12:32:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute_command_bonus.h"
#include "read_and_error_check_command.h"
#include "utilities.h"

#include <stdio.h>
#include "libft.h"

void	execute_first_command(int **pipefds, char **argv, char **envp)
{
	int		file_descriptor;
	char	**command;

	file_descriptor = open_file_with_read_permissions(argv[IN_FILE]);
	command = read_and_error_check_command(argv[COMMAND_1], envp);
	dup_fd(pipefds[1][WRITE_PIPE], STDOUT_FILENO);
	dup_fd(file_descriptor, STDIN_FILENO);
	execve(command[0], (char *const *)command, envp);
}

void	execute_final_command(int pipefds[2], char **argv, char **envp)
{
	int		file_descriptor;
	char	**command;

	close_fd(pipefds[WRITE_PIPE]);
	file_descriptor = open_file_with_write_permissions(argv[OUT_FILE]);
	command = read_and_error_check_command(argv[COMMNAD_2], envp);
	dup_fd(pipefds[READ_PIPE], STDIN_FILENO);
	dup_fd(file_descriptor, STDOUT_FILENO);
	execve(command[0], (char *const *)command, envp);
	close_fd(file_descriptor);
	close_fd(pipefds[READ_PIPE]);
}

void	execute_middle_command(int pipefds[2], char *argv, char **envp)
{
	char	**command;
	pid_t	pid;

	command = read_and_error_check_command(argv, envp);
	dup_fd(pipefds[READ_PIPE], STDIN_FILENO);
	dup_fd(pipefds[WRITE_PIPE], STDOUT_FILENO);
	pid = fork_process();
	if (pid == 0)
	{
		execve(command[0], (char *const *)command, envp);
	}
	ft_putendl_fd("Hello", 2);
	close_fd(pipefds[WRITE_PIPE]);
	waitpid(pid, NULL, 0);
}

#include <stdio.h>

void	execute_next_command(int read_pipe, int write_pipe, \
								char *argv, char **envp)
{
	char	**command;

	command = read_and_error_check_command(argv, envp);
	dup_fd(read_pipe, STDIN_FILENO);
    close_fd(read_pipe);
	dup_fd(write_pipe, STDOUT_FILENO);
    close_fd(write_pipe);
	execve(command[0], (char *const *)command, envp);
}
