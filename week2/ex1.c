#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int num1 = INT_MAX;
	printf("%d %d\n", sizeof(num1), num1);
	float num2 = FLT_MAX;
	printf("%d %f\n", sizeof(num2), num2);
	double num3 = DBL_MAX;
	printf("%d %f\n", sizeof(num3), num3);
	
	return 0;
}