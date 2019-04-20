#include <stdio.h>
#include "Calculator.h"

int main(void)
{
	char ar[100] = { 0 };
	int data;

	printf("°ª : ");
	scanf("%s", ar);
	Conversion(ar);
	data = Calculate(ar);
	igoa(data);

	return 0;
}
