#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	result;

	if (!str)
		return (0);
	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

int	lenght_count(char *str1, char *str2)
{
	int	len;

	if (!str1)
		str1 = "";
	len = 0;
	if (str1 && str2)
		len = ft_strlen(str1) + ft_strlen(str2) + 1;
	return (len);
}

char	*ft_strjoin(char *prefstr, char *sufstr)
{
	char	*addstr;
	int		lenght;
	char	*result;

	lenght = lenght_count(prefstr, sufstr);
	addstr = (char *) malloc(sizeof(char) * lenght);
	if (!addstr)
		return (0);
	result = addstr;
	if (prefstr)
		while (*prefstr)
			*addstr++ = *prefstr++;
	while (*sufstr)
	{
		*addstr = *sufstr;
		addstr++;
		if (*sufstr == '\n')
			break ;
		else
			sufstr++;
	}
	*addstr = '\0';
	return (result);
}

char	*ft_strchr(char *string, int i)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == (char)i)
			return (string + index);
		index++;
	}
	if ((char)i == '\0')
		return (string + index);
	return (NULL);
}

void	*ft_memmove(void *destin, const void *source, size_t lenght)
{
	size_t			i;
	unsigned char	*temps;
	unsigned char	*tempd;

	i = 0;
	temps = (unsigned char *)source;
	tempd = (unsigned char *)destin;
	if (!destin && !source)
		return (0);
	if (temps > tempd)
	{
		while (lenght--)
		{
			tempd[i] = temps[i];
			i++;
		}
	}
	else
		while (lenght--)
			tempd[lenght] = temps[lenght];
	return (tempd);
}
