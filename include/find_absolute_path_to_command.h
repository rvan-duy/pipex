/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_absolute_path_to_command.h                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:36:22 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/07 10:33:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_ABSOLUTE_PATH_TO_COMMAND_H
# define FIND_ABSOLUTE_PATH_TO_COMMAND_H

# define ABSOLUTE_COMMAND '/'

char	*find_absolute_path_to_command(char *command, char **envp);

#endif