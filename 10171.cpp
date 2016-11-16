//https://uva.onlinejudge.org/external/101/10171.pdf

#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n;
typedef pair<int,int> ii;
vector<vector<ii> > adj;
vector<vector<ii> > adjy;
set<int> junct;
int s, t;


#define INF 1000000000
vector<int> dist;
vector<int> distr;
void dijkstra(){
  dist.assign(200,INF);
  dist[s] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adjy[u].size(); j++) {
      ii v = adjy[u][j]; // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
      }
    }
  } // this variant can cause duplicate items in the priority queue
}
void dijkstra_r(){
  distr.assign(200,INF);
  distr[t] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, t)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > distr[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adj[u].size(); j++) {
      ii v = adj[u][j]; // all outgoing edges from u
      if (distr[u] + v.second < distr[v.first]) {
        distr[v.first] = distr[u] + v.second; // relax operation
        pq.push(ii(distr[v.first], v.first));
      } } } // this variant can cause duplicate items in the priority queue
}
int main(){
  int tc = 0;
  while(scanf("%d",&n),n){
    // if(++tc==100) printf("%d\n",n);
  adj.clear();
  adj.resize(200);
  adjy.clear();
  adjy.resize(200);
  junct.clear();
  for(int i=0;i<n;i++){
  char y,d,a,b;
      int w;
      scanf(" %c %c %c %c %d",&y,&d,&a,&b,&w);
      junct.insert(a);
      junct.insert(b);
      // if(tc==100)
      // printf("%c %c %c %c %d\n",y,d,a,b,w);
      if(y == 'Y'){
        adjy[a].push_back(ii(b,w));
        if(d == 'B'){
          adjy[b].push_back(ii(a,w));
        }
      }
      else{
        adj[a].push_back(ii(b,w));
        if(d == 'B'){
          adj[b].push_back(ii(a,w));
        }
      }
    }
    scanf(" %c %c",&s,&t);
    junct.insert(s);junct.insert(t);
    dijkstra();dijkstra_r();
    // if(tc==100) printf("%c %d %c %d\n",s,dist[s],t,distr[t]);
    int best = INF; vector<char> bestcity;
    for(auto i : junct){
      if(dist[i]+distr[i] < best){
        best = dist[i]+distr[i];
        bestcity.clear();
        bestcity.push_back(i);
      }
      else if(dist[i]+distr[i] == best)
        bestcity.push_back(i);
    }
    if(best == INF){
      printf("You will never meet.\n");
    }
    else{
      printf("%d",best);
      for(char f : bestcity){
        printf(" %c",f);
      }
      putchar('\n');
    }
  }
}
