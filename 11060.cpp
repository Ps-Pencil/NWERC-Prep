//https://uva.onlinejudge.org/external/110/11060.pdf

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
int n,m;
vector<int> adj[200];
map<string,int> s2i;
string i2s[101];
int p[101];
bool contains(int a, int b){
  for(int i:adj[a]){
    if(i==b)
      return true;
  }
  return false;
}
int main(){
  int T = 1;
  while(scanf("%d",&n)!=EOF){
    s2i.clear();
    memset(p,0,sizeof(p));

    for(int i=0;i<n;i++){
      adj[i].clear();
      string s;
      cin>>s;
      i2s[i]=s;
      s2i[s]=i;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
      string s1,s2;
      cin>>s1>>s2;
      int u,v;
      u=s2i[s1];
      v=s2i[s2];
      // if(!contains(u,v)){
        adj[u].push_back(v);
        p[v]+=1;
      // }
    }
    printf("Case #%d: Dilbert should drink beverages in this order:",T++);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(p[j]==0){
          printf(" %s",i2s[j].c_str());
          for(int k:adj[j])
            p[k]--;
          p[j]=-1;
          break;
        }
      }
    }
    printf(".\n\n");
  }
}
