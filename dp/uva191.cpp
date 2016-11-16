#include "stdio.h"
#include "math.h"
#include <vector>
#include <cassert>

using namespace std;

#define PRECISION 1e-10

#define INFINITY 1e100




double lx1,ly1,lx2,ly2;

double rx1,ry1,rx2,ry2;

int n;

double sqdist(double x1,double y1,double z1,double x2,double y2,double z2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
	int i,j,k;
	scanf("%d",&n);
	while (n--)
	{
		double t;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&lx1,&ly1,&lx2,&ly2,&rx1,&ry1,&rx2,&ry2);
		if (lx1 > lx2) { swap(&lx1,&lx2); swap(&ly1,&ly2);}
		if (rx1 > rx2) swap(&rx1,&rx2);
		if (ry1 > ry2) swap(&ry1,&ry2);
		if ((lx1 > rx2) || (lx2 < rx1))
		{
			printf("F\n");
			continue;
		}
		if (lx1 == lx2)
		{
			if (((ly1>=ry1) && (ly1<=ry2)) || ((ly2>=ry1) && (ly2<=ry2)))
			{
				printf("T\n");
				continue;
			}
			printf("F\n");
			continue;
		}
	}
	return 0;
}
