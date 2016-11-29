/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:02:36 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/29 19:54:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_handleSetenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
		ft_setenv(args[1], args[2], args[3]);
	else if (args[2] == NULL)
		ft_val_setenv(args[1]);
}

void		ft_handleExecution(char **args)
{
	char 	*path;

	path = ft_check_path(*args);
	ft_execute(path, args);
}

void		ft_handleArgs(char **args, char *line)
{
	args = ft_strsplit(line, ' ');
	if (ft_strcmp(*args, "exit") == 0)
		exit(0);
	else if (ft_strcmp(*args, "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(*args, "cd") == 0)
		ft_change_dir(args);
	else if (ft_strcmp (args[0], "setenv") == 0)
		ft_handleSetenv(args);
	else if (ft_strcmp(*args, "unsetenv") == 0)
		ft_unsetenv(args[1]);
	else if (ft_strstr(line, "<<") != NULL)
		ft_putendl("double <<");
	else if (ft_strstr(line, ">>") != NULL)
		ft_double_output_redirect(line);
	else if (ft_check_char(line, '>') == 0)
		ft_output_redirection(line);
	else if (ft_check_char(line, '<') == 0)
		ft_input_redirection(line);
	else
		ft_handleExecution(args);
}

int		main(void)
{
	char		*line;
	char		*nul_line;
	char		**args;
	extern	char	**environ;
	char		**my_env;

	while (1)
	{
		write (1, "minishell$> ", 12);
		line = ft_shell_read_line();
		nul_line = ft_strtrim(line);
		if (ft_strlen(nul_line) > 0)
		{
			args = ft_strsplit(line, ' ');
			ft_handleArgs(args, line);
		}
	}
	return (0);
}
