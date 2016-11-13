#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <deque>
#define fo(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int mxn=16007;
int n,m;
int dp[105][mxn],z[105],y[105],q[mxn];
deque<int> deq;
struct node
{
    int s,p,l;
}a[mxn];
inline bool comp(const node &x,const node &y) {return x.s<y.s;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int i,j;
    m=read();n=read();
    fo(i,1,n)
      a[i].l=read(),a[i].p=read(),a[i].s=read();
    sort(a+1,a+n+1,comp);
    fo(i,1,n)
      z[i]=max(0,a[i].s-a[i].l),y[i]=min(m,a[i].s+a[i].l-1);
    fo(i,1,n)
    {
        fo(j,0,a[i].s-1) dp[i][j]=dp[i-1][j];
        int h=1,t=0,tmp;
        fo(j,z[i],a[i].s-1) //把dp[i-1]的状态用单调队列闹出来 
        {
            tmp=dp[i-1][j]-j*a[i].p;
            while(!deq.empty() && tmp>=dp[i-1][deq.back()]-deq.back()*a[i].p) deq.pop_back();
            deq.push_back(j);
        }
        fo(j,a[i].s,y[i])
        {
            while(!deq.empty() && j-deq.front()>a[i].l) deq.pop_front();
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[i-1][deq.front()]+(j-deq.front())*a[i].p);
        }
        fo(j,y[i]+1,m) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        printf("%d:\n",i-1);
        for(int j=1;j<=m;j++) printf("%d ",dp[i][j]);
        putchar('\n');
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
