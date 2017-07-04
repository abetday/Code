#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char *argv[])
{
	int fd = open("/etc/passwd", O_RDONLY);
	char buf[SIZE]="";
	int len = sizeof(buf);
	int char_num = read(fd, buf, len-1);
	do{
		printf("%s", buf);
		memset(buf, 0, len-1);
		char_num = read(fd, buf, len-1);


	}while(char_num == len-1);
	printf("%s", buf);

	return 0;
}

