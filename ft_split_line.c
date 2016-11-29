/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 16:32:13 by rmoswela          #+#    #+#             */
/*   Updated: 2016/07/10 13:06:55 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_words(char const *s, char c)
{
    int		i;
    size_t	size;
    
    i = 0;
    size = 0;
    while (s[i] && s[i] == c)
        i++;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            while (s[i] && s[i] != c)
                i++;
            size++;
        }
    }
    return (size);
}

char			**ft_split_line(char *line, char c)
{
    char	**tab;
    size_t	size;
    int		i;
    int		start;
    
    if (!line || !(tab = (char **)malloc(sizeof(char *) * (ft_words(line, c) + 1))))
        return (0);
    i = 0;
    size = 0;
    while (line[i])
    {
        if (line[i] == c)
            i++;
        else
        {
            start = i;
            while (line[i] && line[i] != c)
                i++;
            tab[size++] = ft_strsub(line, start, i - start);
        }
    }
    tab[size] = 0;
    return (tab);
}
