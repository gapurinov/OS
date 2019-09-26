#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int main(int argc, char *argv[]) {
	int tails[2];
	int a = 0;

	if (a = pipe(tails)) {
		fprintf(stderr, "Failed to create a pipe\n");
		exit(a);
	}

	pid_t pnum1 = fork();

	if (pnum1 == 0) {
		pid_t pnum2;
		fprintf(stdout, "Child1 started\n");
		close(tails[1]);
		FILE *fp = fdopen(tails[0], "r");
		fscanf(fp, "%d", &pnum2);
		fclose(fp);
		fprintf(stdout, "Child1 received pnum2 = %d\n", pnum2);
		sleep(5);
		fprintf(stdout, "Child1 send kill to child2\n", pnum2);
		kill(pnum2, SIGSTOP);
	}
	
	else if (pnum1 > 0) {
		pid_t pnum2 = fork();
		
		if (pnum2 == 0) {
			close(tails[0]);
			close(tails[1]);
			fprintf(stdout, "Child2 started\n");
			for(;;) {
				fprintf(stdout, "Child2 running\n");
			}
		}
		
		else if (pnum2 > 0) {
			close(tails[0]);
			FILE *fp = fdopen(tails[1], "w");
			fprintf(stdout, "Main process send pnum\n");
			fprintf(fp, "%d", pnum2);
			fclose(fp);
			int pstatus = 0;
			fprintf(stdout, "Main process waits child2\n");
			waitpid(pnum2, &pstatus, 0);
			fprintf(stdout, "Status of child1 = %d\n", pstatus);
		}
	}
	
}