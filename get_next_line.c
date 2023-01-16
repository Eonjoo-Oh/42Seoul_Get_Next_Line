/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:11:54 by eonjoo            #+#    #+#             */
/*   Updated: 2023/01/16 10:10:44 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*result;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (save == 0)
		save = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		free(save);
		return (NULL);
	}
	save = read_line(fd, buf, save);
	free(buf);
	if (save == NULL)
		return (NULL);
	result = get_result(save);
	save = update_save(save);
	return (result);
}

char	*read_line(int fd, char *buf, char *save)
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

char	*get_result(char *save)
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

char	*update_save(char *save)
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
