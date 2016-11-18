//https://uva.onlinejudge.org/external/11/1112.pdf

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N,E,T;
int M;
#define INF 2000000000
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adj;
vector<int> dist;

void dijkstra(){
  dist[E] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, E)); while (!pq.empty()) { // main loop
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
  bool blankline = false;
  while(tc--){
    if(blankline) putchar('\n');
    blankline = true;
    scanf("%d %d %d",&N,&E,&T);
    scanf("%d",&M);
    adj.clear();
    adj.resize(N+1);
    for(int i=0;i<M;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      adj[b].push_back(ii(a,c));
    }
    dist.assign(N+1,INF);
    dijkstra();
    int ret=0;
    for(int i=1;i<=N;i++){
      if(dist[i]<=T)
        ret++;
    }
    printf("%d\n",ret);
  }
}
