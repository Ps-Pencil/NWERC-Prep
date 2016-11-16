#include "stdio.h"
#include <cstring>

int cost[50],value[50];

int d[50][1200];

int source[50][1200];

void rec(int x,int y,int count)
{
	if (x == 0)
	{
		printf("%d\n",count);
		return;
	}
	rec(x-1,y-source[x][y]*cost[x],count+source[x][y]);
	if (source[x][y]) printf("%d %d\n",cost[x],value[x]);
}

int main()
{
	int t,n,m;
	int i,j,k;
	int max,maxi,maxj;
	int initial = 1;
	while (scanf("%d %d",&t,&m) == 2)
	{
		if (initial) initial = 0;
		else printf("\n");
		t /= (3*m);
		max = 0;
		scanf("%d",&n);
		memset(d,0,sizeof(d));
		memset(source,0,sizeof(source));
		for (i=1;i<=n;i++)
		{
			scanf("%d %d",&cost[i],&value[i]);
		}
		for (i=1;i<=n;i++)
		{
			for (j=0;j<=t;j++)
			{
				d[i][j] = d[i-1][j];
				source[i][j] = 0;
				if (j >= cost[i])
				{
					if (d[i-1][j-cost[i]]+value[i]>d[i][j])
					{
						d[i][j] = d[i-1][j-cost[i]]+value[i];
						source[i][j] = 1;
					}
				}
				if (d[i][j]>max)
				{
					max = d[i][j];
					maxi = i;
					maxj = j;
				}
			}
		}
		printf("%d\n",max);
		rec(maxi,maxj,0);
	}
	return 0;
}
