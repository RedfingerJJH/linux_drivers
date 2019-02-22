/*
sudo mknod /dev/globalmem c 230 0
sudo ./test
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define MEM_CLEAR 0x1
#define LENGTH 0x1000

int main(void)
{
	int fd, len;
	char str[LENGTH];
	char *file = "/dev/globalmem";
	char *name = "I like hello linux ...";
	
	fd = open(file, O_RDWR);
	if (fd) {
		write(fd, name, strlen(name));
		close(fd);
	}

	fd = open(file, O_RDWR);
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
	
	printf("MEM_CLEAR...\n");
	
	fd = open(file, O_RDWR);
	ioctl(fd, MEM_CLEAR, 0);
	close(fd);
	
	fd = open(file, O_RDWR);
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
	
	printf("lseek...\n");
	
	fd = open(file, O_RDWR);
	write(fd, name, strlen(name));
	lseek(fd, 2, SEEK_SET);
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
}
