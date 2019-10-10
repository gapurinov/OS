#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
	struct rusage usgmem;
	for(int i = 1; i <= 10; i++) {
		void *ptr = malloc(1024*1024*10);
		memset(ptr, 0, 1024*1024*10);
		getrusage(RUSAGE_SELF, &usgmem);
		printf("%ld\n", usgmem.ru_maxrss);
		sleep(1);
	}
	return 0;
}
