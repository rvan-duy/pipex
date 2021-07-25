/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_heredoc_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/23 10:17:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/24 19:11:20 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_heredoc_bonus.h"
#include "execute_command_bonus.h"
#include "utilities_bonus.h"
#include "libft.h"

static void	execute_heredoc_child_processes(t_command_line_arguments *arg, \
								int command_index, int **pipefds, int outfile)
{
	const int	last_command_index = 1;

	if (command_index == last_command_index)
		dup_fd(outfile, pipefds[command_index + 1][WRITE_PIPE]);
	close_fd(outfile);
	close_other_fds(pipefds, pipefds[command_index][READ_PIPE], \
		pipefds[command_index + 1][WRITE_PIPE]);
	execute_next_command(pipefds[command_index][READ_PIPE], \
		pipefds[command_index + 1][WRITE_PIPE], \
			arg->argument_vector[command_index + 3], arg->enviroment_variables);
}

static void	exit_get_next_line_error(int ret, const char *limiter, char *line)
{
	if (line != NULL)
		free(line);
	if (ret == 0)
	{
		ft_putstr_fd("Warning: here-document delimited by end-of-file", 2);
		ft_putstr_fd(" (wanted '", 2);
		ft_putstr_fd(limiter, 2);
		ft_putendl_fd("')", 2);
		exit(EXIT_FAILURE);
	}
	else if (ret < 0)
		error_and_exit("Get_next_line failed.");
}

static void	read_heredoc(t_command_line_arguments *arg, int **pipefds)
{
	const char	*limiter = arg->argument_vector[2];
	bool		found_limiter;
	char		*line;
	int			ret;

	ret = 1;
	found_limiter = false;
	while (found_limiter == false)
	{
		ft_putstr_fd("> ", 1);
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret <= 0)
			exit_get_next_line_error(ret, limiter, line);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
			write(pipefds[0][WRITE_PIPE], line, ft_strlen(line));
		else
			found_limiter = true;
		free(line);
	}
}

static void	close_heredoc_everything(int outfile, int **pipefds)
{
	close_fd(outfile);
	close_all_fds(pipefds);
}

void	handle_heredoc(t_command_line_arguments *arg, int **pipefds)
{
	const int	command_count = 2;
	const int	out_index = 5;
	int			i;
	pid_t		pid;
	int			outfile;

	read_heredoc(arg, pipefds);
	outfile = open_file_with_write_permissions(arg->argument_vector[out_index]);
	i = 0;
	while (i < command_count)
	{
		pid = fork_process();
		if (pid == CHILD_PROCESS)
			execute_heredoc_child_processes(arg, i, pipefds, outfile);
		i++;
	}
	close_heredoc_everything(outfile, pipefds);
	wait(NULL);
	wait(NULL);
}
