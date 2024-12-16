/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archemi <archemi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:23:53 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/16 08:14:27 by archemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int		check_newline(char *str);
void	*ft_free(void *ptr);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);

char	*read_file(int fd, char *str);
char	*ft_get_line(char *str);
char	*shift_line(char *str);
char	*get_next_line(int fd);

#endif