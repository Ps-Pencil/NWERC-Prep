#include "stdio.h"

int main()
{
	int n;
	int cur,max;
	scanf("%d",&n);
	while (n>0)
	{
		int i,j;
		cur = 0;
		max = 0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&j);
			cur += j;
			max = cur>max?cur:max;
			cur = cur>0?cur:0;
		}
		if (max>0) printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");
		scanf("%d",&n);
	}
	return 0;
}
