/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:13:05 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/07 16:17:23 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"

typedef struct s_info
{ 
	int	no_ok;
	int	so_ok;
	int we_ok;
	int ea_ok;
	int	f_ok;
	int	c_ok;
	char *no_path;
	char *so_path;
	char *we_path;
	char *ea_path;
	char *f_color;
	char *c_color;
}	t_info;

typedef struct s_parse
{
	char **lines;
	char *temp;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *F;
	char *C;
	t_info *info;
}			t_parse;
	
void	ft_bzero(void *s, size_t n);
int	skip_space(char *s);
int			ft_strcmp(char *s1, char *s2);
int	ft_strncmp( const char *first, const char *second, size_t length);
int	check_no(char *str, t_parse *parse, t_info *info);

#endif
