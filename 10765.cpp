//https://uva.onlinejudge.org/external/107/10765.pdf

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[10010];
int n,m;
int num[10010],low[10010];
int counter;
priority_queue<pair<int,int> > values;
int dfs(int s, int p){
  // printf("dfs called with %d %d\n",s,p);
  num[s]=low[s]=counter++;
  int val = p == -1 ? 0:1;
  for(int i: adj[s]){
    // printf("children of %d, %d, num %d\n",s,i,num[i]);
    if(num[i]==-1){
      dfs(i,s);
      if(low[i]>=num[s]){
        val++;
      }
      low[s]=min(low[s],low[i]);
    }
    else if(i != p)
      low[s]=min(low[s],num[i]);
  }
  // printf("inserting %d %d\n",val,s);
  // descending in val, ascending in s
  values.push(pair<int,int>(val,n-s));
}
int main(){
  while(scanf("%d %d",&n,&m),n+m){
    for(int i=0;i<n;i++) adj[i].clear();
    int a,b;
    while(!values.empty()) values.pop();
    while(scanf("%d %d",&a,&b),a>=0){
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    dfs(0,-1);
    for(int i=0;i<m;i++){
      pair<int,int> x = values.top();values.pop();
      printf("%d %d\n",n-x.second,x.first);
    }
    printf("\n");
  }
}
