/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:38:54 by carlopez          #+#    #+#             */
/*   Updated: 2024/11/29 10:19:46 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
void	ft_free(char **str, char **str2);
char	*ft_strjoin(char *str, char *str2);
int		ft_strlen(char *str);
int		ft_search(char *str);

#endif
