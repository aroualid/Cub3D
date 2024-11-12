/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:07 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/12 18:57:35 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_f(char *str, t_parse *parse, t_info *info)
{
	int	j;
	char *res;
	int	k;
	int i;

	k = 0;
	j = 1;
	if (parse->info->f_ok == 1)
		return (printf("Error\ntoo many NO \n"), 0);
	res = new_string(str, 2);
	parse->info->f_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->f_color = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
	{
		parse->info->f_color[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

int	check_c(char *str, t_parse *parse, t_info *info)
{
	int	j;
	char *res;
	int	k;
	int i;

	k = 0;
	j = 1;
	if (parse->info->c_ok == 1)
		return (printf("Error\ntoo many NO \n"), 0);
	res = new_string(str, 2);
	parse->info->c_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->c_color = ft_calloc(sizeof(char *), ft_strlen(res) );
	while (k < ft_strlen(res))
	{
		parse->info->c_color[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

void	fill_color_f(t_info *info)
{
	char *base = "0123456789abcdef";
	
	info->f_hex = ft_strjoin("", ft_putnbr_basep(info->f->r, base , ft_strlen(info->f->r_char)));
}

int	convert_f(char *str, t_parse *parse, t_info* info)
{
	
	if (check_f(str, parse, info) == 1)
	{
		info->f_rgb = ft_split(info->f_color, ',');
		{
			if (info->f_rgb[0] != NULL)
				info->f->r = ft_atoi(info->f_rgb[0]);
			if (info->f_rgb[1] != NULL)
				info->f->g = ft_atoi(info->f_rgb[1]);
			if (info->f_rgb[2] != NULL)
				info->f->b = ft_atoi(info->f_rgb[2]);
			if ((info->f->r >= 0 && info->f->r <= 255)
				&& (info->f->g >= 0 && info->f->g <= 255)
				&& (info->f->b >= 0 && info->f->g <= 255))
			{
				info->f->r_char = ft_strdup(info->f_rgb[0]);
				info->f->g_char = ft_strdup(info->f_rgb[1]);
				info->f->b_char = ft_strdup(info->f_rgb[2]);
				fill_color_f(info);
			}
		}
	}
}


