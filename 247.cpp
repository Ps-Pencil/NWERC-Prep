//https://uva.onlinejudge.org/external/2/247.pdf

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
map<string,int> s2i;
string i2s[30];
int n,m;
vector<int> adj[50];
int num[100],low[100],visited[100];
vector<int> S;
int counter;
void scc(int s){
  // printf("%s\n",i2s[s].c_str());
  low[s] = num[s] = counter++;
  S.push_back(s);
  visited[s] = 1;
  for(int i:adj[s]){
    if(num[i]==-1)
      scc(i);
    if(visited[i])
      low[s]=min(low[s],low[i]);
    // printf("%s %s %d\n",i2s[s].c_str(),i2s[i].c_str(),low[s]);
  }
  // printf("%s %d %d\n",i2s[s].c_str(),low[s],num[s]);
  if(low[s] == num[s]){
    bool start = true;
    while(1){
      int v = S.back();S.pop_back();visited[v]=0;
      if(!start) printf(", ");
      printf("%s",i2s[v].c_str());
      start = false;
      if(v == s) break;
    }
    printf("\n");
  }
}
int main(){
  int index=1;
  while(scanf("%d %d",&n,&m),n+m){
    // printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
      adj[i].clear();
    if(index!=1) putchar('\n');
    printf("Calling circles for data set %d:\n",index++);
    s2i.clear();
    int x=0;
    for(int i=0;i<m;i++){
      string s1,s2;
      cin>>s1>>s2;
      // printf("%s %s\n",s1.c_str(),s2.c_str());
      if(s2i.find(s1)==s2i.end()){
        s2i[s1]=x;
        i2s[x++]=s1;
      }
      if(s2i.find(s2)==s2i.end()){
        s2i[s2]=x;
        i2s[x++]=s2;
      }
      if(find(adj[s2i[s1]].begin(),adj[s2i[s1]].end(),s2i[s2])==adj[s2i[s1]].end())
        adj[s2i[s1]].push_back(s2i[s2]);
    }
    // for(int i=0;i<n;i++)cout<<i<<i2s[i]<<endl;
    // debug(num,n);
    memset(num,-1,sizeof(num));
    memset(low,-1,sizeof(low));
    memset(visited,0,sizeof(visited));
    S.clear();
    counter = 0;
    for(int i=0;i<n;i++){
      if(num[i]==-1)
        {
          scc(i);
        }
    }
  }
}
