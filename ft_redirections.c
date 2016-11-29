/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 10:17:04 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/24 01:53:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		create_file(char *filename)
{
	int	fd;

	if (access(filename, F_OK) != -1)
		fd = open (filename, O_WRONLY | O_TRUNC);
	else
		fd = open (filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRGRP);
	if (fd != -1)
		dup2 (fd, 1);
	else
	{
		write (2, "failed to open file\n", 21);
		exit (1);
	}
	if (close (fd) != 0)
	{
		write (2, "failed to close file\n", 22);
		exit (1);
	}
}

void		create_file_double(char *filename)
{
	int	fd;

	//printf("inside = %s\n", filename);

	if (access(filename, F_OK) != -1)
		fd = open (filename, O_WRONLY | O_APPEND);
	else
		fd = open (filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRGRP);
	//printf("fd = %d\n", fd);
	if (fd != -1)
		dup2 (fd, 1);
	else
	{
		write (2, "failed to open file\n", 21);
		exit (1);
	}
	//printf("close inside = %s\n", filename);
	if (close (fd) != 0)
	{
		write (2, "failed to close file\n", 22);
		exit (1);
	}
}

void		read_file (char *filename)
{
	int	fd;

	if (access(filename, F_OK) != -1)
		fd = open (filename, O_RDONLY);
	else
	{
		ft_perror ("No such file exists!\n");
		exit (1);
	}
	if (fd != -1)
		dup2(fd, 0);
	else
	{
		ft_perror("failed to open file!\n");
		exit (1);
	}
	if (close(fd) != 0)
	{
		ft_perror("failed to close file!\n");
		exit (1);
	}
}

void			ft_input_redirection(char *cmd_input)
{
	extern char	**environ;
	pid_t		pid;
	int		status;
	char		*path;
	char		**args;

	args = ft_strsplit(cmd_input, '<');
	pid = fork();
	if (pid == 0)
	{
		read_file(ft_strtrim(args[1]));
		args = ft_strsplit(args[0], ' ');
		path = ft_check_path(*args);
		if (execve(path, args, environ) == -1)
		{
			ft_perror("Error, execve input redirections failed!\n");
			exit (1);
		}
	}
	else if (pid == -1)
	{
		ft_perror("Error forking!\n");
		exit (1);
	}
	else
	{
		if ((pid = waitpid(pid, &status, 0) < 0))
			ft_perror("waitpid error!\n");
	}
}

void			ft_output_redirection(char *cmd_input)
{
	extern char	**environ;
	pid_t		pid;
	int		status;
	char		*path;
	char		**args;

	//memory needs freeing from strsplit
	args = ft_strsplit(cmd_input, '>');

	pid = fork();
	if (pid == 0)
	{
		//memory needs freeing from strtrim
		create_file(ft_strtrim(args[1]));
		//memory needs freeing from strsplit
		args = ft_strsplit(args[0], ' ');
		path = ft_check_path(*args);
		if (execve (path, args, environ) == -1)
		{
			ft_perror("Error, execve output redirections failed!\n");
			exit (1);
		}
	}
	else if (pid == -1)
	{
		ft_perror("Error forking!\n");
		exit(1);
	}
	else
	{
		if ((pid = waitpid(pid, &status, 0) < 0))
			ft_perror("waitpid error!\n");
	}
}

void			ft_double_output_redirect(char *cmd_input)
{
	extern char	**environ;
	pid_t		pid;
	int		status;
	int		loop;
	size_t		size;
	char		*path;
	char		**args;
	char		**copy_args;

	size = 0;
	loop = 0;
	//memory needs freeing from strsplit
	args = ft_strsplit(cmd_input, ' ');
	while (args[size] != '\0')
		size++;
	copy_args = (char **)malloc(sizeof(char *) * size + 1);
	size = 0;
	while (args[loop] != '\0')
	{
		if (ft_strcmp(args[loop], ">>") != 0)
		{
			copy_args[size] = ft_strdup(args[loop]);
			size++;
		}
		loop++;
	}
	copy_args[size] = "\0";
/*	loop = 0;
	while (ft_strcmp(copy_args[loop], "\0") != 0)
	{
		printf("testing = %s\n", copy_args[loop]);
		loop++;
	}*/
	pid = fork();
	if (pid == 0)
	{
		//memory needs freeing from strtrim
		//printf("%s\n", copy_args[size - 1]);
		create_file_double(copy_args[size - 1]);
		//printf("%s\n", copy_args[size - 1]);
		//memory needs freeing from strsplit
		//args = ft_strsplit(args[0], ' ');
		path = ft_check_path(*copy_args);
		//printf("path = %s\n", path);
		if (execve (path, copy_args, environ) == -1)
		{
			ft_perror("Error, execve output redirections failed!\n");
			exit (1);
		}
	}
	else if (pid == -1)
	{
		ft_perror("Error forking!\n");
		exit(1);
	}
	else
	{
		if ((pid = waitpid(pid, &status, 0) < 0))
			ft_perror("waitpid error!\n");
	}
}
