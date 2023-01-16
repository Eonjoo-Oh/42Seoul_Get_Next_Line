/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:35:01 by eoh               #+#    #+#             */
/*   Updated: 2023/01/16 17:10:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	static t_list *save;
	t_list *lst;
	char *buf;
	char *saved_line;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (NULL);
	if (!save)
	{
		save = lstnew(fd, buf);
		if (save == 0)
		{
			free(buf);
			return (NULL);
		}
	}
	lst = recall(fd, save);
	saved_line = lst->content;
	saved_line = read_line(fd, buf, saved_line);
	free(buf);
	if (saved_line == NULL)
		return (NULL);
	result = get_result(saved_line);
	line = update_save(save_line);
	save = lstrenew(t_list *save, int fd, char *line);
	return (result);
}

t_list *recall(int fd, t_list *save)
{
	t_list *new;

	while (save->fd != fd)
	{
		if (save->next == NULL)
		{
			new = (t_list*)malloc(sizeof(t_list));
			if (!(save->next))
				return (0);
			save->next = new;
			new->fd = fd;
			new->content = strdup("");
			if (new->content == NULL)
			{
				free(new);
				return (0);
			}
			return (new);
		}
		save = save->next;
	}
	return (save);
}

char *read_line(int fd, char *content)
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

char *get_result(char *line)
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

char *update_save(char *line)
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

t_list *lstnew(int fd, char *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->fd = fd;
	new->content = content;
	new->next = NULL;

	return (new);
}

void	lstrenew(int fd, char *content)
{
	lstrenew->fd = fd;
	lstrenew->contetn = content;
}