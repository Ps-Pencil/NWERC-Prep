// http://codeforces.com/problemset/problem/467/C
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define fo(A,B,C) for(int A=B;i!=C;A++)
#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
using namespace std;
int num[6000];
long long dp[5005][5005];
long long sum[5005];
int n,m,k;

int main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<n;i++)
    scanf("%d",&num[i]);
  sum[1] = num[0];
  for(int i=2;i<=n;i++)
    sum[i] = sum[i-1] + num[i-1];
  for(int j=1;j<=n;j++){
    for(int i=1;i<=k;i++){
      if(i*m > j) break;
      dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + sum[j]-sum[j-m]);
    }
  }
  printf("%lld\n",dp[k][n]);
}
