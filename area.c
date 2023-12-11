#include<stdio.h>

int main() {
	double n1, n2;
	
	scanf("%lf %lf", &n1, &n2);
	double area = (n1*n2)/2;
	
	printf("%.2lf\n\n", area);
}
