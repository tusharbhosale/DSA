#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
typedef struct info {
	int id;
	char name[16];
	double score;
}info;
int main(int argc, char *argv[]) {
	info arr[50];
	int fd, i = 0, x = sizeof(arr[0]);
	double d;	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error\n");
		return errno;
	}
	while(x == sizeof(arr[0])) {
		x = 0;
		x = read(fd, &arr[i], sizeof(arr[0]));
		d = atof(argv[2]);
		if(arr[i].score == d)
			printf("%d %s %lf\n", arr[i].id, arr[i].name, arr[i].score);		
		i++;
	}
	close(fd);
	return 0;
}
