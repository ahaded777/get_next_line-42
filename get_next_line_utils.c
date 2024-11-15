/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/12 13:35:49 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/12 18:16:55 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// lkmala

int	ft_lkmala_machakil_ti9niya(int bytes_read, char **saved)
{
	if (bytes_read < 0)
	{
		free(*saved);
		*saved = NULL;
		return (0);
	}
	return (1);
}

///

char	*ft_strlcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*res;

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

void	ft_lkmala_lkmala(char **str, int i, char *temp)
{
	if (!str || !*str)
		return ;
	if ((*str)[i])
	{
		temp = ft_strdup(&((*str)[i]));
		if (!temp)
		{
			free(*str);
			*str = NULL;
			return ;
		}
		free(*str);
		*str = temp;
	}
	else
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_lkmala(char **str)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (!*str)
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *str, i + 1);
	temp = NULL;
	ft_lkmala_lkmala(&(*str), i, temp);
	return (line);
}
