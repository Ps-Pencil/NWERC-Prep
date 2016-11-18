//https://uva.onlinejudge.org/external/4/429.pdf
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
vector<int> adj[300];
map<string,int> s2i;
vector<string> i2s;
int counter;
bool close(string s1, string s2){
  if(s1.size()!=s2.size()) return false;
  int diff = 0;
  for(int i=0;i<s1.size();i++)
    if(s1[i]!=s2[i]){
      diff++;
      if(diff>1)
        return false;
    }
  return true;
}
int bfs(int s, int t){
  if(s==t) return 0;
  queue<ii> q;
  vector<int> visited(counter,0);
  q.push(ii(0,s));
  while(!q.empty()){
    auto k = q.front();q.pop();
    visited[k.second]=1;
    for(auto i : adj[k.second])
      {
        if(i == t)
          return k.first+1;
        if(!visited[i])
          q.push(ii(k.first+1,i));
      }
  }
  return -1;
}
int main(){
  int T;
  cin>>T;
  for(int h=0;h<T;h++){
    if(h!=0) putchar('\n');
    s2i.clear();
    i2s.clear();
    string s;
    counter = 0;
    while(true){
      cin >> s;
      if(s == "*") break;
      i2s.push_back(s);
      s2i[s]=counter++;
    }
    for(int i=0;i<counter;i++)adj[i].clear();
    for(int i=0;i<counter;i++){
      for(int j=i+1;j<counter;j++)
        if(close(i2s[i],i2s[j])){
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
    }
    scanf(" ");
    while(!cin.eof()){
      string s1,s2;
      getline(cin,s);
      if(s=="") break;
      istringstream is(s);
      is>>s1>>s2;
      printf("%s %s %d\n",s1.c_str(),s2.c_str(),bfs(s2i[s1],s2i[s2]));
    }
  }
}
