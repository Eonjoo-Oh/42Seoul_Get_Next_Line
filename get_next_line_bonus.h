/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:44:26 by eoh               #+#    #+#             */
/*   Updated: 2023/01/17 11:30:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
    struct s_list *next;
    int fd;
    char *content;
} t_list;

char *get_next_line(int fd);
t_list *recall(int fd, t_list *save);
char *read_line(int fd, char *buf, char *content);
char *get_result(char *line);
char *update_save(char *line);
t_list *lstnew(int fd);
int	ft_strlen(char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int end);
int	ft_strchr(char *s, int c);

# endif