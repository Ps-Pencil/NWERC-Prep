//https://uva.onlinejudge.org/external/7/796.pdf

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
using namespace std;
int N;
int adj[200][200];
int bridge[200][200];
int num[200],low[200];
int counter;
void dfs(int s, int p){
  // printf("dfs called %d %d\n",s,p);
  num[s]=low[s]=counter++;
  for(int i=0;i<N;i++ ){if(adj[s][i]==0 || i==s) continue;
    if(num[i] == -1){
      dfs(i,s);
      if(low[i]>num[s]){
        bridge[i][s]=bridge[s][i]=1;
      }
      low[s]=min(low[s],low[i]);
    }
    else if(i!=p)
      low[s] = min(low[s],num[i]);
  }
}
int main(){
  while(scanf("%d",&N)!=EOF){
    memset(adj,0,sizeof(adj));
    memset(bridge,0,sizeof(bridge));
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    for(int i=0;i<N;i++){
      int x,nx;
      scanf("%d (%d)",&x,&nx);
      for(int j=0;j<nx;j++){
        int y;
        scanf("%d",&y);
        adj[x][y] = adj[y][x]=1;
      }
    }
    // for(int i=0;i<N;i++) debug(adj[i],N);
    counter = 0;
    for(int i=0;i<N;i++){
      if(num[i]==-1)
        {
          // printf("going %d\n",i);
          dfs(i,-1);
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if(bridge[i][j])
          ans++;
      }
    }
    printf("%d critical links\n",ans);
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if(bridge[i][j])
          printf("%d - %d\n",i,j);
      }
    }
    printf("\n");
  }
}
