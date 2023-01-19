#include "push_swap.h"

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