//https://uva.onlinejudge.org/external/113/11396.pdf
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,l;

vector<int> adj[400];

int color[400];
bool bip(){
  memset(color,0,sizeof(color));
  queue<int> q;
  q.push(1);
  color[1]=1;
  while(!q.empty()){
    int x=q.front();q.pop();
    for(int i : adj[x]){
      if(color[i] == 0){
        color[i] = 3-color[x];
        q.push(i);
      }
      else if(color[i] == color[x])
        {
          // printf("%d %d\n",i,x);
          return false;
        }
    }
  }
  return true;
}
int main(){
  while(scanf("%d",&n),n){
    for(int i=1;i<=n;i++)
      adj[i].clear();
    int a,b;
    while(scanf("%d %d",&a,&b),a+b){
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if(bip()) printf("YES\n");
    else printf("NO\n");
  }
}
