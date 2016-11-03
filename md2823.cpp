#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
	int n,k;
	srand(time(NULL));
	n = 1000000;
	k = 400000;
	printf("%d %d\n",n,k);
	for (int i=0;i<n;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}
