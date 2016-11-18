//https://uva.onlinejudge.org/external/1/104.pdf
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
#define INF 1000000000
int n;
double conv[100][100][100];
int nxt[100][100][100];
int main(){
  while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++)
          nxt[i][j][k]=j;
        if(i!=j){
          scanf("%lf",&conv[i][j][1]);
        }
        else
          conv[i][j][1] = 1.0;
      }
    }
    // for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){printf("%d %d %d\n",i,j,nxt[i][j]);}
    bool flag = false;
    for(int p=1;p<=n && !flag;p++){
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){conv[i][j][p+1]=conv[i][j][1];}
      // printf("p == %d\n",p);
      for(int i=1;i<=n;i++){
        if(conv[i][i][p] > 1.01){
          printf("%d",i);
          int c = nxt[i][i][p];
          while(p>1){
            printf(" %d",c);
            c = nxt[c][i][--p];
          }
          printf(" %d\n",c);
          flag = true;
          break;
        }
      }
      if(flag) break;
      for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            if(conv[i][k][p]*conv[k][j][1] > conv[i][j][p+1]){
              // printf("%d->(%d)->%d %.4f %.4f %.4f %d %d\n",i,k,j,conv[i][k][p],conv[k][j][1],conv[i][j][p+1],nxt[i][j],nxt[i][k]);
              conv[i][j][p+1]=conv[i][k][p]*conv[k][j][1];
              nxt[i][j][p+1] = nxt[i][k][p];
            }
          }
        }
      }
    }
    if(!flag) printf("no arbitrage sequence exists\n");

  }
}
