#include "stdio.h"
#include <cstring>

int weight[150];

int d[60000];

int sum;

int main()
{
	int m,n;
	int i,j,k;
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d",&n);
		sum = 0;
		memset(weight,0,sizeof(weight));
		memset(d,0,sizeof(d));
		for (i=0;i<n;i++)
		{
			scanf("%d",&weight[i]);
			sum += weight[i];
		}
		d[0] = 1;
		for (i=0;i<=n;i++)
		{
			for (j=sum/2;j>=0;j--)
			{
				if (j>=weight[i]) d[j] |= d[j-weight[i]];
			}
		}
		for (i=sum/2;i>=0;i--)
		{
			if (d[i]) break;
		}
		printf("%d\n",sum-2*i);
	}
	return 0;
}
