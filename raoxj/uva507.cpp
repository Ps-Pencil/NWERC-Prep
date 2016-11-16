#include "stdio.h"

int main()
{
	int n,k,m;
	long long cur,max;
	scanf("%d",&m);
	for (k=1;k<=m;k++)
	{
		scanf("%d",&n);
		int i,j;
		int besti,bestj,curi;
		besti = 0;
		bestj = -1;
		cur = 0;
		max = 0;
		curi = 1;
		for (i=1;i<n;i++)
		{
			scanf("%d",&j);
			cur += j;
			if (cur>=max)
			{
				if (((cur == max) && (i+1-curi > bestj-besti)) || (cur > max))
				{
					bestj = i+1;
					besti = curi;
				}
				max = cur;
			}
			if (cur<0)
			{
				cur = 0;
				curi = i+1;
			}
		}
		if (max>0) printf("The nicest part of route %d is between stops %d and %d\n",k,besti,bestj);
		else printf("Route %d has no nice parts\n",k);
	}
	return 0;
}
