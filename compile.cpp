#include <cstdio>
#include <string>
using namespace std;


typedef pair<int,string> is;
int n;

//stack,x,y
is d[260][260][260];

is ans[260];


inline is min(is x,is y)
{
	return x.first>y.first?y:x;
}

string operator * (string a, int x){
  string ans = "";
  while(x--)
    ans += a;
  return ans;
}
string operator * (int x, string a){
  return a*x;
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
				d[i][j][k] = is(10000,"");
			}
		}
    ans[i] = is(10000,"");
	}
	d[0][0][0] = is(0,"");
	d[0][1][0] = is(1,"SET X\n");
	d[0][0][1] = is(1,"SET Y\n");
	for (i=0;i<=255;i++)//stack
	{
printf("%d\n",i);
		for (j=0;j<=255;j++)//x
		{
			for (k=0;k<=255;k++)//y
			{
				if (i==0) d[1][j][k] = min(d[1][j][k],is(d[i][j][k].first+2, d[i][j][k].second+"SET Z\nPUSH Z\n"));//set i to 1
				if (j==0) d[i][1][k] = min(d[i][1][k],is(d[i][j][k].first+1,d[i][j][k].second+"SET X\n"));//set j to 1
				if (k==0) d[i][j][1] = min(d[i][j][1],is(d[i][j][k].first+1,d[i][j][k].second+"SET Y\n"));//set k to 1
				
				d[j][j][k] = min(d[j][j][k],is(d[i][j][k].first+1,d[i][j][k].second+"PUSH X\n"));//set i to j
				d[k][j][k] = min(d[k][j][k],is(d[i][j][k].first+1,d[i][j][k].second+"PUSH Y\n"));//set i to k
				for (l=2;l<=5;l++)//multiplication
				{
					if (i*l <= 255)//pop z;push z (l times);add (l-1 times);
					{
						d[i*l][j][k] = min(d[i*l][j][k],is(d[i][j][k].first+2*l,d[i][j][k].second+string( "POP Z\n" )+l*string( "PUSH Z\n" )+(l-1)*string( "ADD\n" )));
					}
					if (j*l <= 255)//push x (l times);add (l-1 times); pop x;
					{
						d[i][j*l][k] = min(d[i][j*l][k],is(d[i][j][k].first+2*l,d[i][j][k].second+l*string( "PUSH X\n" )+(l-1)*string("ADD\n")+"POP X\n"));
					}
					if (i+j*l <= 255)//push x (l times);add (l times);
					{
						d[i+j*l][j][k] = min(d[i+j*l][j][k],is( d[i][j][k].first+2*l ,d[i][j][k].second+l*string( "PUSH X\n" )+l*string("ADD\n")));
					}
					if (k*l <= 255)//same
					{
						d[i][j][k*l] = min(d[i][j][k*l],is(d[i][j][k].first+2*l,d[i][j][k].second+l*string( "PUSH Y\n" )+(l-1)*string("ADD\n")+"POP Y\n"));
					}
					if (i+k*l <= 255)//same
					{
						d[i+k*l][j][k] = min(d[i+k*l][j][k],is( d[i][j][k].first+2*l ,d[i][j][k].second+l*string( "PUSH Y\n" )+l*string("ADD\n")));
					}
				}
				if (j+k<=255)//push x;push y;add; pop x/y;
				{
					d[i][j+k][k] = min(d[i][j+k][k],is(d[i][j][k].first+4,d[i][j][k].second+"PUSH X\nPUSH Y\nADD\nPOP X\n"));
					d[i][j][j+k] = min(d[i][j][j+k],is(d[i][j][k].first+4,d[i][j][k].second+"PUSH X\nPUSH Y\nADD\nPOP Y\n"));
				}
				if (i+j<=255)
				{
					d[i+j][i+j][k] = min(d[i+j][i+j][k],is(d[i][j][k].first+4,d[i][j][k].second+"PUSH X\nADD\nPOP X\nPUSH X\n"));//push x;add;pop x;push x;
				}
				if (i+k<=255)
				{
					d[i+k][j][i+k] = min(d[i+k][j][i+k],is(d[i][j][k].first+4,d[i][j][k].second+"PUSH Y\nADD\nPOP Y\nPUSH Y\n"));//push x;add;pop x;push x;
				}
				
				ans[i] = min(ans[i],is(d[i][j][k].first+2,d[i][j][k].second+"POP Z\nDISP Z\n"));//pop; dl
				ans[j] = min(ans[j],is(d[i][j][k].first+1,d[i][j][k].second+"DISP X\n"));//dl
				ans[k] = min(ans[k],is(d[i][j][k].first+1,d[i][j][k].second+"DISP Y\n"));//dl
			}
		}
	}
  printf("%s\n",ans[239].second.c_str());
	return 0;
}
