#ifndef SHELLGAME_SHELLGAME_H
# define SHELLGAME_SHELLGAME_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>

typedef enum e_colors
{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	RESET,
	ORANGE
}	t_color;

char	*color(t_color color);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);
char	*ft_itoa(int c);
char	*get_next_line(int fd);
#endif
