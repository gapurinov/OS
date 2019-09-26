#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
	pid_t process_num = fork();
	
	if(process_num > 0) {
		sleep(10);
		kill(process_num, SIGTERM);
	} else if(process_num == 0) {
		for(;;) {
		printf("I'm alive!\n");
		sleep(1);
		}
	} else {
		printf("Forking error\n");
	}
}
