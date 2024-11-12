/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:22 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/12 18:39:09 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10;
		resultat += str[i] - '0';
		i++;
	}
	return (resultat * signe);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t1;
	int		t2;
	char	*ptr;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	ptr = ft_calloc(t1 + t2 + 1, 1);
	if (!ptr)
		return (NULL);
	while (i < (t1 + t2))
	{
		while (i < t1)
			if (i++ >= 0)
				ptr[i - 1] = s1[i - 1];
		while (j < t2)
			ptr[i++] = s2[j++];
	}
	return (ptr);
}
