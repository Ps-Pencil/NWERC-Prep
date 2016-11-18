//https://uva.onlinejudge.org/external/100/10004.pdf
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,l;

vector<int> adj[300];

int color[300];
bool bip(){
  memset(color,0,sizeof(color));
  queue<int> q;
  q.push(0);
  color[0]=1;
  while(!q.empty()){
    int x=q.front();q.pop();
    for(int i : adj[x]){
      if(color[i] == 0){
        color[i] = 3-color[x];
        q.push(i);
      }
      else if(color[i] == color[x]) return false;
    }
  }
  return true;
}
int main(){
  while(scanf("%d",&n),n){
    for(int i=0;i<n;i++)
      adj[i].clear();
    scanf("%d",&l);
    for(int i=0;i<l;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if(bip()) printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");
  }
}
