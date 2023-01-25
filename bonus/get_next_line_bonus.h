/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:38:57 by eoh               #+#    #+#             */
/*   Updated: 2023/01/21 18:57:27 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

typedef struct s_list 
{
    struct s_list *front;
    struct s_list *cur;
    struct s_list *back;
    int fd;
    char *save;
} t_list;

char *get_next_line(int fd);
t_list *ft_lstnew(int fd);
t_list *recall_lst(int fd, t_list *save_lst);
char *read_line(int fd, char *save, t_list *lst, t_list *save_lst);
char *free_lst(t_list *lst, t_list *save_lst);
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int end);
int	ft_strchr(char *s, int c);

#endif