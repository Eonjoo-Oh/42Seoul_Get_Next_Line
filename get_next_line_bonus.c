/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:35:01 by eoh               #+#    #+#             */
/*   Updated: 2023/01/17 11:30:19 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	static t_list *save_lst;
	t_list *lst;
	char *buf;
	char *save;
	char *result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (NULL);
	if (!save_lst)
	{
		save_lst = lstnew(fd);
		if (save_lst == 0)
		{
			free(buf);
			return (NULL);
		}
	}
	lst = recall(fd, save_lst);
	save = read_line(fd, buf, save_lst->content);
	free(buf);
	if (save == NULL)
	{
		free(save_lst);
		return (NULL);
	}
	result = get_result(save);
	save_lst->content = update_save(save);
	
	return (result);
}

t_list *recall(int fd, t_list *save)
{
	t_list *new;

	while (save->fd != fd)
	{
		if (save->next == NULL)
		{
			new = lstnew(fd);
			if (new->content == NULL)
			{
				free(new);
				return (0);
			}
			save->next = new;
			return (new);
		}
		save = save->next;
	}
	return (save);
}

char *read_line(int fd, char *buf, char *save)
{
	char	*old_save;
	int		read_res;

	while (1)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(save);
			return (0);
		}
		if (read_res == 0)
			return (save);
		buf[read_res] = '\0';
		old_save = save;
		save = ft_strjoin(save, buf);
		free(old_save);
		if (save[0] == '\0')
		{
			free(save);
			return (save);
		}
		if (ft_strchr(save, '\n') != -1 || read_res < BUFFER_SIZE)
			return (save);
	}
}

char *get_result(char *save)
{
	int		n_index;
	char	*result;

	if (save[0] == '\0')
		return (0);
	n_index = ft_strchr(save, '\n');
	if (n_index == -1)
		result = ft_strdup(save);
	else
		result = ft_substr(save, 0, n_index);
	return (result);
}

char *update_save(char *save)
{
	char	*new_save;
	int		n_index;

	if (save[0] == '\0')
	{
		free(save);
		return (0);
	}
	n_index = ft_strchr(save, '\n');
	if (n_index == -1)
	{
		free(save);
		new_save = 0;
	}
	else
	{
		new_save = ft_substr(save, n_index + 1, ft_strlen(save) - 1);
		free(save);
	}
	return (new_save);
}

t_list *lstnew(int fd)
{
	t_list *new;
	char *content;

	content = ft_strdup("");
	if (content == NULL)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->fd = fd;
	new->content = content;
	new->next = NULL;

	return (new);
}
