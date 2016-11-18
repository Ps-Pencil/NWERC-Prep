//https://uva.onlinejudge.org/external/119/11906.pdf
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int r,c,m,n;
int w;
int water[105][105];
int even,odd;
int vis[105][105];
bool valid(int x, int y){
  return !(x<0 || x >= c || y<0||y>=r||water[y][x]);
}
void dfs(int x, int y, vector<int> dx, vector<int> dy){
  // printf("%d %d %d %d\n",x,y,valid(x,y),water[y][x]);
  if(!vis[y][x]){
    vis[y][x] = 1;
    int out = 0;
    for(int i=0;i<dx.size();i++){
      if(valid(x+dx[i],y+dy[i])){
        out++;
        if(!vis[y+dy[i]][x+dx[i]])
          dfs(x+dx[i],y+dy[i],dx,dy);
      }
    }
    if(out % 2 == 0)
      even++;
    else
      odd++;
  }
}
int main(){
  int T;
  scanf("%d",&T);
  for(int x=1;x<=T;x++){
    memset(vis,0,sizeof(vis));
    memset(water,0,sizeof(water));
    even=odd=0;
    printf("Case %d: ",x);
    scanf("%d %d %d %d",&r,&c,&m,&n);
    int dx[] = {m,m,n,n,-m,-m,-n,-n};
    int dy[] = {n,-n,m,-m,n,-n,m,-m};
    vector<int> vdx(dx,dx+8), vdy(dy,dy+8);
    if(m == 0 || n==0){
      vdx.clear();
      vdy.clear();
      n = m == 0?n:m;
      vdx.push_back(0);
      vdy.push_back(n);
      vdx.push_back(0);
      vdy.push_back(-n);
      vdx.push_back(n);
      vdy.push_back(0);
      vdx.push_back(-n);
      vdy.push_back(0);
    }
    else if(m == n){
      vdx.clear();
      vdy.clear();
      vdx.push_back(m);
      vdy.push_back(m);
      vdx.push_back(m);
      vdy.push_back(-n);
      vdx.push_back(-n);
      vdy.push_back(n);
      vdx.push_back(-n);
      vdy.push_back(-m);
    }
    scanf("%d",&w);
    for(int i=1;i<=w;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      water[a][b] = 1;
    }
    dfs(0,0,vdx,vdy);
    printf("%d %d\n",even,odd);
  }
}
