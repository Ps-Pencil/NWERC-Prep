//https://uva.onlinejudge.org/external/5/558.pdf

#include <cstdio>
#include <vector>
using namespace std;
struct edge{
  int u,v,w;
  edge(int u, int v, int w):u(u),v(v),w(w){}
};
vector<edge> E;
#define INF 2000000000
int n,m;
vector<int> dist;
int main(){
  int tc;
  scanf("%d",&tc);
  while(tc--){
    E.clear();
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      E.push_back(edge(a,b,c));
    }
    dist.assign(n,INF);
    dist[0]=0;
    for(int i=0;i<n-1;i++){
      for(auto e:E){
        if(dist[e.v] < dist[e.u]+e.w)
          dist[e.v] = dist[e.u]+e.w;
      }
    }
    int negativecycle = 0;
    for(auto e:E){
      // printf("Edge %d %d %d, dist %d %d\n",e.u,e.v,e.w,dist[e.u],dist[e.v]);
      if(dist[e.v] > dist[e.u]+e.w)
        {
          negativecycle=1;
          break;
        }
    }
    printf("%s\n",negativecycle?"possible":"not possible");

  }
}
