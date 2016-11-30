/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 00:36:15 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/30 02:29:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

void		ft_unsetenv (char *name)
{
	char	**my_env;
	size_t	loop;
	size_t	size;

	size = 0;
	while (environ[size] != '\0')
		size++;
	my_env = (char **)malloc(sizeof(char *) * size + 1);
	loop = 0;
	while (environ[loop] != '\0')
	{
		if (ft_strncmp(environ[loop], name, ft_strlen(name)) != 0)
		{
			my_env[loop] = ft_strdup(environ[loop]);
		}
		loop++;
	}
	environ = my_env;
	//free(my_env);
}

char	**ft_env ()
{
	size_t		loop;
	char		**my_env;
	size_t		size_of_env;

	loop = 0;
	size_of_env = 0;
	while (environ[size_of_env] != '\0')
		size_of_env++;
	my_env = (char **)malloc(sizeof(char *) * (size_of_env + 2));
	while (environ[loop] != '\0')
	{
		my_env[loop] = ft_strdup(environ[loop]);
		loop++;
	}
	return (my_env);
}

void	ft_val_setenv (char *name)
{
	char		**my_env;
	size_t		loop;

	my_env = ft_env();
	loop = 0;
	while (environ[loop] != '\0')
		loop++;
	my_env[loop] = name;
	environ = my_env;
}

void		ft_loopSetenv(char *name, char *value,\
	       	char **my_env, char *overwrite, int loop)
{
	char	**str;

	//printf("%d", ft_strlen(name));
	str = ft_strsplit(my_env[loop], '=');
	ft_bzero (str[1], ft_strlen(str[1]));
	str[0] = ft_strjoin(str[0], "=");
	my_env[loop] = ft_strjoin(str[0], value);
	//printf("%s\n", my_env[loop]);
	environ = my_env;
	return;
}

void		ft_setenv (char *name, char *value, char *overwrite)
{
	char	**my_env;
	size_t	loop;

	my_env = ft_env();
	loop = 0;
	while (environ[loop] != '\0')
	{
		if (ft_strncmp(my_env[loop], name, ft_strlen(name)) == 0 \
			       	&& overwrite != 0)
			ft_loopSetenv(name, value, my_env, overwrite, loop);
		else if (ft_strncmp(environ[loop], name, ft_strlen(name)) == 0 \
			       	&& overwrite == 0)
		{
			my_env[loop] = environ[loop];
			environ = my_env;
			return;
		}
		loop++;
	}
	my_env[loop] = ft_strjoin(name, "=");
	my_env[loop] = ft_strjoin(my_env[loop], value);
	environ = my_env;
}
