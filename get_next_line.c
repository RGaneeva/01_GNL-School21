#include "get_next_line.h"

char	*saved_checking_null(char *saved, int fd)
{
	int	read_rslt;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		  return (0);
	if (saved == NULL)
	{
		saved = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!saved)
			return (0);
		read_rslt = read(fd, saved, BUFFER_SIZE);
		if (read_rslt == 0)
		{
			free(saved);
			saved = NULL;
			return (NULL);
		}
		saved[read_rslt] = '\0';
	}
	return (saved);
}

char	*no_break_pointer_check(char *newline, char *saved)
{
	char	*temp;

	temp = newline;
	newline = ft_strjoin(newline, saved);
	free (temp);
	return (newline);
}

char	*break_pointer_check(char *newline, char **saved, char *break_pointer)
{
	char	*temp;

	break_pointer++;
	temp = newline;
	newline = ft_strjoin(newline, *saved);
	free (temp);
	ft_memmove(*saved, break_pointer, (ft_strlen(break_pointer) + 1));
	if (*(saved[0]) == 0)
	{
		free(*saved);
		*saved = NULL;
	}
	return (newline);
}

char	*saved_free(char **saved)
{
	free(*saved);
	*saved = NULL;
	return (*saved);
}

char	*get_next_line(int fd)
{
	char		*break_pointer;
	char		*newline;
	static char	*saved;

	newline = NULL;
	saved = saved_checking_null(saved, fd);
	while (saved)
	{
		break_pointer = ft_strchr(saved, '\n');
		if (!break_pointer)
			newline = no_break_pointer_check(newline, saved);
		else
		{
			newline = break_pointer_check(newline, &saved, break_pointer);
			return (newline);
		}
		saved[read(fd, saved, BUFFER_SIZE)] = '\0';
		if (saved[0] == 0)
		{
			saved = saved_free(&saved);
			return (newline);
		}
	}
	return (newline);
}
