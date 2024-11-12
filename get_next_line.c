/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:34:09 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/12 17:14:42 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (-1);
    while (str[i])
        i++;
    return (i);
}

char *ft_strchar(char *str, char c)
{
    int i;
    
    i = 0;
    while (str && str[i])
    {
        if (str[i] == c)
            return (str + i);
        i++;
    }
    if (c == '\0')
        return (str + i);
    return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *res;
    
    i = 0;
    j = 0;
    if (!s1 && !s2)
        return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";	
    res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (NULL); 
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    static char *saved;
    char        *line;
    char        *temp;
    char        buffer[BUFFER_SIZE + 1];
    int         bytes_read;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || write(1, 0, 0) == -1)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchar(saved, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(saved);
            saved = NULL;
            return (NULL);
        }
        if (bytes_read == 0)
            break;   
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(saved, buffer);
        free(saved);
        saved = temp;
    }
    if (!saved || !*saved)
		return (NULL);
    line = ft_lkmala(&saved);
    return (line);
}


