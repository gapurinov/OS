#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
	
int sz = 47;
char* s1 = "California love, California knows how to party";

void read(int fp) {
	char ch;
	FILE *content = fdopen(fp, "r");
	
	while((ch = fgetc(content)) != EOF) {
		printf("%c", c);
	}
	
	fclose(content);
	exit(0);
}

int main() {
	int tails[2];
	pipe (tails);
	
	pid_t process_num = fork();
	if(process_num == 0) 
		read(tails[0]);
	
	FILE *fp = fdopen(tails[1], "w");
	fprintf(fp, "%s", "In the city of L.A \n");
	fclose(fp);
	
	return 0;
}
