//http://poj.org/problem?id=2449

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int M,N,S,T,K;
typedef pair<int,int> ii;
typedef pair<int,ii> pii;

vector<pair<int, int> > adj[1001];
vector<pair<int, int> > rev_adj[1001];
int dist[1001];
#define INF 2000000000
class compare{
public:
  bool operator()(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
  }
};
void dijkstra(){
  priority_queue<pair<int,int>,vector<pair<int,int> >,compare> q;
  for(int i=1;i<=N;i++) dist[i]=INF;
  dist[T]=0;
  q.push(pair<int,int>(T,0));
  while(!q.empty()){
    pair<int,int> x = q.top();q.pop();
    if(x.second > dist[x.first]) continue;
    // for(auto i : rev_adj[x.first]){
    for(int k=0;k<rev_adj[x.first].size();k++){ii i=rev_adj[x.first][k];
      if(dist[i.first] > dist[x.first] + i.second){
        dist[i.first] = dist[x.first]+i.second;
        q.push(pair<int,int>(i.first,dist[i.first]));
      }
    }
  }
}
int seen[1001];
int astar(){
  priority_queue<pair<int,pii>,vector<pii>,greater<pii> > q;
  q.push(pii(0+dist[S],ii(0,S)));
  while(!q.empty()){
    // auto cur = q.top();
    pii cur = q.top();
    // printf("%d %d %d %d\n",cur.first,cur.second.first,cur.second.second,seen[cur.second.second]);
    q.pop();
    seen[cur.second.second]++;
    if(seen[cur.second.second] == K && cur.second.second == T) return cur.second.first;
    if(seen[cur.second.second]>K) continue;
    // for(auto i : adj[cur.second.second]){
    for(int k=0;k<adj[cur.second.second].size();k++){ii i=adj[cur.second.second][k];
      // printf("pushing %d %d %d\n",i.first,i.second,dist[i.first]);
      q.push(pii(cur.second.first+dist[i.first]+i.second,ii(cur.second.first+i.second,i.first)));
    }
  }
}
int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    adj[a].push_back(pair<int,int>(b,c));
    rev_adj[b].push_back(pair<int,int>(a,c));
  }
  scanf("%d %d %d",&S,&T,&K);
  dijkstra();
  // Since we count from 0
  if(S==T)K++;
  printf("%d\n",astar());
}
