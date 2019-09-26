#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void handle(int x) {
	fprintf(stderr, "Break %d\n", x);
	exit(0);
}

int main(int argc, char *argv[]) {
	
	signal(SIGUSR1, handle); //Only SIGUSR1 can be catched
	signal(SIGSTOP, handle);
	signal(SIGKILL, handle);	
	kill(getpid(), SIGUSR1);
	
	for(;;){
	}
}
