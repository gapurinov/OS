#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>


int sz = 47;
char* s1 = "California love, California knows how to party";

int main() {
	int tails[2];
	
	if (pipe(tails) < 0)
		exit(1);	
	
	char s2[sz];
	write(tails[1], s1, sz);
	read(tails[0], s2, sz);
	printf("It is first string: %s\n It is second string: %s\n ", s1, s2);
	
	return 0;
}
