//https://uva.onlinejudge.org/external/2/259.pdf

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef vector<int> vi;
#define INF 1000000000
#define MAX_V 40
using namespace std;
int res[MAX_V][MAX_V],mf,f,s,t;
vi p;
void augment(int v, int minEdge){
  // printf("augment v %d, p[v] %d, s %d\n",v,p[v],s);
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {
    // printf("going back from %d to %d\n",v,p[v]);
    augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;
  }
}
int main(){
  s = 38,t=39;
  while(cin){
    int total = 0;
    memset(res,0,sizeof(res));
    while(true){
      string str;
      getline(cin,str);
      // cout<<str<<endl;
      if(str=="") break;
      int u = str[0]-'A';
      int n = 0;
      int i = 1;
      while(str[i]!=' '){
        n*=10;
        n+=str[i]-'0';
        i++;
      }
      res[s][u] = n;
      // printf("%d %d\n",u,n);
      total += n;
      i++;
      while(str[i]!=';'){
        int v = str[i]-'0';
        res[u][v+26]=1;
        i++;
      }
    }
    for(int i=0;i<10;i++) res[i+26][t] = 1;
    mf = 0;
    while(1){
      f = 0;
      vi dist(MAX_V,INF);dist[s]=0;queue<int> q;q.push(s);
      p.assign(MAX_V,-1);
      while(!q.empty()){
        int u = q.front();q.pop();
        if(u == t) break;
        for(int v=0;v < MAX_V;v++)
          {
            if(res[u][v]>0 && dist[v]==INF){
              // printf("%d->%d %d\n",u,v,res[u][v]);
              dist[v]=dist[u]+1;q.push(v);p[v]=u;
            }
          }
      }
      augment(t,INF);
      // printf("%d\n",f);
      // for(int i=0;i<MAX_V;i++){
      //   for(int j=0;j<MAX_V;j++){
      //     if(res[i][j]!=0)
      //       // printf("%d %d: %d\n",i,j,res[i][j]);
      //   }
      // }
      if(f==0) break;
      mf+=f;
    }
    // printf("%d\n",mf);
    if(mf < total) printf("!\n");
    else{
      for(int i=0;i<10;i++){
        int c = -1;
        for(int j=0;j<26;j++){
          if(res[i+26][j] > 0){
            c = j;
            break;
          }
        }
        if(c!=-1) putchar(c+'A');
        else putchar('_');
      }
      putchar('\n');
    }
  }
}
