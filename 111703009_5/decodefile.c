#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
	int id;
	char name[40], c;
	int fd, i = 0, x = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error\n");
		return errno;
	}
	while(x != 0) {
		i = 0;
		x = read(fd, &id, sizeof(int));
		if(x == 0)
			break;
		lseek(fd, 4, SEEK_CUR);
		for(i = 0; i < 40; i++) {
			x = read(fd, &c, 1);
			name[i] = c;
		}
		if(x == 0)
			break;
		printf("%d%s\n", id, name);
	}
	close(fd);
	return 0;
}
