#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 100
#define MEM_CLEAR 0x1

int main(void)
{
	int fd, len;
	char str[LENGTH];
	char *name = "hello linux ...";

	/* fd = open("hello.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR); */
	fd = open("/dev/globalmem0", O_RDWR);
	if (fd) {
		write(fd, name, strlen(name));
		close(fd);
	}

	/* fd = open("hello.txt", O_RDWR); */
	fd = open("/dev/globalmem0", O_RDWR);
	len = read(fd, str, LENGTH);
	str[len] = '\0';
	printf("%s\n", str);
	close(fd);
}
