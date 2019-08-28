#include <stdio.h>
#include <string.h> 

void func_swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	func_swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}
