#include "stdio.h"
#include <cstring>

int weight[30];

int d[300];

int sum;

int main()
{
	int m,n;
	int i,j,k;
	scanf("%d",&m);
	while (m--)
	{
		n = 0;
		sum = 0;
		memset(weight,0,sizeof(weight));
		memset(d,0,sizeof(d));
		char ch = ' ';
		while (ch == ' ')
		{
			scanf("%c",&ch);
			while ((ch < '0') || (ch > '9')) scanf("%c",&ch);
			int cur = 0;
			while ((ch >= '0') && (ch <= '9'))
			{
				cur *= 10;
				cur += ch-'0';
				scanf("%c",&ch);
			}
			weight[n] = cur;
			n++;
			sum += cur;
		}
		if (sum%2 != 0)
		{
			printf("NO\n");
			continue;
		}
		d[0] = 1;
		for (i=0;i<=n;i++)
		{
			for (j=sum/2;j>=0;j--)
			{
				if (j>=weight[i]) d[j] |= d[j-weight[i]];
			}
		}
		printf(d[sum/2]?"YES\n":"NO\n");
	}
	return 0;
}
