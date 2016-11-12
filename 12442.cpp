//https://uva.onlinejudge.org/external/124/12442.pdf

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n[60000];
int N;
int longest[60000];
bool vis[60000];

void dfs(int x){
  if(longest[x]) return;
  // x is start of loop
  if(vis[x]){
    int looplen = 1;
    int cur = n[x];
    while(cur != x){
      looplen++;
      cur = n[cur];
    }
    longest[cur] = looplen;
    cur = n[cur];
    while(cur!=x){
      longest[cur]=looplen;
      cur = n[cur];
    }
    return;
  }
  vis[x]=1;
  dfs(n[x]);
  // if x is not in a loop
  if(!longest[x]) longest[x] = longest[n[x]]+1;
}
int main(){
  int T;
  scanf("%d",&T);
  for(int x=1;x<=T;x++){
    memset(longest,0,sizeof(longest));
    printf("Case %d: ",x);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      n[a] = b;
    }
    int maxd=0, maxi;
    for(int i=1;i<=N;i++){
      memset(vis,0,sizeof(vis));
      dfs(i);
      if(longest[i] >maxd){
        maxd = longest[i];
        maxi=i;
      }
    }
    printf("%d\n",maxi);
  }
  return 0;
}
