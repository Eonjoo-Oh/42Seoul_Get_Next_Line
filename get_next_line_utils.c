/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:26:40 by eonjoo            #+#    #+#             */
/*   Updated: 2023/01/12 16:42:37 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strdup(const char *src)
{
    char *str;
    char *c_src;
    int l;
    int i;

    l = 0;
    i = 0;
    c_src = (char *)src;
    while (c_src[l])
    {
        l++;
    }
    str = (char *)malloc(sizeof(char) * (l + 1));
    if (str == 0)
        return (0);
    while (i < l)
    {
        str[i] = c_src[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len;
    size_t s2_len;
    char *str;
    size_t i;

    i = 0;
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
    if (str == 0)
        return (0);
    while (i < s1_len)
    {
        str[i] = s1[i];
        i++;
    }
    while (i < s1_len + s2_len)
    {
        str[i] = s2[i - s1_len];
        i++;
    }
    str[i] = '\0';
    return (str);
}