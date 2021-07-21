/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/23 16:03:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/18 12:14:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute_command.h"
#include "read_and_error_check_command.h"
#include "utilities.h"

void	execute_first_command(int pipefds[2], char **argv, char **envp)
{
	int		file_descriptor;
	char	**command;

	close_fd(pipefds[READ_PIPE]);
	file_descriptor = open_file_with_read_permissions(argv[IN_FILE]);
	command = read_and_error_check_command(argv[COMMAND_1], envp);
	dup_fd(pipefds[WRITE_PIPE], STDOUT_FILENO);
	dup_fd(file_descriptor, STDIN_FILENO);
	execve(command[0], (char *const *)command, envp);
	close_fd(file_descriptor);
	close_fd(pipefds[WRITE_PIPE]);
}

void	execute_second_command(int pipefds[2], char **argv, char **envp)
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
