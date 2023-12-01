// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int fd;
// 	char buf[256];
// 	int chars_read;
// 	fd = open("file.txt", O_RDONLY);
// 	while ((chars_read = read(fd,buf,73)))
// 	{
// 		buf[chars_read] = '\0';
// 		printf("buf -> %s",buf);
// 	}
// }