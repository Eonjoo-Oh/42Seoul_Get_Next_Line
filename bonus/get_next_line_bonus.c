/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:43:19 by eoh               #+#    #+#             */
/*   Updated: 2023/01/25 11:48:09 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static t_list *save_lst;
    t_list *lst;
    char *line;
    int n_index;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    if (!save_lst)
        save_lst = ft_lstnew(-1);
    lst = recall_lst(fd, save_lst);
    line = read_line(fd, lst->save, lst, save_lst);

    if (!line || line[0] == '\0')
        return (free_lst(lst, save_lst));
    n_index = ft_strchr(line, '\n');
    if (n_index == -1)
    {
        lst->cur->save = NULL;
        free_lst(lst, save_lst);
    }
    else
        lst->cur->save = ft_substr(line, n_index + 1, ft_strlen(line));
    line = ft_substr(line, 0, n_index);
    return (line);
}

t_list *ft_lstnew(int fd)
{
    t_list *new;
    char *str;

    str = 0;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->front = NULL;
    new->cur = new;
    new->back = NULL;
    new->fd = fd;
    new->save = str;
    return (new);
}

t_list *recall_lst(int fd, t_list *save_lst)
{
    t_list *result;

    while (save_lst->fd != fd)
    {
        if (save_lst->back == NULL)
        {
            result = ft_lstnew(fd);
            if(result == 0)
            {
                free(save_lst);
                return (NULL);
            }
            save_lst->back = result;
            result->front = save_lst;
            return (result);
        } 
        save_lst = save_lst->back;
    }
    result = save_lst;
    return (result);
}

char *read_line(int fd, char *save, t_list *lst, t_list *save_lst)
{
    char buf[BUFFER_SIZE + 1];
    char *old_save;
    int read_res;

    while (1)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 0)
		{
            return (free_lst(lst, save_lst));
		}
		if (read_res == 0)
			return (save);
		buf[read_res] = '\0';
        old_save = save;
		save = ft_strjoin(save, buf);
        free(old_save);
        /*if (save == 0)
        {
            free(save_lst);
            return (NULL);
        }*/
		if (save[0] == '\0')
		    return (free_lst(lst, save_lst));
		if (ft_strchr(save, '\n') != -1 || read_res < BUFFER_SIZE)
			return (save);
	}
}

char *free_lst(t_list *lst, t_list *save_lst)
{
    free(lst->cur->save);
    lst->front->back = lst->cur->back;
    if (lst->back == NULL)
    {
        free(lst->cur);
        return (NULL);
    }
    lst->back->front = lst->cur->front;
    free(lst->cur);
    if (save_lst->back == NULL)
        free(save_lst->cur);
    return (0);
}
