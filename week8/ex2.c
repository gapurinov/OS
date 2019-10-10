#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	for(int i = 1; i <= 10; i++) {
		void *ptr = malloc(1024*1024*10);
		memset(ptr, 0, 1024*1024*10);
		sleep(1);
	}
	return 0;
}
