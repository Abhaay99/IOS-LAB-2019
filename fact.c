#include<stdio.h>

int main()
{
	int i,num,j=1;
	printf("Enter the number");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
		j*=i;

	printf("the factorial of %d is %d\n",num,j);
}
