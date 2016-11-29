/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:43:08 by rmoswela          #+#    #+#             */
/*   Updated: 2016/08/06 06:12:04 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
    if (str == NULL)
        return (NULL);
    ft_strcat(str, s1);
    ft_strcat(str, s2);
    return (str);
}
