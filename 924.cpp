//https://uva.onlinejudge.org/external/9/924.pdf

#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;

int N;
vector<vector<int> > adj;
void bfs(int source, int& maxb,int& maxd){
  vector<int> boom(N,0);
  vector<int> vis(N,0);
  queue<pair<int,int> > q;
  q.push(make_pair(0,source));
  boom[0]=-1;
  while(!q.empty()){
    auto a = q.front();q.pop();
    if(vis[a.second]) continue;
    // printf("%d %d\n",a.second,a.first);
    boom[a.first]++;
    vis[a.second] = 1;
    for(int k:adj[a.second]){
      // printf("%d-%d\n",a.second,k);
      if(!vis[k])
        q.push(make_pair(a.first+1,k));
    }
  }
  for(int i=0;i<N;i++){
    if(maxb < boom[i]){
      maxb = boom[i];
      maxd = i;
    }
  }
}
int main(){
  scanf("%d ",&N);
  adj.resize(N);
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    while(x--){
      int y;
      cin>>y;
      adj[i].push_back(y);
    }
  }
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    int s;
    cin>>s;
    int maxb=0,maxd=0;
    bfs(s,maxb,maxd);
    if(maxd == 0) printf("0\n");
    else printf("%d %d\n",maxb,maxd);
  }
}
