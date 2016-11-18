//https://uva.onlinejudge.org/external/105/10557.pdf
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int > > adj;
#define INF 1000000000
vector<int> dist;
vector<int> cost;
int main(){
  while(scanf("%d",&n),n!=-1){
    adj.clear();
    cost.clear();
    cost.resize(n+1);
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
      int x,m;
      scanf("%d %d",&x,&m);
      cost[i]=-x;
      for(int j=0;j<m;j++){
        int y;
        scanf("%d",&y);
        adj[i].push_back(y);
      }
    }
    dist.assign(n+1,INF);
    dist[1] = -100;
    for(int i=0;i<n-1;i++){
      for(int j=1;j<=n;j++){
        for(auto e : adj[j]){
          // printf("%d-%d: %d->%d+%d\n",j,e,dist[e],dist[j],cost[e]);
          if(dist[e] > dist[j] + cost[e] && dist[j] < 0){
            dist[e] = dist[j] + cost[e];
          }
        }
      }
    }
    // for(int i=1;i<=n;i++) printf("%d dist[i]: %d\n",i,dist[i]);
    bool winnable = dist[n] <= 0;
    queue<int> neg;
    vector<int> vis(n+1,0);
    for(int j=1;j<=n;j++){
      for(auto e : adj[j]){
        if(dist[e] > dist[j] + cost[e] && dist[j] < 0){
          dist[e] = dist[j] + cost[e];
          neg.push(e);
          vis[e]=1;
        }
      }
    }
    while(!neg.empty()){
      int a = neg.front();neg.pop();
      if(a==n)
        {
          winnable = true;
          break;
        }
      for(int k:adj[a]){
        if(!vis[k]){
          vis[k]=1;
          neg.push(k);
        }
      }
    }
    // for(int i=1;i<=n;i++) printf("%d dist[i]: %d\n",i,dist[i]);
    printf("%s\n",winnable?"winnable":"hopeless");
  }
}
