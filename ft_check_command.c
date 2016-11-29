/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 15:32:52 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/29 21:03:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_check_command(char *str)
{
	char	*arg_path;
	char	*appended_path;
	char	*path;
	char	**split_path;

	path = ft_check_path();
	split_path = ft_strsplit(path, ':');
	while (*split_path != '\0')
	{
		appended_path = ft_strjoin(*split_path, "/");
		arg_path = ft_strjoin(appended_path, str);
		if (access(arg_path, F_OK) == 0)
			return (arg_path);
		split_path++;
	}
	write (2, "Command is not found!\n", 22);
	return (0);
}
