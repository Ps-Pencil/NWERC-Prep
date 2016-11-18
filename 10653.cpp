//https://uva.onlinejudge.org/external/106/10653.pdf

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int R,C;
struct pt{
  int col,row;
};
bool operator == (pt a, pt b){
  return a.row == b.row && a.col == b.col;
}
int grid[1000][1000];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
pt s,t;
int bfs(){
  int visited[1000][1000];
  memset(visited,0,sizeof(visited));
  queue<pair<int,pt> > q;
  q.push(make_pair(0,s));
  while(!q.empty()){
    auto a = q.front();q.pop();
    if(a.second == t) return a.first;
    if(visited[a.second.row][a.second.col]) continue;
    // printf("%d %d\n",a.second.row,a.second.col);
    visited[a.second.row][a.second.col] = 1;
    for(int i=0;i<4;i++){
      pt x = a.second;
      x.row += dx[i];
      x.col += dy[i];
      if(x.row >= 0 && x.row < R && x.col >=0 && x.col < C && grid[x.row][x.col] != 1)
        q.push(make_pair(a.first+1,x));
    }
  }
  return -1;
}
int main(){
  while(scanf("%d %d",&R,&C),R+C){
    memset(grid,0,sizeof(grid));
    int x;
    scanf("%d",&x);
    while(x--){
      int a,b;
      scanf("%d %d",&a,&b);
      while(b--){
        int y;
        scanf("%d",&y);
        grid[a][y] = 1;
      }
    }
    scanf("%d %d",&s.row,&s.col);
    scanf("%d %d",&t.row,&t.col);
    printf("%d\n",bfs());
  }
}
