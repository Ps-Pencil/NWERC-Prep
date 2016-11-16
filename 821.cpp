//https://uva.onlinejudge.org/external/8/821.pdf

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;

vector<vector<int> > adj;
vector<pair<int,int> > edges;
int n;
vector<vector<int> > dist;

int bfs(int s){
  dist[s][s]=0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int a = q.front();q.pop();
    for(int k : adj[a]){
      if(dist[s][k]==-1){
        dist[s][k] = 1+dist[s][a];
        q.push(k);
      }
    }
  }
}
int present[200];
int main(){
  int a,b;
  int tc=1;
  while(scanf("%d %d",&a,&b),a+b){
    memset(present,0,sizeof(present));
    edges.clear();
    edges.push_back(ii(a,b));
    n=0;
    n = max(n,a); n = max(n,b);present[a]=present[b]=1;
    while(scanf("%d %d",&a,&b),a+b){
      edges.push_back(ii(a,b));
      n = max(n,a); n = max(n,b);
      present[a]=present[b]=1;
    }
    adj.clear();
    adj.resize(n+1);
    for(auto e : edges){
      adj[e.first].push_back(e.second);
    }
    dist.assign(n+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++){
      if(present[i])
      bfs(i);
    }
    int total = 0;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(present[i]&&present[j])
        total += dist[i][j] + dist[j][i];
      }
    }
    int counter=0;
    for(int i=1;i<=n;i++) counter += present[i];
    printf("Case %d: average length between pages = %.3f clicks\n",tc++,((double) total )/(counter*(counter-1)));
  }
}
