/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:11:54 by eonjoo            #+#    #+#             */
/*   Updated: 2023/01/13 17:17:26 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char *get_next_line(int fd)
{
    char *buf; //buf[BUFFER)SIZE];
    char *result;
    static char *save;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    if (save == 0)
    {
        save = ft_strdup("");
        if (!save)
            return (0);
    }
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == 0)
    {
        free(save);
        return (0);
    }
    save = read_line(fd, buf, save); // 한 줄을 찾아서 save에 넣어주는 작업
    free(buf);
    /*if (save == 0)
        return (0);*/
    result = get_result(save); // save에서 개행또는 eof까지 잘라서 res를 만들어주는 작업
    save = update_save(save);  // save에서 res를 잘라내고 save를 갱신하는 작업
    return (result);
}

char *read_line(int fd, char *buf, char *save)
{
    char *old_save;
    int read_res;

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
        save = ft_strjoin(save, buf); // save와 buf를 합쳐주는 함수
        free(old_save);
        if (save[0] == '\0')
        {
            save = 0;
            free(save);
            return (save);
        }
        if (ft_strchr(save, '\n') != -1 || read_res < BUFFER_SIZE) // ft_strchr 해당문자가 있는지 찾아주는 함수
            break;
    }
    return (save);
}

char *get_result(char *save)
{
    int n_index;
    char *result;

    n_index = ft_strchr(save, '\n');
    if (n_index == -1)
    {
        result = save;
        free(save);
        //save = 0;
    }
    else
        result = ft_substr(save, 0, n_index); // ft_substr(char, start, end) start부터 end까지 잘라주고 종료문자를 보장해주는 함수
    return (result);
}

char *update_save(char *save)
{
    char *new_save;
    int n_index;

    n_index = ft_strchr(save, '\n');
    if (n_index == -1)
    {
        save = 0;
        free(save);
        new_save = 0;
    }
    else
        new_save = ft_substr(save, n_index + 1, ft_strlen(save) - 1);
    return (new_save);
}  
//0x7fc0e2104080