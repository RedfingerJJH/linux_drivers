/*
sudo mknod /dev/globalmem c 230 0
sudo ./test
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 0x1000

int main(void)
{
	int fd, len;
	char str[LENGTH];
	char *name = "hello linux ...";
	
	fd = open("/dev/globalmem", O_RDWR);
	if (fd) {
		write(fd, name, strlen(name));
		close(fd);
	}

	fd = open("/dev/globalmem", O_RDWR);
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
}
