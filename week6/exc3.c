#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void handle(int i) {
	fprintf(stderr, "Terminating...\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	signal(SIGINT, handle);

	for(;;) {
	}
}
