/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:47:50 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/15 10:48:57 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

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
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *str, i + 1);
	temp = NULL;
	ft_lkmala_lkmala(&(*str), i, temp);
	return (line);
}
