//https://uva.onlinejudge.org/external/8/820.pdf


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
int n,m;
int res[200][200],mf,f,s,t;
vi p;
void augment(int v, int minEdge){
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;}
}
// inside main
int main(){
  int tc=1;
  while(scanf("%d",&n),n){
    memset(res,0,sizeof(res));
    int c;
    scanf("%d %d %d",&s,&t,&c);
    for(int i=0;i<c;i++){
      int a,b,x;
      scanf("%d %d %d",&a,&b,&x);
      res[a][b] += x;
      res[b][a] += x;
    }
    MAX_V=n+1;
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
    printf("Network %d\nThe bandwidth is %d.\n\n",tc++,mf);
  }
}
