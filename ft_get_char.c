/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 07:35:14 by rmoswela          #+#    #+#             */
/*   Updated: 2016/08/03 07:38:04 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_get_char()
{
	char buffer;
	if (read (0, &buffer, 1) < 0)
		write (2, "Error has occured in the read\n", 30);
	return (buffer);
}
