//https://uva.onlinejudge.org/external/10/1056.pdf
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

vector<string> i2s;
map<string,int> s2i;
int n,m;
vector<vector<int> > adj;
vector<vector<int> > dist;
#define INF 1000000000
void bfs(int s){
  dist[s][s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int a = q.front();q.pop();
    for(int b : adj[a]){
      if(dist[s][b] == INF){
        dist[s][b] = dist[s][a]+1;
        q.push(b);
      }
    }
  }
}
int main(){
  int tc = 1;
  while(scanf("%d %d",&n,&m),n+m){
    i2s.clear();s2i.clear();adj.clear();dist.clear();
    int counter = 0;
    adj.resize(n);
    for(int i=0;i<m;i++){
      string s1,s2;
      cin>>s1>>s2;
      if(s2i.find(s1) == s2i.end()){
        i2s.push_back(s1);
        s2i[s1]=counter;
        counter++;
      }
      if(s2i.find(s2) == s2i.end()){
        i2s.push_back(s2);
        s2i[s2]=counter;
        counter++;
      }
      adj[s2i[s1]].push_back(s2i[s2]);
      adj[s2i[s2]].push_back(s2i[s1]);
    }
    dist.assign(n,vector<int>(n,INF));
    for(int i=0;i<n;i++)
      bfs(i);
    int maxd = 0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(dist[i][j] > maxd){
          maxd = dist[i][j];
        }
      }
    }
    printf("Network %d: ",tc++);
    if(maxd == INF) printf("DISCONNECTED\n\n");
    else printf("%d\n\n",maxd);
  }
}
