/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:27:19 by mel-hadd          #+#    #+#             */
/*   Updated: 2023/12/01 13:52:08 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	dst = (unsigned char *)dest;
	while (i < n)
	{
		*dst = *(unsigned char *)src;
		i++;
		dst++;
		src++;
	}
	return (dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		total_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2;
	new_str = (char *)malloc(total_len * sizeof(char) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, len_s1);
	ft_memcpy(new_str + len_s1, s2, len_s2);
	new_str[total_len] = '\0';
	return (new_str);
}

char *get_next_line(int fd)
{
    char buf [BUFFER_SIZE];
    static char *str;
    int chars_read;
   	chars_read  = read (fd, buf, BUFFER_SIZE);
	
	if (chars_read != 0)
	ft_memcpy(str,buf,BUFFER_SIZE);
	ft_strjoin(str,str);
	return str;  
    
}
char *get_next_line(int fd)
{
    char *buf;
        static char *str;
    int chars_read;

        buf = ft_calloc(sizeof(char) * BUFFER_SIZE);
        if (buf == NULL)
        return NULL;
        chars_read  = read (fd, buf, BUFFER_SIZE);
        if (chars_read <= 0)
        return
        ft_memcpy(str,buf,BUFFER_SIZE);
        ft_strjoin(str,str);
        return str;

}
int main ()
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
}
