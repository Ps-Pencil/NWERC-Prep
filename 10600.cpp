//https://uva.onlinejudge.org/external/106/10600.pdf

#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
priority_queue<pair<int,ii>, vector<pair<int,ii> >, greater<pair<int,ii> > > q;
int C[200001];
int ra[200001];
int n,m;
int find(int i){
  return (C[i]==i)?i:C[i]=find(C[i]);
}
int u(int i, int j){
  if(ra[i] == ra[j]){
    C[i] = j;
    ra[j]++;
  }
  else if(ra[i]<ra[j]) C[i]=j;
  else C[j]=i;
}
vector<ii> adj[200];
vector<pair<int,ii> > spare;
int minimax[200][200];
void dfs(int source, int u, int maxEdge){
  minimax[source][u] = maxEdge;
  for(auto k : adj[u]){
    if(minimax[source][k.second]<0)
    dfs(source,k.second,max(maxEdge,k.first));
  }
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    while(!q.empty())q.pop();
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      q.push(make_pair(c,ii(a,b)));
    }
    for(int i=1;i<=n;i++) C[i]=i;
    for(int i=1;i<=n;i++) ra[i]=1;
    int counter = n;
    int mincost = 0;
    for(int i=1;i<=n;i++) adj[i].clear();
    spare.clear();
    while((!q.empty()) && counter != 1){
      auto a = q.top();q.pop();
      if(find(a.second.first) == find(a.second.second)) {
        spare.push_back(a);
        continue;
      }
      counter--;
      adj[a.second.first].push_back(ii(a.first,a.second.second));
      adj[a.second.second].push_back(ii(a.first,a.second.first));
      mincost += a.first;
      u(find(a.second.first),find(a.second.second));
    }
    while(!q.empty()){
      spare.push_back(q.top());q.pop();
    }
    memset(minimax,-1,sizeof(minimax));
    for(int i=1;i<=n;i++){
      dfs(i,i,0);
    }
    int best = 2000000000;
    for(auto e : spare){
      // printf("%d %d %d\n",e.first,e.second.first,e.second.second);
      best = min(best,e.first-minimax[e.second.first][e.second.second]);
    }
    printf("%d %d\n",mincost,mincost+best);
  }
}
