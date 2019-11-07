#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *myFile1 = fopen("/dev/random", "r");
	FILE *myFile2 = fopen("ex1.txt", "w");

	char str[21];
	for(int i = 0; i < 20; i++) {
		str[i] = fgetc(myFile1);
	} 
	str[20] = '\0';
	fprintf(myFile2, "%s\n", str);
	fclose(myFile1);
	fclose(myFile2);
	return 0;
}