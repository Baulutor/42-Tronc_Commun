#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	int id;
	int x;
	int y;

	if (pipe(fd) == -1)
		return 1;
	id = fork();
	if (id == -1)
	{
		return (2);
	}
	if (id == 0)
	{
		close (fd[0]);
		x  = 156;
		write(fd[1], &x, sizeof(int));
		printf("fais la team\n");
		close (fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &y, sizeof(int));
		close (fd[0]);
		printf("le gosse t'as capte %d", y);
	}
}