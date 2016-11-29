/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 19:51:16 by rmoswela          #+#    #+#             */
/*   Updated: 2016/09/04 22:13:22 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//process is something in which a program executes
void	ft_execute(char *str, char **args)
{
	pid_t 		pid;
	int 		status;
	extern char	**environ;

	//returns 0 for the child and child pid for parent
	//if fork fails it returns error to parent as not child is created
	//its essential for parent to know child pid as it can wait, kill
	//child has to use getppid to know parent process
	pid = fork();
	if (pid == 0)
	{
		//child
		if (execve(str, args, environ) == -1)
		{
			ft_perror("Error, execve failed!\n");
			exit(1);
		}
	}
	else if (pid == -1)
	{
		//error
		ft_perror("Error forking!\n");
		exit(1);
	}
	else
	{
		//parent
		if ((pid = waitpid(pid, &status, 0)) < 0)
			ft_perror("waitpid error!\n");
	}
}
