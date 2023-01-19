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

static size_t	count_len(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (*s != c && *s)
	{
		s++;
		j++;
	}
	return (j);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	size_t	word;

	i = 0;
	cnt = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			cnt = 0;
		else if (s[i] != c && cnt == 0)
		{
			word++;
			cnt = 1;
		}
		i++;
	}
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	size_t	j;
	size_t	k;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		k = 0;
		while (*s == c && *s)
			s++;
		if (*s)
		{
			tab[j] = malloc(sizeof(**tab) * (count_len(s, c) + 1));
			while (*s != c && *s != '\0' && tab[j])
				tab[j][k++] = *s++;
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

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
int	ft_atoi_error(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][0] == '+' || av[j][0] == '-' ) && i == 0)
				i++;
			if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		j++;
	}
	return (1);
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
	{
		str = (char *)ft_calloc(sizeof(char), 1);
		str[0] = '\0';
	}
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

int parsing(int ac, char **av)
{
	static char *str;
	int i;
	if(ac <= 1)
		return 0;
	i = 1;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	if (!ft_atoi_error(ft_split(str, ' ')))
		return 0;
	return 1;
}