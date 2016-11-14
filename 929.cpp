//https://uva.onlinejudge.org/external/9/929.pdf

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int grid[1000][1000];
int vis[1000][1000];
#define INF 2100000000
struct pt{
  int r,c;
  pt(int r,int c) : r(r),c(c){}
  pt(){}
};
bool operator < (pt a, pt b){
  return false;
}
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
bool operator == (pt a, pt b){
  return a.r == b.r && a.c == b.c;
}
int dijkstra(){
  int dist[1000][1000];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      dist[i][j]=INF;
  priority_queue<pair<int,pt>, vector<pair<int,pt> >, greater<pair<int,pt> > > q;
  q.push(make_pair(grid[0][0],pt(0,0)));
  while(!q.empty()){
    auto a = q.top();q.pop();
    if(dist[a.second.r][a.second.c] < a.first) continue;
    // printf("%d %d %d\n",a.first,a.second.r,a.second.c);
    if(a.second == pt(n-1,m-1))
      return a.first;
    for(int i=0;i<4;i++){
      pt x = a.second;
      x.r += dr[i];
      x.c += dc[i];
      if(x.r >= 0 && x.r < n && x.c >=0 && x.c < m){
        if(dist[x.r][x.c] == INF){
          dist[x.r][x.c] = a.first+grid[x.r][x.c];
          q.push(make_pair(a.first + grid[x.r][x.c],x));
        }
      }
    }
  }
}
int main(){
  int tc;
  scanf("%d",&tc);
  while(tc--){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        scanf("%d",&grid[i][j]);
    memset(vis,0,sizeof(vis));
    printf("%d\n",dijkstra());
  }
}
