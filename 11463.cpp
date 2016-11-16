//https://uva.onlinejudge.org/external/114/11463.pdf

#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<vector<int> > adj;
#define INF 1000000000
vector<int> dist,distr;
int s,t;
int main(){
  int T;
  scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    printf("Case %d: ",tc);
    adj.clear();
    scanf("%d %d",&n,&m);
    adj.resize(n);
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    // for(int i=0;i<n;i++){
    //   printf("%d : ",i);
    //   for(int j:adj[i]){
    //     printf("%d ",j);
    //   }
    //   printf("\n");
    // }
    scanf("%d %d",&s,&t);
    dist.assign(n,INF);
    distr.assign(n,INF);
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int a = q.front();q.pop();
      for(int k : adj[a]){
        // printf("%d->%d\n",a,k);
        if(dist[k] == INF){
          dist[k] = dist[a]+1;
          q.push(k);
        }
      }
    }
    distr[t]=0;
    q.push(t);
    while(!q.empty()){
      int a = q.front();q.pop();
      for(int k : adj[a]){
        if(distr[k] == INF){
          distr[k] = distr[a]+1;
          q.push(k);
        }
      }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
      // printf("%d %d %d\n",i,dist[i],distr[i]);
      ans = max(ans,dist[i]+distr[i]);
    }
    printf("%d\n",ans);
  }
}
