/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:38:38 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/03 17:36:46 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../lib/push_swap.h"

void	ft_free(char **str, char **str2)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return ;
}

char	*ft_strjoin(char *str, char *str2)
{
	int		i;
	int		j;
	char	*final_str;
	int		len;

	len = ft_strlen(str) + ft_strlen(str2);
	final_str = (char *)malloc((len + 1) * sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	while (str && str[i] != '\0')
	{
		final_str[i] = str[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j] != '\0')
		final_str[i++] = str2[j++];
	final_str[i] = '\0';
	ft_free(&str, &str2);
	return (final_str);
}

int	ft_search(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}
