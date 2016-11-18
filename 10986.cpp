//https://uva.onlinejudge.org/external/109/10986.pdf
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define INF 2000000000
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adj;
vector<int> dist;
int N,M,S,T;
void dijkstra(){
  dist[S] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, S)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adj[u].size(); j++) {
      ii v = adj[u][j]; // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
}
int main(){
  int tc;
  scanf("%d",&tc);
  for(int x=1;x<=tc;x++){
    printf("Case #%d: ",x);
    scanf("%d %d %d %d",&N,&M,&S,&T);
    adj.clear();
    adj.resize(N);
    dist.assign(N,INF);
    for(int i=0;i<M;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      adj[a].push_back(ii(b,c));
      adj[b].push_back(ii(a,c));
    }
    dijkstra();
    if(dist[T] == INF) printf("unreachable\n");
    else printf("%d\n",dist[T]);
  }
}
