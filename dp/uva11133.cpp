#include "stdio.h"
#include <cstring>

int d[50][50];

int main()
{
	int i,j,k;
	for (i=0;i<=43;i++)
	{
		d[i][i+1] = 1;
	}
	for (i=0;i<=44;i++)
	{
		for (j=i+2;j<=44;j++)
		{
			if (i%(j-i) == 0) d[i][j] = 1;
			for (k=i+1;k<=j-1;k++)
			{
				if (k%(j-k) == 0) d[i][j] += d[i][k];
			}
		}
	}
	scanf("%d %d",&i,&j);
	while (i<j)
	{
		printf("%d %d %d\n",i,j,d[i][j]);
		scanf("%d %d",&i,&j);
	}
	return 0;
}
