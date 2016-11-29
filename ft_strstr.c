/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:26:47 by rmoswela          #+#    #+#             */
/*   Updated: 2016/09/04 23:52:50 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strstr(char *src, char *sub)
{
	size_t i;
	if (*sub == '\0')
		return (src);
	while (*src)
	{
		i = 0;
		while (src[i] == sub[i])
		{
			if (sub[i + 1] == '\0')
				return (src);
			i++;
		}
		src++;
	}
	return (0);
}
