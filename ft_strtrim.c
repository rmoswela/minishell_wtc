/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 07:55:34 by rmoswela          #+#    #+#             */
/*   Updated: 2016/08/09 11:14:03 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtrim(char *str)
{
	size_t len;
	int i, j;
	size_t str_len;
	str_len = ft_strlen(str);
	char *trim_str;
	i = 0;
	j = 0;
	trim_str = (char *)malloc(sizeof(char) * str_len);
	if (trim_str == NULL)
		return NULL;
	else
	{
		while (str[i] == 32 || str[i] == 10 || str[i] == 9)
			i++;
		while (str[i] != '\0')
			trim_str[j++] = str[i++];
		trim_str[j] = '\0';
		len = ft_strlen(trim_str) - 1;
		while (trim_str[len] == 32 || trim_str[len] == 9 || trim_str[len] == 10)
			len--;
		trim_str[len + 1] = '\0';
		return (trim_str);
	}
	return (0);
}
