/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:01 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/07 16:24:35 by aroualid         ###   ########.fr       */
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

void check_id(char *str, t_parse *parse)
{

	if (ft_strncmp(str, "NO ", 3) == 0)
		check_no(str, parse,parse->info);
	if (ft_strncmp(str, "SO ", 3) == 0)
	{
		parse->SO = ft_strdup(str);
		parse->info->no_ok = 1;
	}
	if (ft_strncmp(str, "WE ", 3) == 0)
	{
		parse->WE = ft_strdup(str);
		parse->info->we_ok = 1;
	}
	if (ft_strncmp(str, "EA ", 3) == 0)
	{
		parse->EA = ft_strdup(str);
		parse->info->ea_ok = 1;
	}
	if (ft_strncmp(str, "F ", 2) == 0)
		parse->F = ft_strdup(str);
	if (ft_strncmp(str, "C ", 2) == 0)
		parse->C = ft_strdup(str);
}

int main(int ac, char **av)
{
	int		fd;
	t_parse *parse;

	parse = malloc(sizeof(t_parse));
	parse->info = malloc(sizeof(t_info));

	if (ac == 2)
	{
		parse->lines = ft_calloc(sizeof(char **), get_line(av[1]));
		fd = open(av[1], O_RDONLY);
		int i = 0;
		int j;
		int	k = 0;
		while (i < get_line(av[1]))
		{
			parse->lines[i] = get_next_line(fd);
			j = skip_space(parse->lines[i]);
			parse->temp = ft_calloc(sizeof(char *), ft_strlen(parse->lines[i]));
			while (k < ft_strlen(parse->lines[i]))
			{
				parse->temp[k] = parse->lines[i][j];
				k++;
				j++;
			}
			check_id(parse->temp, parse);
			parse->temp = NULL;
			free (parse->temp);
			free(parse->lines[i]);
			k = 0;
			i++;
		}
		close (fd);
		
		printf("NO = %s\n", parse->info->no_path);
		printf("SO = %s\n", parse->SO);
		printf("WE = %s\n", parse->WE);
		printf("EA = %s\n", parse->EA);
		printf("F = %s\n", parse->F);
		printf("C = %s\n", parse->C);
	}
	else
	{
		printf("Error \nWrong number of arg\n");
		return (0);
	}
	return (0);
}
