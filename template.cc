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
