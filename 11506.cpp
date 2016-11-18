//https://uva.onlinejudge.org/external/115/11506.pdf


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
int res[300][300],mf,f,s,t;
vi p;
void augment(int v, int minEdge){
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;}
}
// inside main
#define in(x) x
#define out(x) (x==s||x==t?x:(M+( x )))
int main(){
  int M,W;
  while(scanf("%d %d",&M,&W),M+W){
    s = 1;t=M;MAX_V = t+M;
    memset(res,0,sizeof(res));
    for(int i=0;i<M-2;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      res[in(a)][out(a)] = b;
    }
    for(int i=0;i<W;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      res[out(a)][in(b)] = c;
      res[out(b)][in(a)] = c;
    }
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
