//https://uva.onlinejudge.org/external/120/12047.pdf

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int N,M,s,t,p;

#define INF 2000000000
vi dist,dist_r;
vector<vii> adj,adj_r;
void dijkstra(){
  dist[s] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adj[u].size(); j++) {
      ii v = adj[u][j]; // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
      } } }
}
void dijkstra_r(){
  dist_r[t] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, t)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist_r[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adj_r[u].size(); j++) {
      ii v = adj_r[u][j]; // all outgoing edges from u
      if (dist_r[u] + v.second < dist_r[v.first]) {
        dist_r[v.first] = dist_r[u] + v.second; // relax operation
        pq.push(ii(dist_r[v.first], v.first));
      } } }
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d %d %d",&N,&M,&s,&t,&p);
    adj.clear();
    adj_r.clear();
    adj.resize(N+1);
    adj_r.resize(N+1);
    for(int i=0;i<M;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      adj[a].push_back(ii(b,c));
      adj_r[b].push_back(ii(a,c));
    }
    dist.assign(N+1,INF);
    dist_r.assign(N+1,INF);
    dijkstra();
    dijkstra_r();
    int maxtoll = -1;
    for(int i=1;i<adj.size();i++){
      for(ii e : adj[i]){
        if(dist[i]!=INF && dist_r[e.first]!=INF && dist[i]+e.second+dist_r[e.first]<=p && e.second>maxtoll)
          maxtoll = e.second;
      }
    }
    printf("%d\n",maxtoll);
  }
}
