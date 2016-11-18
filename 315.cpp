//https://uva.onlinejudge.org/external/3/315.pdf

#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#define debug(A,B) {for(int index=1;index<=B;index++)printf("%d ",A[index]);printf("\n");}
using namespace std;

int N;
vector<int> adj[120];
int dfs_num[120];
int dfs_low[120];
int counter=0;

int vis[200];
int rootchild=0;
bool crit[200];
bool contains(int x, int y){
  for(int i:adj[x])
    if(i==y)
      return true;
  return false;
}
int dfs(int s, int parent){
  dfs_low[s]=dfs_num[s]=counter++;
  bool flag = false;
  for(int i:adj[s]){
    if(dfs_num[i] == -1){
      if(s==1) rootchild++;
      dfs_low[s] = min(dfs_low[s], dfs(i,s));
      if(dfs_low[i]>=dfs_num[s]) flag=true;
    }
    else if(i!=parent)
      dfs_low[s] = min(dfs_low[s],dfs_num[i]);
  }
  if( (rootchild>1 || parent != 0) && flag )
    crit[s]=1;
  return dfs_low[s];
}
int artp(int s){
  for(int i:adj[s])
    if(dfs_low[i]>=dfs_num[s])
      return true;
  return false;
}
int main(){
  while(scanf("%d ",&N),N){
    for(int i=1;i<=N;i++) adj[i].clear();
    string s;
    // cout<<s<<endl;
    int x;
    while(true){
      getline(cin,s);
      istringstream is(s);
      // cout<<s<<endl;
      is>>x;
      if(x == 0) break;
      // printf("%d\n",x);
      int y;
      while(!is.eof()){
        is>>y;
        if(!contains(x,y))
          adj[x].push_back(y);
        if(!contains(y,x))
          adj[y].push_back(x);
        // printf("%d %d\n",x,y);
      }
    }
    memset(vis,0,sizeof(vis));
    memset(dfs_num,-1,sizeof(dfs_num));
    memset(crit,0,sizeof(crit));
    counter = 1;
    rootchild=0;
    dfs(1,0);
    // debug(dfs_num,N);
    // debug(dfs_low,N);
    int ret = 0;
    for(int i=1;i<=N;i++)
      ret += crit[i];
    printf("%d\n",ret);
  }
}
