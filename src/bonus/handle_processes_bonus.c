/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:20:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 13:26:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_processes_bonus.h"
#include "execute_command_bonus.h"
#include "utilities_bonus.h"

#include <stdio.h>
#include <stdlib.h>

void	handle_processes(int argc, char **argv, int **pipefds, char **envp)
{
	int			i;
	pid_t		pid;
	int         files[2];
	const int	command_count = argc - 3;
	const int   in_file = 1;
	const int   out_file = argc - 1;
	const int   first_command = 0;
	const int   last_command = command_count - 1;

	files[0] = open_file_with_read_permissions(argv[in_file]);
	files[1] = open_file_with_write_permissions(argv[out_file]);
	i = 0;
	//dprintf(2, "MAIN PROCESS PID:%d\n", getpid());
	while (i < command_count)
	{
		pid = fork_process();
		if (pid == CHILD_PROCESS)
		{
			//dprintf(2, "CHILD PID:%d\n", getpid());
			if (i == first_command)
				dup_fd(files[0], pipefds[i][READ_PIPE]);
			else if (i == last_command)
				dup_fd(files[1], pipefds[i + 1][WRITE_PIPE]);
			close_fd(files[0]);
			close_fd(files[1]);
			close_other_fds(pipefds, pipefds[i][READ_PIPE], pipefds[i + 1][WRITE_PIPE]);
			execute_next_command(pipefds[i][READ_PIPE], pipefds[i + 1][WRITE_PIPE], \
									argv[i + 2], envp);
		}
		i++;
	}
	close_fd(files[0]);
	close_fd(files[1]);
	close_all_fds(pipefds);
	i = 0;
	while (i < command_count)
	{
		wait(NULL);
		i++;
	}
}

// void	handle_first_command(int **pipefds, char **argv, char **envp)
// {
// 	pid_t	pid;

// 	pid = fork_process();
// 	if (pid == CHILD_PROCESS)
// 	{
// 		close_other_fds(pipefds, pipefds[0][0], pipefds[1][1]);
// 		execute_first_command(pipefds, argv, envp);
// 		close_all_fds(pipefds);
// 	}
// 	waitpid(pid, NULL, 0);
// }

// void	handle_processes(int argc, char **argv, int **pipefds, char **envp)
// {
// 	int		i;
// 	int		j;
// 	pid_t	pid;

// 	handle_first_command(pipefds, argv, envp);
// 	i = 3;
// 	j = 1;
// 	printf("Main process pid: %d\n", getpid());
// 	while (i < argc - 1)
// 	{
// 		pid = fork_process();
// 		printf("two processes %d\n", pid);
// 		if (pid == CHILD_PROCESS)
// 		{
// 			printf("Start of child process..\n");
// 			close_other_fds(pipefds, pipefds[j][READ_PIPE],
// 			 				 pipefds[j + 1][WRITE_PIPE]);
// 			dprintf(2, "using: %d and %d\n", pipefds[j][READ_PIPE], pipefds[j + 1][WRITE_PIPE]);
// 			execute_next_command(pipefds[j][READ_PIPE],
// 				pipefds[j + 1][WRITE_PIPE], argv[i], envp);
// 		}
// 		else
// 		{
// 			dprintf(2, "Closing.. %d pid: %d\n", pipefds[j][READ_PIPE], getpid());
// 			dprintf(2, "Closing.. %d pid: %d\n", pipefds[j + 1][WRITE_PIPE], getpid());
// 			close(pipefds[j][READ_PIPE]);
// 			close(pipefds[j + 1][WRITE_PIPE]);
// 		}
// 		i++;
// 		j++;
// 	}
// 	printf("hi\n");
// 	close_all_fds(pipefds);
// 	wait(NULL);
// }
