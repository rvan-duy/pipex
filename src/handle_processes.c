/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 17:35:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/04 14:29:29 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_processes.h"
#include "execute_command.h"
#include "utilities.h"

void	handle_processes(char **argv, int pipefds[2], char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork_process();
	pid2 = 0;
	if (pid1 == CHILD_PROCESS)
		execute_first_command(pipefds, argv, envp);
	else
	{
		pid2 = fork_process();
		if (pid2 == CHILD_PROCESS)
			execute_second_command(pipefds, argv, envp);
	}
	close_fd(pipefds[READ_PIPE]);
	close_fd(pipefds[WRITE_PIPE]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
