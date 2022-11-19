#include "../includes/shellgame.h"

int main(void)
{
	int fd = open("words.txt", O_RDONLY);
	int fd2 = open("words2.txt", O_WRONLY);
	char *line;
	while ((line = get_next_line(fd)) != 0)
	{
		if (ft_strlen(line) == 6)
			write(fd2, line, ft_strlen(line));
	}
	return (0);
}