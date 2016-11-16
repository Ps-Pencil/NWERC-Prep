#include "stdio.h"
#include "math.h"

int n;

double tree[5500][3];

int ans[15];

double min[5500];

inline double sqdist(double x1,double y1,double z1,double x2,double y2,double z2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
	double x,y,z;
	int i,j;
	n = 0;
	scanf("%lf %lf %lf",&x,&y,&z);
	while ((fabs(x)>1e-9)||(fabs(y)>1e-9)||(fabs(z)>1e-9))
	{
		tree[n][0] = x;
		tree[n][1] = y;
		tree[n][2] = z;
		n++;
		scanf("%lf %lf %lf",&x,&y,&z);
	}
	for (i=0;i<n;i++)
	{
		min[i] = 100000000;
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			if (j==i) continue;
			double tmp = sqdist(tree[i][0],tree[i][1],tree[i][2],tree[j][0],tree[j][1],tree[j][2]);
			if (tmp < min[i]) min[i] = tmp;
			if (tmp < min[j]) min[j] = tmp;
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=1;j<=10;j++) if (min[i] < j*j) {ans[j] ++; break;}
	}
	for (i=1;i<=10;i++)
	{
		printf("%4d",ans[i]);
	}
	printf("\n");
	return 0;
}
