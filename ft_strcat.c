/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:44:56 by rmoswela          #+#    #+#             */
/*   Updated: 2016/07/10 17:45:01 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcat(char *str1, const char *str2)
{
    int i;
    int len;
    
    len = ft_strlen(str1);
    i = 0;
    while (str2[i] != '\0')
    {
        str1[len + i] = str2[i];
        i++;
    }
    str1[len + i] = '\0';
    return (str1);
}
