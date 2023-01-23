#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;

	if (c)
	{
		while (c[i] != '\0')
			i++;
	}
	else
		return (0);
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int is_space(char *str)
{
	int i = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 14))
		i++;
	if(str[i] == '\0')
		return 0;
	return 1;		
}

long int ft_atoi(char *str)
{
	int	i;
	int sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 14))
		i++;	
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	return (res * sign);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char *str, char *av)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!str)
		str = (char *)ft_calloc(sizeof(char), 1);
	if (!av)
		return (NULL);
	joined = (char *)malloc((ft_strlen(str) + ft_strlen(av) + 2));
	if (!joined)
		return (NULL);
	while (str[i])
		joined[j++] = str[i++];
	i = 0;
	while (av[i])
		joined[j++] = av[i++];
	joined[j] = ' ';
	joined[j+1] = '\0';
	if(str[0])
		free(str);
	str = NULL;
	return (joined);
}
