/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_read_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 18:38:38 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/29 20:10:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_IncreaseBuf(int position, char *buf)
{
	char	*temp;

	temp = buf;
	buf = (char *)malloc((sizeof(char) * MINISHELL_BUFFSIZE) * 2) + 1;
	buf[MINISHELL_BUFFSIZE * 2] = '\0';
	if (buf == NULL)
	{
		write (2, "Memory Allocation Failed!\n",26);
		exit(EXIT_FAILURE); 
	}
	else
	{
		ft_strcpy(buf, temp);
		free(temp);
	}
}

char		*ft_shell_read_line(void)
{
	int	position;
	char	currentChar;
	char	*buf;

	buf = (char *)malloc((sizeof(char) * MINISHELL_BUFFSIZE) + 1);
	buf[MINISHELL_BUFFSIZE] = '\0';
	position = 0;

	if (buf == NULL)
	{
		write (2, "memory allocation failed!\n", 26);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		currentChar = ft_get_char();
		if (currentChar == '\0' || currentChar == '\n')
			return (buf);
		else
			buf[position] = currentChar;
		position ++;
		if (position >= MINISHELL_BUFFSIZE)
			ft_IncreaseBuf(position, buf);
	}
}
