#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char input[255];
	int flag = 0;
	fgets(input, sizeof(input), stdin);

	if (argc > 1) {
		if (strcmp(argv[1], "-a") == 0)
		flag = 1;
	}
	if (flag) {
		for (int i = 2; i < argc; i++) {
		FILE *myFile = fopen(argv[i], "a");
			fputs(input, myFile);
			fclose(myFile);
		}
	} else {
		for (int i = 1; i < argc; i++) {
			FILE *myFile = fopen(argv[i], "w");
			fputs(input, myFile);
			fclose(myFile);
		}
	}
	printf("%s", input);
return 0;
}