/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_heredoc_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/23 10:17:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/24 11:17:58 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_heredoc_bonus.h"
#include "execute_command_bonus.h"
#include "utilities_bonus.h"
#include "libft.h"

void	exit_get_next_line_error(int ret, const char *limiter, char *line)
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

void	read_heredoc(t_command_line_arguments *arg, int **pipefds)
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
	exit(EXIT_SUCCESS);
}

void	handle_heredoc(t_command_line_arguments *arg, int **pipefds)
{
	// int		i;
	// pid_t	pid;
	// int		outfile;

	read_heredoc(arg, pipefds);
	// i = 0;
}
