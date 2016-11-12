//https://uva.onlinejudge.org/external/103/10305.pdf
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
typedef vector<int> vi;

vi adj[200];
int order[101];
int cur;
bool p[101];
bool vis[101];
void dfs(int s){
  vis[s] = 1;
  for(int i : adj[s]){
    if(!vis[i])
      dfs(i);
  }
  order[cur++]=s;
}
int main(){
  while(scanf("%d %d",&n,&m),n+m){
    for(int i=1;i<=n;i++)
      adj[i].clear();
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      adj[b].push_back(a);
      p[a]=1;
    }
    cur=0;
    for(int i=1;i<=n;i++){
      if(!p[i] && !vis[i]){
        dfs(i);
      }
    }
    printf("%d",order[0]);
    for(int i=1;i<cur;i++)
      printf(" %d",order[i]);
    printf("\n");
  }
}
