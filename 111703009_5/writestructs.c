#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
typedef struct info {
	int id;
	char name[16];
	double score;
}info;
int main(int argc, char *argv[]) {
	info arr[50];
	int fd, i = 0;
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
	perror("Error");
	return errno;
	}
	while(i < 50 && scanf("%d%s%lf", &arr[i].id, arr[i].name, &arr[i].score) != EOF)
	       i++;
	write(fd, arr, i * sizeof(arr[0]));
	close(fd);
	return 0;
}
