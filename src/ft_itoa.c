#include "shellgame.h"
#include <stdlib.h>

static int	num_size(int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	int		i;
	int		size;
	char	*result;
	int		is_neg;

	is_neg = c < 0;
	size = num_size(c) + is_neg;
	result = malloc(size * sizeof(char) + 1);
	if (!result)
		return (0);
	result[size] = '\0';
	if (c == 0)
	{
		result[0] = '0';
		return (result);
	}
	i = size - 1;
	while (i >= is_neg)
	{
		result[i--] = (((is_neg) * (-1) + !(is_neg)) * (c % 10)) + '0';
		c /= 10;
	}
	if (is_neg)
		result[0] = '-';
	return (result);
}
