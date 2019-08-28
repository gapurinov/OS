#include <stdio.h>
#include <string.h> 

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int cnt = 2*i-1;
		for(int j = 1; j <= 2*n-1; j++) {
			if(j <= n-i) {
				printf(" ");
			} else {
				if(cnt > 0) {
					printf("*");
					cnt--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
