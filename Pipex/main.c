#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int id = fork();
	int x;

	x = 0;
	while (x < 5)
	{
		id = fork();
		x++;
	}
	printf("fork 1 %d\n", id);
	// printf("fork 2 %d\n", id1);
}