/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/12 13:47:30 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/12 16:48:19 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_lkmala(char **str);
int		ft_strlen(const char *str);
char	*ft_strchar(char *str, char c);
char	*ft_strlcpy(char *dest, char *src, int len);
int		ft_lkmala_machakil_ti9niya(int bytes_read, char *saved);

#endif
