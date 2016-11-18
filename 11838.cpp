//https://uva.onlinejudge.org/external/118/11838.pdf

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
int main(){
  while(scanf("%d %d",&n,&m),n+m){
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    memset(visited,0,sizeof(visited));
    counter = 0;
    S.clear();
    total = 0;
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      adj[a].push_back(b);
      if(c==2)
        adj[b].push_back(a);
      // printf("%d %d %d %d %d\n",i,m,a,b,c);
    }
    for(int i=1;i<=n;i++)
      if(num[i]==-1)
        scc(i);
    if(total > 1) printf("0\n");
    else printf("1\n");
  }
}
