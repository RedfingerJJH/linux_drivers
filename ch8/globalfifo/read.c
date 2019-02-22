/*
sudo mknod /dev/globalfifo c 231 0
sudo ./read
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 10

int main(void)
{
	int fd, len;
	char str[LENGTH];
	char *file = "/dev/globalfifo";

	fd = open(file, O_RDWR);	
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
	
	printf("read\n");
}
