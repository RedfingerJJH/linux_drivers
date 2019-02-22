#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#define MAX_LEN 100

void intput_handler(int num)
{
	char data[MAX_LEN];
	int len;
	
	len = read(STDIN_FILENO, &data, MAX_LEN);
	data[len] = 0;
	printf("input available:%s\n", data);
}

int main(void)
{
	int oflags;
	
	signal(SIGIO, intput_handler);
	fcntl(STDIN_FILENO,F_SETOWN, getpid());
	oflags =fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, oflags | FASYNC);
	
	while(1);
}