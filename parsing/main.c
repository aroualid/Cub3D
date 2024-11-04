/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:01 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/04 14:38:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_line(char *file)
{
	char	*str;
	int		infile;
	int		i;

	i = 0;
	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	while (str)
	{
		i++;
		free (str);
		str = get_next_line(infile);
	}
	close (infile);
	free(str);
	return (i);
}

int main(int ac, char **av)
{
	int		fd;
	char	*str;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		str = get_next_line(fd);
		int i = 0;
		while (i < get_line(av[1]))
		{
			printf("%s", str);
			free (str);
			str = get_next_line(fd);
			i++;
		}
		close (fd);
		free (str);
	}
	else
	{
		printf("Error \nWrong number of arg\n");
		return (0);
	}
	return (0);
}
