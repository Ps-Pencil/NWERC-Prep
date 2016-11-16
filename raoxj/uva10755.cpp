#include "stdio.h"
#include <cstring>

long long val[30][30][30];

long long d[30][30][30];

long long sum[30][30][30];

inline long long sumbox(int x1,int y1,int z1,int x2,int y2,int z2)
{
	return sum[x2][y2][z2]-sum[x1-1][y2][z2]-sum[x2][y1-1][z2]-sum[x2][y2][z1-1]+sum[x1-1][y1-1][z2]+sum[x2][y1-1][z1-1]+sum[x1-1][y2][z1-1]-sum[x1-1][y1-1][z1-1];
}

int main()
{
	int n;
	int x,y,z;
	int i,j,k,l,m;
	scanf("%d",&n);
	while (n--)
	{
		long long max = -1111111111111;
		scanf("%d %d %d",&x,&y,&z);
		memset(sum,0,sizeof(sum));
		memset(val,0,sizeof(val));
		memset(d,0,sizeof(d));
		for (i=1;i<=x;i++)
		{
			for (j=1;j<=y;j++)
			{
				for (k=1;k<=z;k++)
				{
					scanf("%lld",&val[i][j][k]);
					max = val[i][j][k]>max?val[i][j][k]:max;
					sum[i][j][k] = sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]
							-sum[i-1][j-1][k]-sum[i][j-1][k-1]-sum[i-1][j][k-1]
							+sum[i-1][j-1][k-1]
							+val[i][j][k];
			//		printf("%d %d %d %d\n",i,j,k,sum[i][j][k]);
				}
			}
		}
		long long ans = 0;
		long long cur = 0;
		for (i=1;i<=x;i++)
		{
			for (j=1;j<=y;j++)
			{
				for (k=i;k<=x;k++)
				{
					for (l=j;l<=y;l++)
					{
						cur = 0;
						for (m=1;m<=z;m++)
						{
							cur += sumbox(i,j,m,k,l,m);
			//				printf("%d %d %d %d %d %d\n",i,j,k,l,m,sumbox(i,j,m,k,l,m));
							cur = cur>0?cur:0;
							ans = cur>ans?cur:ans;
						}
					}
				}
			}
		}
		if (ans>0)
		{
			printf("%lld\n",ans);
		}
		else
		{
			printf("%lld\n",max);
		}
		if (n != 0) printf("\n");
	}
	return 0;
}
