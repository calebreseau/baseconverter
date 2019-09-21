#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reste(int a,int b)
{
	return a-(a/b)*b;
}
int convfromten(int nb,int b)
{
	int q;
	int digits[100];
	int result=0;
	int cpt=0;
	int oldq;
	q=nb;
	do
	{
		oldq=q;
		q=oldq/b;
		digits[cpt]=reste(oldq,b);
		cpt++;
	}
	while (q!=0);
	int tmp[cpt];
	for (int i=0;i<cpt+1;i++)
	{
		tmp[i]=digits[i];
	}
	for (int i=0;i<cpt+1;i++)
	{
		result=result+tmp[i]*pow(10,i);
	}
	return result;
}

int available(int base)
{
	int result=0;
	int bases[]={10};
	int length=sizeof(bases)/sizeof(int);
	for (int i=0;i<length;i++)
	{
		if (base==bases[i]) result=1;
	}
	return result;
}

int main(void)
{
	int n,b;
	int nb;
	int result;
	do
	{
		printf("What base do you convert from (choose from list)?\n\t- 10\n\t>");
		scanf("%d",&n);
	}
	while (available(n)==0);
	printf("What number do you want to convert?\n\t>");
	scanf("%d",&nb);
	do
	{
		printf("What base do you want to convert to? (10 max)\n\t>");
		scanf("%d",&b);
	}
	while (b>10);
	switch (n)
	{
		case 10:
			result=convfromten(nb,b);
	}
	printf("(%d)%d = (%d)%d\n",nb,n,result,b);
}
