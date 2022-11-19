#include "shellgame.h"

char	*color(t_color color)
{
	switch (color)
	{
		case BLACK:
			return ("\033[0;30m");
		case RED:
			return ("\033[0;31m");
		case GREEN:
			return ("\033[0;32m");
		case YELLOW:
			return ("\033[0;33m");
		case BLUE:
			return ("\033[0;34m");
		case PURPLE:
			return ("\033[0;35m");
		case CYAN:
			return ("\033[0;36m");
		case WHITE:
			return ("\033[0;37m");
		case RESET:
			return ("\033[0m");
		case ORANGE:
			return ("\033[38;5;208m");
	}
	return ("");
}
