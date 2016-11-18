//https://uva.onlinejudge.org/external/104/10449.pdf
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> busy;
#define INF 2000000000
int n;
typedef pair<int,int> ii;
vector<vector<ii> > adj;

vector<int> dist;

int main(){
  int tc = 1;
  while(scanf("%d",&n)!=EOF){
    printf("Set #%d\n",tc++);
    busy.clear();
    adj.clear();
    adj.resize(n+1);
    busy.push_back(0);
    for(int i=0;i<n;i++)
      {
        int x;
        scanf("%d",&x);
        busy.push_back(x);
      }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      // printf("Edge %d %d %d\n",a,b,( busy[b]-busy[a] )*( busy[b]-busy[a] )*( busy[b]-busy[a] ));
      adj[a].push_back(ii(b,( busy[b]-busy[a] )*( busy[b]-busy[a] )*( busy[b]-busy[a] )));
    }
    int qs;
    scanf("%d",&qs);
    queue<int> q;
    dist.assign(n+1,INF);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
      for(int j=0;j<adj.size();j++){
        for(ii k : adj[j]){
          if(dist[k.first] > dist[j]+k.second){
            dist[k.first]=dist[j]+k.second;
          }
        }
      }
    }
    queue<int> neg;
    vector<int> vis(n+1,0);
    for(int j=0;j<adj.size();j++){
      for(ii k : adj[j]){
        if(dist[k.first] > dist[j]+k.second){
          dist[k.first]=dist[j]+k.second;
          neg.push(k.first);
          vis[k.first]=1;
        }
      }
    }
    while(!neg.empty()){
      int a = neg.front();neg.pop();
      dist[a] = -1;
      for(ii e : adj[a]){
        if(!vis[e.first]){
          vis[e.first]=1;
          neg.push(e.first);
        }
      }
    }
    while(qs--){
      int x;
      scanf("%d",&x);
      if(x<=0 || x > n || dist[x] < 3 || dist[x] >= INF/2 || n==0) printf("?\n");
      else printf("%d\n",dist[x]);
    }
  }
}
