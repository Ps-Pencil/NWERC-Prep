//https://uva.onlinejudge.org/external/3/314.pdf

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int grid[50][50];
int r,c;
int abs(int a){
  return a<0?-a:a;
}
struct pt{
  int r,c;
  pt(int r,int c) : r(r),c(c){}
  pt(){}
};
pt s,t;
int d;
//          U R D L
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool operator == (pt a, pt b){
  return a.r == b.r && a.c == b.c;
}
struct state{
  int d;
  pt p;
  int t;
  state(int d, pt p, int t):d(d),p(p),t(t){}
};
bool valid(pt x){
  return x.r >= 0 && x.r < r && x.c >=0 && x.c < c && grid[x.r][x.c]!=1;
}
int bfs(){
  int vis[50][50][4];
  memset(vis,0,sizeof(vis));
  vis[s.r][s.c][d]=1;
  queue<state> q;
  q.push(state(d,s,0));
  while(!q.empty()){
    auto a = q.front();q.pop();
    // for(int i=0;i<r+1;i++){ for(int j=0;j<c+1;j++)printf("%d ",grid[i][j]); putchar('\n');}
    // printf("direction %d point %d,%d time %d\n",a.d,a.p.r,a.p.c,a.t);
    if(a.p == t) return a.t;
    for(int k=1;k<=3;k++){
      pt x = a.p;
      x.r += dr[a.d]*k;
      x.c += dc[a.d]*k;
      if(valid(x) && !vis[x.r][x.c][a.d]){
        q.push(state(a.d,x,a.t+1));
        vis[x.r][x.c][a.d]=1;
      }
      else if(!valid(x)) break;
    }
    int newd = (a.d+1)%4;
    if(!vis[a.p.r][a.p.c][newd])
      {
        q.push(state(newd,a.p,a.t+1));
        vis[a.p.r][a.p.c][newd]=1;
      }
    newd = (a.d+3)%4;
    if(!vis[a.p.r][a.p.c][newd])
      {
        q.push(state(newd,a.p,a.t+1));
        vis[a.p.r][a.p.c][newd]=1;
      }
  }
  return -1;
}
int main(){
  while(scanf("%d %d",&r,&c),r+c){
    memset(grid,0,sizeof(grid));
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        int x;
        scanf("%d",&x);
        if(x){
          grid[i][j]=1;
          grid[i+1][j]=1;
          grid[i][j+1]=1;
          grid[i+1][j+1]=1;
        }
      }
    }
    // for(int i=0;i<r+1;i++){ for(int j=0;j<c+1;j++)printf("%d ",grid[i][j]); putchar('\n');}
    for(int i=0;i<r+1;i++)
      grid[i][0]=1;
    for(int j=0;j<c+1;j++)
      grid[0][j]=1;
    scanf("%d %d %d %d",&s.r,&s.c,&t.r,&t.c);
    char str[10];
    scanf("%s",str);
    switch(str[0]){
    case 'n':
      d=0;
      break;
    case 'e':
      d=1;
      break;
    case 's':
      d=2;
      break;
    case 'w':
      d=3;
      break;
    }
    printf("%d\n",bfs());
  }
}
