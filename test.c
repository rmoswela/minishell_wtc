/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:04:39 by rmoswela          #+#    #+#             */
/*   Updated: 2016/09/10 17:09:52 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//int		ft_strcmp(char *s1, char *s2);
char	ft_read_char()
{
	char buf;
	if (read (0, &buf, 1) < 0)
		write (1, "Error reading\n", 17);
	return (buf);
}
/*
char	*ft_store_buf()
{
	char read_char;
	int out_loop;
	int in_loop;
	char **buf_arr;

	buf_arr = (char **)malloc(sizeof(char *) + 1);
	out_loop = 0;
	in_loop = 0;
	//read_char = ft_read_char();
	while (buf_arr[out_loop])
	{
		read_char = ft_read_char();
		if (read_char != '\n')
		{
			return(buf_arr);
		}
		else
			buf_arr[out_loop] = ft_read_char();
		out_loop++;
	}
	return (0);
}*/
int	main()
{
	//char *argv = "reuben";
	char **input;
	char c;
	int loop_in;
	int loop_out;

	loop_in = 0;
	loop_out = 0;
	input = (char **)malloc(sizeof(char *)) + 1;
	while (1)//you are going to compare with last word
	{
		write (1, "heredoc> ", 9);
		/*input[loop_in][loop_out]*/c = ft_read_char();
		if (input[loop_in][loop_out] != '\n' || c != '\n')
		{
			if (loop_out == 0)
			{
				input[loop_in][loop_out] = c;
				loop_out++;
			}
			input[loop_in][loop_out] = ft_read_char();
			loop_out++;
		}
		loop_in++;
		//if (ft_strcmp(input, argv))
		//		break;
	}
	return 0;
}
