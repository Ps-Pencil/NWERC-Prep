// union-find MST
#include <queue>
#include <cstring>
#include <algorithm>
typedef pair<int,int> ii;
priority_queue<pair<int,ii>, vector<pair<int,ii> >, greater<pair<int,ii> > > q;
int C[200001];
int ra[200001];
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
int main(){
  while(!q.empty())q.pop();
  for(int i=0;i<n;i++) C[i]=i;
  for(int i=0;i<n;i++) ra[i]=1;
  int counter = n;
  while((!q.empty()) && counter != 1){
    auto a = q.top();q.pop();
    if(find(a.second.first) == find(a.second.second)) {
      continue;
    }
    counter--;
    // do stuff
    u(find(a.second.first),find(a.second.second));
  }
}
//floodfill
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void fill(int x, int y, int from, int to){
  if(x < 0 || x >= w || y < 0 || y >= h || graph[y][x] != from){
    return;
  }
  graph[y][x] = to;
  for(int i=0;i<4;i++)
    fill(x+dx[i],y+dy[i],from,to);
}
//dijkstra
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 2000000000
vector<vii> adj;
vector<int> dist;
vi dist(V, INF); dist[s] = 0; // INF = 1B to avoid overflow
priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s)); while (!pq.empty()) { // main loop
  ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
  int d = front.first, u = front.second;
  if (d > dist[u]) continue; // this is a very important check
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j]; // all outgoing edges from u
    if (dist[u] + v.second < dist[v.first]) {
      dist[v.first] = dist[u] + v.second; // relax operation
      pq.push(ii(dist[v.first], v.first));
    } } } // this variant can cause duplicate items in the priority queue
// Edmond Karp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef vector<int> vi;
#define INF 1000000000
int MAX_V;
int res[2000][2000],mf,f,s,t;
vi p;
void augment(int v, int minEdge){
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;}
}
// inside main
mf = 0;
while(1){
  f = 0;
  vi dist(MAX_V,INF);dist[s]=0;queue<int> q;q.push(s);
  p.assign(MAX_V,-1);
  while(!q.empty()){
    int u = q.front();q.pop();
    if(u == t) break;
    for(int v=0;v < MAX_V;v++)
      if(res[u][v]>0 && dist[v]==INF){
        dist[v]=dist[u]+1;q.push(v);p[v]=u;
      }
  }
  augment(t,INF);
  if(f==0) break;
  mf+=f;
 }
