#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int dp[257][257][257];


int main(){
  scanf("%d",&N);
  memset(dp,50,sizeof(dp));
  dp[256][0][0]=0;
  for(int s = 0; s != 257;s++){
    for(int x = 0;x != 257;x++){
      for(int y = 0;y != 257;y++){
      }
    }
  }
  int min = 50;
  for(int i=0;i!=257;i++)
    for(int j=0;j!=257;j++){
      if(dp[i][N][j] < min)
        min = dp[i][N][j];
      if(dp[i][j][N] < min)
        min = dp[i][j][N];
    }
  printf("%d\n",min);
}
