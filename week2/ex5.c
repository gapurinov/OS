#include <stdio.h>
#include <string.h> 

void draw_figure(int n, int x) {
	if(x == 1) {
		for(int i = 1; i <= n; i++) { 
			for(int j = 1; j <= n; j++) {
				if(j <= i) {
					printf("*");
				}
			}
			printf("\n");
		}
	}
	if(x == 2) {
		for(int i = 1; i <= (n+1)/2; i++) {
			for(int j = 1; j <= (n+1)/2; j++) {
				if(j <= i) {
					printf("*");
				}
			}
			printf("\n");
		}
		int cnt = (n+1) / 2;
		if(n % 2 != 0) cnt--;
		for(int i = (n+1)/2 + 1; i <= n; i++) {
			for(int j = 1; j <= cnt; j++) {
				printf("*");
			}
			cnt--;
			printf("\n");
		}
	}
	if(x == 3) {
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) {
					printf("*");
			}
			printf("\n");
		}
	}
}

int main() {
	int n, x;
	printf("Enter the height n: ");
	scanf("%d", &n);
	printf("Enter the number of the type x: ");
	scanf("%d", &x);
	draw_figure(n, x);
	return 0;
}
