/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:15:58 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/15 15:16:02 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h> 
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

char	*find_full_path(char *cmd, char **env);
int		open_file(char *path, int in_out);

#endif