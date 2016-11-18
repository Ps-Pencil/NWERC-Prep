//https://uva.onlinejudge.org/external/115/11504.pdf

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}

vector<int> adj[100001];
int num[100001],low[100001],visited[100001];
vector<int> S;
int counter;
int n,m;
int total;
void scc(int s){
  low[s] = num[s] = counter++;
  S.push_back(s);
  visited[s] = 1;
  for(int i:adj[s]){
    if(num[i]==-1)
      scc(i);
    if(visited[i])
      low[s]=min(low[s],low[i]);
    // printf("inner %d %d %d\n",s,i,low[s]);
  }
  // printf("%d %d %d\n",s,low[s],num[s]);
  if(low[s] == num[s]){
    total++;
    while(1){
      int v = S.back();S.pop_back();visited[v]=0;
      low[v]=num[s];
      if(v == s) break;
    }
  }
}
int ind[100001];
int main(){
  int t;
  scanf("%d\n",&t);
  while(t--){
    memset(ind,0,sizeof(ind));
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    S.clear();
    memset(visited,0,sizeof(visited));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      if(find(adj[a].begin(),adj[a].end(),b)==adj[a].end())
        {
          adj[a].push_back(b);
        }
    }
    total = 0;
    counter = 0;
    for(int i=1;i<=n;i++){
      if(num[i]==-1)
        scc(i);
    }
    // for(int i=1;i<=n;i++)printf("low %d %d %d\n",i,num[i],low[i]);
    for(int i=1;i<=n;i++){
      for(int j:adj[i]){
        if(low[i]!=low[j]){
          // printf("%d %d %d\n",n,low[i],low[j]);
          ind[low[j]]++;
        }
      }
    }
    int ret= 0;
    for(int i=1;i<=n;i++){
      if(ind[low[i]] == 0){
        ret++;
        ind[low[i]]++;
      }
    }
    printf("%d\n",ret);
  }
}
