#include "stdio.h"

int n;

//stack,x,y
int d[260][260][260];

int ans[260];

inline int min(int x,int y)
{
	return x>y?y:x;
}

int main()
{
	int i,j,k,l;
	for (i=0;i<=255;i++)
	{
		for (j=0;j<=255;j++)
		{
			for (k=0;k<=255;k++)
			{
				d[i][j][k] = 10000;
			}
		}
		ans[i] = 10000;
	}
	d[0][0][0] = 0;
	d[0][1][0] = 1;
	d[0][0][1] = 1;
	for (i=0;i<=255;i++)//stack
	{
		for (j=0;j<=255;j++)//x
		{
			for (k=0;k<=255;k++)//y
			{
				if (i==0) d[1][j][k] = min(d[1][j][k],d[i][j][k]+1);//set i to 1
				if (j==0) d[i][1][k] = min(d[i][1][k],d[i][j][k]+1);//set j to 1
				if (k==0) d[i][j][1] = min(d[i][j][1],d[i][j][k]+1);//set k to 1
				
				d[j][j][k] = min(d[j][j][k],d[i][j][k]+1);//set i to j
				d[k][j][k] = min(d[k][j][k],d[i][j][k]+1);//set i to k
				for (l=2;l<=5;l++)//multiplication
				{
					if (i*l <= 255)//pop z;push z (l times);add (l-1 times);
					{
						d[i*l][j][k] = min(d[i*l][j][k],d[i][j][k]+2*l);
					}
					if (j*l <= 255)//push x (l times);add (l-1 times); pop x;
					{
						d[i][j*l][k] = min(d[i][j*l][k],d[i][j][k]+2*l);
					}
					if (i+j*l <= 255)//push x (l times);add (l times);
					{
						d[i+j*l][j][k] = min(d[i+j*l][j][k],d[i][j][k]+2*l);
					}
					if (k*l <= 255)//same
					{
						d[i][j][k*l] = min(d[i][j][k*l],d[i][j][k*l]+2*l);
					}
					if (i+k*l <= 255)//same
					{
						d[i+k*l][j][k] = min(d[i+k*l][j][k],d[i][j][k]+2*l);
					}
				}
				if (j+k<=255)//push x;push y;add; pop x/y;
				{
					d[i][j+k][k] = min(d[i][j+k][k],d[i][j][k]+4);
					d[i][j][j+k] = min(d[i][j][j+k],d[i][j][k]+4);
				}
				if (i+j<=255)
				{
					d[i+j][i+j][k] = min(d[i+j][i+j][k],d[i][j][k]+4);//push x;add;pop x;push x;
				}
				if (i+k<=255)
				{
					d[i+k][j][i+k] = min(d[i+k][j][i+k],d[i][j][k]+4);//same
				}
				
				ans[i] = min(ans[i],d[i][j][k]+2);//pop; dl
				ans[j] = min(ans[j],d[i][j][k]+1);//dl
				ans[k] = min(ans[k],d[i][j][k]+1);//dl
			}
		}
	}
	double avg = 0;
	int maxi;
	int max = 0;
	for (i=1;i<=255;i++)
	{
		printf("%03d: %03d ",i,ans[i]);
		avg += ans[i];
		if (ans[i] > max)
		{
			max = ans[i];
			maxi = i;
		}
		if (i%5 == 0) printf("\n");
	}
	printf("Average = %.4lf\nMax = %03d (for %03d)\n",avg/255.0,max,maxi);
	return 0;
}
