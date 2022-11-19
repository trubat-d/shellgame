#include "shellgame.h"

#define WORD_LEN 5
#define MAX_TRIES 5

int	compare_words(char *word1, char *word2)
{
	int	i = 0;
	int j = 0;
	int	*tab;
	int	diff = 0;

	tab = calloc(5, sizeof(int));
	while (word1[i])
	{
		j = 0;
		while (word2[j])
		{
			if (word1[i] == word2[j] && !tab[j])
			{
				tab[j] = 1;
				diff++;
				break ;
			}
			j++;
		}
		i++;
	}
	fflush(0);
	free(tab);
	return (diff);
}

int	compare_list(char *word, char **word_list)
{
	int i = 0;

	if (!word)
		return 0;
	while (word_list[i])
	{
		if (compare_words(word_list[i], word) == WORD_LEN)
			break ;
		i++;
	}
	if (!word_list[i])
		return (0);
	return (1);
}

char	random_char_gen(void)
{
	char	*list = "!@#&(){}[]:;',?/*`~$^+=<>\"\\";
	int		random = rand() % 27;
	return (list[random]);
}

char	*random_char_list(char **word_list)
{
	static int	tab;
	char		*res;
	int			i = 0;
	int			j = 0;
	int			random = rand() % 4;

	if (tab >= 20)
		tab = 0;
	res = calloc(4 + WORD_LEN, sizeof(char));
	while (i < 3 + WORD_LEN)
	{
		if (i >= random && j < WORD_LEN)
			res[i] = word_list[tab][j++];
		else
			res[i] = random_char_gen();
		i++;
	}
	tab++;
	return (res);
}

char	**gen_word_list(int fd)
{
	char	**res;

	res = calloc(501, sizeof(char *));
	for (int i = 0; i < 500; i++)
	{
		res[i] = get_next_line(fd);
	}
	return (res);
}

char	**get_word_list(char **word_list)
{
	char	**res;
	int		random;

	res = calloc(21, sizeof(char *));
	for (int i = 0; i < 20; i++)
	{
		random = rand() % 500;
		res[i] = word_list[random];
	}
	return (res);
}

char	*gen_password(char **word_list)
{
	int random = rand() % 20;
	return (word_list[random]);
}

void	ft_putstr_dlay(char *str)
{
	int	i = 0;
	while (str[i])
	{
//		usleep(10000);
		printf("%c", str[i]);
		fflush(0);
		i++;
	}
}

void printer(char *address_base, int fd, char **word_list, int i)
{
	char	*address;
	char	*list;

	address = ft_strjoin(address_base, ft_itoa(50 + i));
	printf("%s", color(GREEN));
	ft_putstr_dlay(address);
	list = random_char_list(fd, word_list);
	ft_putstr_dlay("\t");
	ft_putstr_dlay(list);
	ft_putstr_dlay("\t");
	address = ft_strjoin(address_base, ft_itoa(50 + i + 10));
	ft_putstr_dlay(address);
	ft_putstr_dlay("\t");
	list = random_char_list(fd, word_list);
	ft_putstr_dlay(list);
	printf("%s\n", color(RESET));
}

int	main(void)
{
	char	*address_base;
	char	*input;
	int		fd = open("words.txt", O_RDONLY);
	char	**general_list;
	char	**word_list;
	char	*password;
	int		diffs;
	int		tries = 0;

	srand(time(NULL));
	general_list = gen_word_list(fd);
	while (1)
	{
		srand(time(NULL));
		word_list = get_word_list(general_list);
		password = gen_password(word_list);
//		printf("Password is : %s\n", password);
		address_base = "0x42-L";
		printf("%sEnter the right Password in the list%s\n\n", color(ORANGE), color(RESET));
		for (int i = 0; i < 10; i++)
			printer(address_base, fd, word_list, i);
		printf("\n");
		while (1)
		{
			input = 0;
			while (1)
			{
				printf("%sEnter your answer : %s", color(GREEN), color(RESET));
				fflush(0);
				input = get_next_line(0);
				if (ft_strlen(input) != WORD_LEN + 1)
				{
					printf("%sWord must be in the list !%s\n", color(RED), color(RESET));
					fflush(0);
					continue ;
				}
				input[5] = 0;
				if (!compare_list(input, word_list))
				{
					printf("%sWord must be in the list !%s\n", color(RED), color(RESET));
					fflush(0);
				}
				else
					break ;
			}
			diffs = compare_words(input, password);
			if (diffs == WORD_LEN)
			{
				printf("%sYou are now ready to enter !%s\n", color(PURPLE), color(RESET));
				close(fd);
				return (0);
			}
			else
			{
				if (tries == MAX_TRIES - 2)
					printf("%sCare ! this is your last attempt%s\n", color(RED), color(RESET));
				printf("%sSimilar characters to password : %d/%d%s\n", color(PURPLE), diffs, WORD_LEN, color(RESET));
				tries++;
			}
			if (tries == MAX_TRIES)
			{
				system("@cls||clear");
				printf("%sERROR ! ERROR ! The system has changed \nthe password for security purposes%s\n", color(RED), color(RESET));
				break ;
			}
		}
	}
}
