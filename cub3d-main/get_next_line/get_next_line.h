/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:47:09 by mdenguir          #+#    #+#             */
/*   Updated: 2022/12/03 20:25:33 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
# endif

# include <stdlib.h>
# include <fcntl.h>
# include<unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strchr(const char *s, int c);
char	*ft_read(int fd, char *buffer);
// int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*free_buf(char *buffer);
char	*ft_read_line(char *buffer);

#endif