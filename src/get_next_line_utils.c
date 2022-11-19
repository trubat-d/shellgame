#include "get_next_line.h"
#include "shellgame.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	if ((unsigned char)c == 0)
		return (&ptr[ft_strlen(ptr)]);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (0);
}
