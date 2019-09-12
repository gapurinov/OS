#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int n = 10;
	fork();
	printf("Hello from parent %ld\n", (long)getpid()-n);
	printf("Hello from child %ld\n", (long)getpid()-n);
return 0;
}
