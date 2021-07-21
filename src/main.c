/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/17 16:19:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/18 11:28:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_processes.h"
#include "utilities.h"
#include "libft.h"

static void	check_argument_count(int argc)
{
	if (argc != 5)
		error_and_exit("Usage: ./pipex <infile> \
<cmd1> <cmd2> <outfile>");
}

static void	create_pipe(int pipefds[2])
{
	if (pipe(pipefds) == -1)
	{
		ft_putendl_fd("Error", 2);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefds[2];

	check_argument_count(argc);
	create_pipe(pipefds);
	handle_processes(argv, pipefds, envp);
	return (EXIT_SUCCESS);
}
