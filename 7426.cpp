// https://icpcarchive.ecs.baylor.edu/external/74/7426.pdf
#include <cstdio>
#include <cstring>

#include <algorithm>
unsigned long dp[1000001];
unsigned long n,r,p;
using namespace std;


unsigned long ceiling(unsigned long a, unsigned long b){
  return (a+b-1)/b;
}
// min time
unsigned long mt(unsigned long nol){
  if(nol <= 1) return 0;
  if(dp[nol] != 0) return dp[nol];
  unsigned long ans = -1;
  for(int i=1;i!=nol;i++){
    int k = ceiling(nol,i+1);
    ans = min(ans, i * p + mt(k) + r);
  }
  return dp[nol] = ans;
}
int main(){
  while(scanf("%lu %lu %lu",&n,&r,&p) != EOF){
    memset(dp,0,sizeof(dp));
    printf("%lu\n",mt(n));
  }
}
