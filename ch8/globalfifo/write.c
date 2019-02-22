/*
sudo mknod /dev/globalfifo c 231 0
sudo ./write
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int fd;
	char *file = "/dev/globalfifo";
	char *name = "I like hello linux ...";
	
	fd = open(file, O_RDWR);
	
	if (fd) {
		write(fd, name, strlen(name));
		close(fd);
	}
	
	printf("write\n");
}
