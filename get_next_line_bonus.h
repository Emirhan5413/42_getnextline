/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:45:33 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/21 16:58:30 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>

int		check_newline(char *str);
void	*ft_free(void *ptr);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

char	*ft_read_file(int fd, char *str);
char	*ft_get_line(char *str);
char	*ft_shift_line(char *str);
char	*get_next_line(int fd);

#endif