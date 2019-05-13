/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_gnl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 18:13:24 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/16 18:13:25 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include "get_next_line.h"

#define PRINT_ALL -2

int		call_gnl(int fd, int print_times)
{
	char *line;
	int	ret;
	int i;

	i = 0;
	line = NULL;
	clock_t begin = clock();
	if (print_times == PRINT_ALL)
	{
		while ((ret = get_next_line(fd, &line)))
		{
			printf("line %d: return value: %d| %s\n",
			i, ret, line);
			free(line);
			i++;
		}
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\033[36mtime:%f\n\033[0m", time_spent);
	}
	else
	{
		while (i <= print_times)
		{
			ret = get_next_line(fd, &line);
			printf("line %d: return value: %d| %s\n",
			i, ret, line);
			free(line);
			i++;
		}
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\033[36mtime:%f\n\033[0m", time_spent);
	}
	return (0);
}

void	peace_and_war()
{
	int	fd;

	fd = open("war_and_peace.c", O_RDONLY);
	if (fd < 0)
	{
		perror("war_and_peace: ");
		return ;
	}
	call_gnl(fd, PRINT_ALL);
}

void	simple_test()
{
	int	fd;

	fd = open("simple_test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("simple_test ");
		return ;
	}
	printf("\n\033[01;37m-----Simple test with 2 new lines in the end-------\n\n\033[0m");
	call_gnl(fd, 5);
	close(fd);
}

void	simple_test_nl()
{
	int	fd;

	fd = open("simple_test_nl.c", O_RDONLY);
	if (fd < 0)
	{
		perror("simple_test_nl ");
		return ;
	}
	printf("\033[01;37m\n-----Simple test WITH new line in the end-------\n\n\033[0m");
	call_gnl(fd, 6);
	close(fd);
}

void	empty_file()
{
	int	fd;

	fd = open("empty_file2.c", O_RDONLY);
	if (fd < 0)
	{
		perror("empty_file ");
		return ;
	}
	printf("\n-----Empty_file-------\n\n");
	call_gnl(fd, 3);
}

void	two_lines()
{
	int	fd;

	fd = open("simple_test.c", O_RDONLY);
	if (fd < 0)
	{
		perror("simple_test.c");
		return ;
	}
	printf("\033[01;37m\n-----2 lines 8 chars without Line Feed-------\n\n\033[0m");
	call_gnl(fd, 5);
	close(fd);
}

void	new_line()
{
	int	fd;

	fd = open("empty_file.c", O_RDONLY);
	if (fd < 0)
	{
		perror("empty_file ");
		return ;
	}
	printf("\n-----Just 3 new lines-------\n\n");
	call_gnl(fd, 4);
}

int		main()
{
	short int i;

	printf("\n\033[33m1) Simple test 6 lines. New line at 1, 5, 6 line\n");
	printf("2) Simple test.txt 5 lines. With new line at 1, 4, 5 \n");
	printf("3) Huge text. War and peace\n");
	printf("4) Empty file\n");
	printf("5) 2 lines 8 chars without Line Feed\n\033[0m");
	printf("6) Just 3 new lines\n\033[0m");

	scanf("%hd", &i);
	if (i == 1)
		simple_test_nl();
	else if (i == 2)
		simple_test();
	else if (i == 3)
		peace_and_war();
	else if (i == 4)
		empty_file();
	else if (i == 5)
		two_lines();
	else if (i == 6)
		new_line();
	else
		printf("Error. Enter only one number\n");
	return (0);
}