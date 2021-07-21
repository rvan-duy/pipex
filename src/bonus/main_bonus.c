/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:15:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 15:38:48 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "handle_processes_bonus.h"
#include "utilities_bonus.h"
#include "libft.h"

static void	check_argument_count(int argc)
{
	if (argc < 5)
		error_and_exit("Usage: ./pipex <infile> \
<cmd1> <cmd2> ... <cmdn> <outfile>");
}

static int	**create_pipes(int pipes_amount_needed)
{
	int	i;
	int	**pipefds;

	pipefds = ft_calloc(pipes_amount_needed + 1, sizeof(int *));
	if (pipefds == NULL)
		error_and_exit("Failed to allocate memory.");
	i = 0;
	while (i < pipes_amount_needed)
	{
		pipefds[i] = ft_calloc(2, sizeof(int));
		if (pipefds[i] == NULL)
			error_and_exit("Failed to allocate memory.");
		if (pipe(pipefds[i]) == -1)
		{
			ft_putendl_fd("Error", 2);
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipefds);
}

int	main(int argc, char **argv, char **envp)
{
	int							**pipefds;
	t_command_line_arguments	arg;

	arg.argument_count = argc;
	arg.argument_vector = argv;
	arg.enviroment_variables = envp;
	check_argument_count(arg.argument_count);
	pipefds = create_pipes(arg.argument_count - 1);
	handle_processes(&arg, pipefds);
	ft_array_free((void **)pipefds, ft_array_len((void **)pipefds));
	return (EXIT_SUCCESS);
}
