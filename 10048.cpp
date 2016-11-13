//https://uva.onlinejudge.org/external/100/10048.pdf

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int m,n;
typedef pair<int,int> ii;
priority_queue<pair<int,ii>, vector<pair<int,ii> >, greater<pair<int,ii> > > q;
int C[200001];
int ra[200001];
int find(int i){
  return (C[i]==i)?i:C[i]=find(C[i]);
}
int u(int i, int j){
  if(ra[i] == ra[j]){
    C[i] = j;
    ra[j]++;
  }
  else if(ra[i]<ra[j])
    C[i]=j;
  else
    C[j]=i;
}
int sssp[101][101];
vector<ii> adj[200];
void dfs(int source, int s, int maxdb){
  sssp[source][s] = maxdb;
  for(ii nxt : adj[s]){
    if(sssp[source][nxt.second]==-1)
      dfs(source,nxt.second,max(maxdb,nxt.first));
  }
}
int main(){
  int Q;
  int testcase = 1;
  while(scanf("%d %d %d",&n,&m,&Q),m+n+Q){
    while(!q.empty())q.pop();
    if(testcase != 1) printf("\n");
    printf("Case #%d\n",testcase++);
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      q.push(make_pair(c,ii(a,b)));
    }
    for(int i=1;i<=n;i++) C[i]=i;
    for(int i=1;i<=n;i++) ra[i]=1;

    for(int i=1;i<=n;i++) adj[i].clear();
    int counter = n;
    while(( counter != 1 ) && ( !q.empty() )){
        auto a = q.top();q.pop();
        if(find(a.second.first) == find(a.second.second)) {
          continue;
        }
        counter --;
        // printf("taking edge %d %d\n",a.second.first,a.second.second);
        adj[a.second.first].push_back(ii(a.first,a.second.second));
        adj[a.second.second].push_back(ii(a.first,a.second.first));
        u(find(a.second.first),find(a.second.second));
    }
    memset(sssp,-1,sizeof(sssp));
    for(int i=1;i<=n;i++){
      dfs(i,i,0);
    }
    for(int i=0;i<Q;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      if(sssp[a][b] == -1)
        printf("no path\n");
      else
        printf("%d\n",sssp[a][b]);
    }
  }
}
