#include "stdio.h"
#include <cstring>

long long d[10][12][150][1024];

int main()
{
	int i,j,k,l;
	int t;
	int n,m;
	for (k=1;k<=9;k++)
	{
		for (i=1;i<=k;i++)
		{
			d[k][i][1][1<<i] = 1;
		}
	}
	for (k=1;k<=9;k++)
	{
		for (j=2;j<=100;j++)
		{
			for (i=0;i<=k;i++)
			{
				for (l=1<<i;l<=(1<<(k+1))-1;l++)
				{
					if ((l&(1<<i)) == 0) continue;
					if (i!=0) d[k][i][j][l] += d[k][i-1][j-1][l]+d[k][i-1][j-1][l-(1<<i)];
					if (i!=k) d[k][i][j][l] += d[k][i+1][j-1][l]+d[k][i+1][j-1][l-(1<<i)];
					d[k][i][j][l] %= 1000000007;
				}
			}
		}
	}
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d %d",&n,&m);
		long long ans = 0;
		for (i=0;i<=n-1;i++)
		{
			for (j=1;j<=m;j++)
			{
				ans += d[n-1][i][j][(1<<n)-1];
				ans %= 1000000007;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
