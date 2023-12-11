/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:19:34 by mel-hadd          #+#    #+#             */
/*   Updated: 2023/12/11 16:03:24 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_newline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	count(char *buff)
{
	int	i;

	i = 0;
	while (buff && (buff[i] != '\0' && buff[i] != '\n'))
		i++;
	return (i);
}
// char	*read_file(int fd, char *buff)
// {
// 	int		readed;
// 	char	*str;

// 	str = ft_strdup("");
// while (!found_newline(str) && readed != 0)
// {
// 	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!str)
// 		return (NULL);
// 	readed = read(fd, str, BUFFER_SIZE);
// 	if (readed < 0)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	str[readed] = '\0';
// 	buff = ft_strjoin(buff, str);
// }
// if (readed == 0 && buff[0] == '\0')
// {
// 	free(buff);
// 	buff = NULL;
// 	return (0);
// }
// if (!buff)
// 	return (NULL);
// free(str);
// 	return (buff);
// }

char	*get_next_line(int fd)
{
	static char *buff;
	char		*line;
	int			len;
	char		*str;
	int			readed;
	char *tmp;

	str = NULL;
	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!found_newline(str) && readed != 0)
	{
		if (str)
		free(str);
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		readed = read(fd, str, BUFFER_SIZE);
		if (readed < 0)
		{
			free(str);
			free(buff);
			buff = NULL;
			return (NULL);
		}
		str [readed] = '\0';
		buff = ft_strjoin(buff, str);
	}
	free(str);
	if (readed == 0 && (!buff || buff[0] == '\0'))
	{
		free(buff);
		buff = NULL;
		return (0);
	}
	len = count(buff);
	line = ft_substr(buff, 0, len + 1);
	tmp = buff;
	buff = ft_substr(buff, len + 1, ft_strlen(buff));
	free(tmp);
	return (line);
}