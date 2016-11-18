//https://uva.onlinejudge.org/external/113/11380.pdf
#include<cstdio>
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
int X,Y,P;
char grid[40][40];
#define in(x) ((x)*2)
#define out(x) ((x)*2+1)
#define index(i,j) (((i)*Y)+(j))
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main(){
  while(scanf("%d %d %d",&X,&Y,&P)!=EOF)
    {
      memset(res,0,sizeof(res));
      for(int i=0;i<X;i++){
        scanf("%s",grid[i]);
      }
      s=X*Y*2;t=s+1;MAX_V=t+1;
      for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
          if(grid[i][j]!='~'){
            int vertex_cap = 0;
            switch(grid[i][j]){
            case '*':
              vertex_cap = 1;
              res[s][in(index(i,j))] = 1;
              break;
            case '.':
              vertex_cap = 1;
              break;
            case '@':
              vertex_cap = INF;
              break;
            case '#':
              vertex_cap = INF;
              res[out(index(i,j))][t] = P;
              break;
            }
            // printf("i %d j %d index %d in %d out %d s %d t %d\n",i,j,index(i,j),in(index(i,j)),out(index(i,j)),s,t);
            res[in(index(i,j))][out(index(i,j))]=vertex_cap;
          }
          for(int d=0;d<4;d++){
            int nx = i+dx[d];
            int ny = j+dy[d];
            if(nx >= 0 && ny >= 0 && nx <X && ny < Y){
              if(grid[nx][ny] != '~')
                res[out(index(i,j))][in(index(nx,ny))] = INF;
            }
          }
        }
      }
      // for(int i=0;i<MAX_V;i++){
      //   if(res[s][i] > 0) printf("s->%d %d\n",i,res[s][i]);
      // }
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
      printf("%d\n",mf);
    }
}
