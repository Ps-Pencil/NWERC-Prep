#include "stdio.h"
#include <cstring>

#define MAXN 1120
#define MAXK 14

int notprime[MAXN+30];

int plist[MAXN];

int pnum;

int d[MAXN+30][MAXN+30][MAXK+1];

int main()
{
	int i,j,k;
	notprime[0] = 1;
	notprime[1] = 1;
	for (i=2;i<=MAXN;i++)
	{
		if (notprime[i]) continue;
		for (j=2;j*i<=MAXN;j++)
		{
			notprime[i*j] = 1;
		}
	}
	for (i=2;i<=MAXN;i++)
	{
		if (!notprime[i])
		{
			pnum ++;
			plist[pnum] = i;
		}
	}
	d[0][0][0] = 1;
	for (i=1;i<=pnum;i++)
	{
		d[i][0][0] = 1;
		for (j=0;j<=MAXN;j++)
		{
			for (k=1;k<=MAXK;k++)
			{
				d[i][j][k] = d[i-1][j][k];
			}
			if (j>=plist[i])
			{
				for (k=1;k<=MAXK;k++)
				{
					d[i][j][k] += d[i-1][j-plist[i]][k-1];
				}
			}
		}
	}
	while (scanf("%d %d",&i,&j) == 2)
	{
		if (j == 0) return 0;
		printf("%d\n",d[pnum][i][j]);
	}
	
	return 0;
}
