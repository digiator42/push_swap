#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum { false, true } bool;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	parsing(int ac, char **av);
long int	ft_atoi(char *ptr);
char	*ft_strjoin(char *str, char *av);
char	**ft_split(char *s, char c);


#endif