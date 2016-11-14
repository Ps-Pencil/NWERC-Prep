//https://uva.onlinejudge.org/external/104/10449.pdf
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> busy;
#define INF 1000000000
int n;
typedef pair<int,int> ii;
vector<vector<ii> > adj;

vector<int> dist;
vector<int> cnt;
vector<bool> inq;
vector<bool> neg;

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
    if(n==m && n == 0)
      {
        while(qs--) {scanf("%*d");printf("?\n");}
        continue;
      }
    queue<int> q;
    dist.assign(n+1,INF);
    cnt.assign(n+1,0);
    inq.assign(n+1,0);
    neg.assign(n+1,0);
    q.push(1);dist[1]=0;
    cnt[1]=1;
    if(n!=0)
    while(!q.empty()){
      int a = q.front();q.pop();
      inq[a] = 0;
      for(ii i : adj[a]){
        if(dist[a]+i.second < dist[i.first]){
          dist[i.first]=dist[a]+i.second;
          if(!inq[i.first])
          {
            if(++cnt[i.first]>n){
              // printf("%d is neg\n",i.first);
              queue<int> nq;
              nq.push(i.first);
              neg[i.first]=1;
              dist[i.first]=-INF;
              while(!nq.empty()){
                int x = nq.front();nq.pop();
                // printf("%d is neg\n",x);
                for(ii k:adj[x]){
                  if(!neg[k.first]){
                    neg[k.first]=1;
                    nq.push(k.first);
                    dist[k.first] = -INF;
                  }
                }
              }
            }
            else if(!neg[i.first]){
              inq[i.first]=1;
              q.push(i.first);
            }
          }
        }
      }
    }
    while(qs--){
      int x;
      scanf("%d",&x);
      if(x<=0 || x > n || neg[x] || dist[x] < 3 || dist[x] == INF || n==0) printf("?\n");
      else printf("%d\n",dist[x]);
    }
  }
}
