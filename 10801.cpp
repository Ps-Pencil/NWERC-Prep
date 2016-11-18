// https://uva.onlinejudge.org/external/108/10801.pdf

#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 2000000000
int n,k;
vector<int> t;
vector<vii> adj;
vector<int> dist;
#define in(A) (2*( A ))
#define out(A) (2*( A )+1)
void dijkstra(){
  dist[out(0)] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, out(0))); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    // printf("floor %d %s at time %d\n",front.second/2,front.second%2==0?"in":"out",front.first);
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
  while(scanf("%d %d",&n,&k)!=EOF){
    // printf("%d %d\n",n,k);
    t.assign(n,0);
    for(int i=0;i<n;i++){
      int x;
      scanf("%d",&x);
      t[i]=x;
    }
    adj.clear();
    adj.resize(200);
    for(int i=0;i<n;i++){
      // parse the line breaks
      scanf(" ");
      string s;
      getline(cin,s);
      istringstream iss(s);
      vector<int> v;
      while(!iss.eof()){
        int x;
        iss>>x;
        v.push_back(x);
      }
      for(int j=0;j<v.size();j++){
        for(int k=j+1;k<v.size();k++){
          adj[out(v[j])].push_back(ii(in(v[k]),t[i]*(v[k]-v[j])));
          adj[out(v[k])].push_back(ii(in(v[j]),t[i]*(v[k]-v[j])));
        }
      }
    }
    if(k==0) {printf("0\n");continue;}
    for(int i=0;i<100;i++)
      adj[in(i)].push_back(ii(out(i),60));
    dist.assign(200,INF);
    dijkstra();
    if(dist[in(k)] == INF) printf("IMPOSSIBLE\n");
    else printf("%d\n",dist[in(k)]);
  }
}
