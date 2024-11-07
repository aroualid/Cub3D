/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:51:13 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/07 16:29:38 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


int	check_no(char *str, t_parse *parse, t_info *info)
{
	int	j;
	char *res;
	int	k;

	k = 0;
	j = 2;
	if (parse->info->no_ok == 1)
		return (printf("Error\n too many NO \n"), 0);
	res = ft_calloc(sizeof(char *), ft_strlen(str));
	parse->NO = ft_strdup(str);
	parse->info->no_ok = 1;
	while (j < ft_strlen(str))
	{
		res[k] = str[j];
		k++;
		j++;
	}
	j = skip_space(res);
	parse->info->no_path = ft_calloc(sizeof(char *), ft_strlen(res));
	k = 0;
	while (k < ft_strlen(res))
	{
		parse->info->no_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

