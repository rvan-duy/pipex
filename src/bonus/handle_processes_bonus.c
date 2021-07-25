/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:20:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/24 18:42:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_processes_bonus.h"
#include "execute_command_bonus.h"
#include "utilities_bonus.h"
#include "libft.h"

static void	execute_child_process(t_command_line_arguments *arg, \
						int command_index, int **pipefds, int *files)
{
	const int	command_count = ft_array_len((void**)arg->argument_vector) - 3;
	const int	first_command_index = 0;
	const int	last_command_index = command_count - 1;

	if (command_index == first_command_index)
		dup_fd(files[0], pipefds[command_index][READ_PIPE]);
	else if (command_index == last_command_index)
		dup_fd(files[1], pipefds[command_index + 1][WRITE_PIPE]);
	close_fd(files[0]);
	close_fd(files[1]);
	close_other_fds(pipefds, pipefds[command_index][READ_PIPE], \
		pipefds[command_index + 1][WRITE_PIPE]);
	execute_next_command(pipefds[command_index][READ_PIPE], \
		pipefds[command_index + 1][WRITE_PIPE], \
			arg->argument_vector[command_index + 2], arg->enviroment_variables);
}

static void	open_files(int *files, char **argv, int argc)
{
	const int	in_file = 1;
	const int	out_file = argc - 1;

	files[0] = open_file_with_read_permissions(argv[in_file]);
	files[1] = open_file_with_write_permissions(argv[out_file]);
}

static void	close_everything(int *files, int **pipefds)
{
	close_fd(files[0]);
	close_fd(files[1]);
	close_all_fds(pipefds);
}

static void	wait_for_all_processes(int command_count)
{
	int	i;

	i = 0;
	while (i < command_count)
	{
		wait(NULL);
		i++;
	}
}

void	handle_processes(t_command_line_arguments *arg, int **pipefds)
{
	const int	command_count = arg->argument_count - 3;
	int			i;
	pid_t		pid;
	int			files[2];

	open_files(files, arg->argument_vector, arg->argument_count);
	i = 0;
	while (i < command_count)
	{
		pid = fork_process();
		if (pid == CHILD_PROCESS)
			execute_child_process(arg, i, pipefds, files);
		i++;
	}
	close_everything(files, pipefds);
	wait_for_all_processes(command_count);
}
