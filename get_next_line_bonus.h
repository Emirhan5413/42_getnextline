#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int		check_nl(char *str);
void	*ft_free(void *ptr);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

char	*read_file(int fd, char *str);
char	*ft_get_line(char *str);
char	*shift_line(char *str);
char	*get_next_line(int fd);

#endif