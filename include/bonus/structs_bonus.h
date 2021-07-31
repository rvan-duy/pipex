/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/21 15:24:45 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/31 17:03:50 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <stdbool.h>

typedef struct s_command_line_arguments {
	int		argument_count;
	char	**argument_vector;
	char	**enviroment_variables;
}	t_command_line_arguments;

#endif