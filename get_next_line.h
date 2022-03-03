#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*saved_free(char **saved);
char	*break_pointer_check(char *newline, char **saved, char *break_pointer);
char	*no_break_pointer_check(char *newline, char *saved);
char	*saved_checking_null(char *saved, int fd);
void	*ft_memmove(void *destin, const void *source, size_t lenght);
char	*ft_strchr(char *string, int i);
char	*ft_strjoin(char *prefstr, char *sufstr);
int		lenght_count(char *str1, char *str2);
int		ft_strlen(char *str);

#endif
