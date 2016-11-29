/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 11:50:32 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/29 21:05:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//function to check for environment
char			*my_getenv(char *path_name)
{
	int		loop;
	extern char	**environ;

	loop = -1;
	//iterate throught environ to check for environ name given
	//comparing with those in environ using string length
	while (environ[++loop] != '\0')
		if (ft_strncmp(environ[loop], path_name, ft_strlen(path_name)) == 0)
			return (&environ[loop][ft_strlen(path_name) + 1]);
	return (0);
}
//functionn to check for if given command is available
//in the environment
char		*ft_check_path(char *arg)
{
	size_t	loop;
	char	*path;
	char	**path_split;

	loop = 0;
	//check if arg avail using access funtion
	if (access(arg, F_OK) == 0)
		return (arg);
	//get the environment path and split it using delimiters
	path = my_getenv("PATH");
	path_split = ft_strsplit(path, ':');
	//append backslash and arg to path variable to make absolute path
	//then check if arg is avail in environ using created absolute path
	while (path_split[loop] != '\0')
	{
		path = ft_strjoin(path_split[loop], "/");
		path = ft_strjoin(path, arg);
		if (access(path, F_OK) == 0)
			return (path);
		loop++;
	}
	return 0;
}

/**int	main()
{
	char *cmd_name = ft_check_path("pwd");
	printf("mine: %s\n", my_getenv("PATH"));
	printf("%s\n", cmd_name);
	return 0;
}*/
