//https://uva.onlinejudge.org/external/114/11492.pdf

#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

map<string,vector<string> > l2w;
map<string,vector<string> > w2l;
map<string,int> w2i;
vector<string> i2w;
set<string> lang;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 2000000000
vector<vii> adj;
vector<int> dist;
#define in(A) (2*( A ))
#define out(A) (2*( A )+1)
int n,s,t;
string startL,endL;
void dijkstra(){
  dist[s] = 0; // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s)); while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    // printf("visiting word %s %s distance %d\n",i2w[front.second/2].c_str(),front.second%2==0?"in":"out",front.first);
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check
    for (int j = 0; j < (int)adj[u].size(); j++) {
      ii v = adj[u][j]; // all outgoing edges from u
      // printf("from %s to %s\n",i2w[front.second/2].c_str(),i2w[v.first/2].c_str());
      if (dist[u] + v.first < dist[v.second]) {
        dist[v.second] = dist[u] + v.first; // relax operation
        pq.push(ii(dist[v.second], v.second));
      }
    }
  }
}
int main(){
  while(scanf("%d",&n),n){
    l2w.clear();w2l.clear();w2i.clear();i2w.clear();adj.clear();dist.clear();lang.clear();
    cin>>startL>>endL;
    string s1,s2,s3;
    i2w.resize(n);
    for(int i=0;i<n;i++){
      cin>>s1>>s2>>s3;
      l2w[s1].push_back(s3);
      l2w[s2].push_back(s3);
      w2l[s3].push_back(s1);
      w2l[s3].push_back(s2);
      lang.insert(s1);
      lang.insert(s2);
      w2i[s3]=i;
      i2w[i]=s3;
    }
    adj.resize(2*n+2);
    s = 2*n; t = 2*n+1;
    for(string l : lang){
      vector<string> & words = l2w[l];
      for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
          if(words[i][0] != words[j][0])
            {
              adj[out(w2i[words[i]])].push_back(ii(0,in(w2i[words[j]])));
              adj[out(w2i[words[j]])].push_back(ii(0,in(w2i[words[i]])));
            }
        }
      }
    }
    for(int i=0;i<n;i++){
      adj[in(i)].push_back(ii(i2w[i].size(),out(i)));
    }
    for(string ss:l2w[startL]){
      // printf("starting word %s, integer %d, %s\n",ss.c_str(),w2i[ss],i2w[w2i[ss]].c_str());
      adj[s].push_back(ii(0,in(w2i[ss])));
    }
    for(string s:l2w[endL]){
      // printf("ending word %s\n",s.c_str());
      adj[out(w2i[s])].push_back(ii(0,t));
    }
    dist.assign(2*n+2,INF);
    dijkstra();
    if(dist[t] == INF) printf("impossivel\n");
    else printf("%d\n",dist[t]);
  }
}
