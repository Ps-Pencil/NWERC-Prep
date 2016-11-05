#include "stdio.h"
#include <cstring>

int n,m;

int hp[500],pay[500],pos[500];

long long d[200][25000];

long long mq[250000][2];

long long ans;

int main()
{
	int i,j;
	long long k;
	scanf("%d %d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d %d %d",&hp[i],&pay[i],&pos[i]);
	}
	int s,t;
	for (i=1;i<=m;i++)
	{
		memset(mq,0,sizeof(mq));
		s = 1;
		t = 1;
		mq[1][0] = 0;
		mq[1][1] = 0;
		for (j=1;j<=n;j++)
		{
			while ((s<=t) && ((j-mq[s][1]>hp[i]) || (mq[s][1] >= pos[i]))) s++;
			d[i][j] = d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];
			if ((s<=t) && (j>=pos[i]) && (j<=pos[i]+hp[i]-1))
			{
				k = mq[s][0] + pay[i]*j;
				d[i][j] = k>d[i][j]?k:d[i][j];
			}
			if (j<pos[i])
			{
				k = d[i-1][j] - pay[i]*j;
				while ((t>=s) && (mq[t][0] < k)) t--;
				t++;
				mq[t][0] = k;
				mq[t][1] = j;
			}
			if (d[i][j] > ans) ans = d[i][j];
//			printf("%d ",d[i][j]);
		}
//		printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
}
