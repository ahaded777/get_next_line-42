/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:35:49 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/12 18:16:55 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strlcpy(char *dest, char *src, int len)
{
    int i;

    i = 0;
	if (!dest && !src)
		return (NULL);
    while (src[i] && i < len)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

char	*ft_strdup(char *str)
{
    int     i;
    char    *res;

    i = 0;
	if (!str)
		return (NULL);
    res = malloc(ft_strlen(str) + 1);
    if (!res)
        return (NULL);
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char	*ft_lkmala(char **str)
{
    int     i;
    char    *line;
    char    *temp;

    i = 0;
    if (!*str)
        return (NULL);
    while ((*str)[i] && (*str)[i] != '\n')
        i++;
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    ft_strlcpy(line, *str, i + 1);
    if ((*str)[i] == '\n')
	{
        line[i] = '\n';
		i++;
	}
    line[i] = '\0';
    if ((*str)[i])
    {
        temp = ft_strdup(&((*str)[i]));
        free(*str);
        *str = temp;
    }
    else
	{
		free(*str);
        *str = NULL;
	}
    return (line);
}
