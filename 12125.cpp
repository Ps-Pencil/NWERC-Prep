//https://uva.onlinejudge.org/external/121/12125.pdf


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
int res[300][300],mf,f,s,t;
int initial[300][300];
struct pt{
  int x,y;
};
vi p;
int MAX_V;
void augment(int v, int minEdge){
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;}
}
vector<pt> pts;
#define in(x) (2*(x))
#define out(x) (2*(x)+1)
bool near(pt a, pt b, double d){
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) < d*d;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    memset(initial,0,sizeof(initial));
    pts.clear();
    int num=0;;
    int N;double D;
    scanf("%d %lf",&N,&D);
    s = 2*N;MAX_V = s+1;
    for(int i=0;i<N;i++){
      int x,y,n,m;
      scanf("%d %d %d %d",&x,&y,&n,&m);
      initial[in(i)][out(i)] = m;
      initial[s][in(i)] = n;
      num += n;
      struct pt p;
      p.x = x;p.y = y;
      pts.push_back(p);
    }
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if(near(pts[i],pts[j],D)){
          // printf("%d <-> %d\n",i,j);
          initial[out(i)][in(j)] = INF;
          initial[out(j)][in(i)] = INF;
        }
      }
    }
    // printf("initial\n");
    // for(int i=0;i<MAX_V;i++){
    //   for(int j=0;j<MAX_V;j++){
    //     if(initial[i][j]!=0){
    //       printf("%d %s->%d %s: %d\n",i/2,i%2==0?"in":"out",j/2,j%2==0?"in":"out",initial[i][j]);
    //     }
    //   }
    // }
    vector<int> ans;
    for(int i=0;i<N;i++){
      for(int j=0;j<MAX_V;j++)
        for(int k=0;k<MAX_V;k++)
          res[j][k] = initial[j][k];
      t = in(i);
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
        // printf("f=%d\n",f);
        // for(int i=0;i<MAX_V;i++){
        //   for(int j=0;j<MAX_V;j++){
        //     if(res[i][j]!=0){
        //       printf("%d %s->%d %s: %d\n",i/2,i%2==0?"in":"out",j/2,j%2==0?"in":"out",res[i][j]);
        //     }
        //   }
        // }
        if(f==0) break;
        mf+=f;
      }
      if(mf == num) ans.push_back(i);
    }
    if(ans.size() == 0)
      printf("-1\n");
    else{
      printf("%d",ans[0]);
      for(int i=1;i<ans.size();i++){
        printf(" %d",ans[i]);
      }
      printf("\n");
    }
  }
}
