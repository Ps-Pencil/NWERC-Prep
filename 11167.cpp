//https://uva.onlinejudge.org/external/111/11167.pdf

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
typedef vector<int> vi;
#define INF 1000000000
int MAX_V;
int res[1000][1000],mf,f,s,t;
vi p;
void augment(int v, int minEdge){
  if(v==s) {f = minEdge;return;}
  else if(p[v] != -1) {augment(p[v],min(minEdge,res[p[v]][v]));res[p[v]][v]-=f;res[v][p[v]]+=f;}
}
// inside main
int n,m;
int main(){
  s=0;
  int tc = 1;
  while(scanf("%d",&n),n){
    memset(res,0,sizeof(res));
    int total = 0;
    vector<pair<int,int> > schedule(n+1);
    scanf("%d",&m);
    set<int> times;
    for(int i=1;i<=n;i++){
      int v,a,b;
      scanf("%d %d %d",&v,&a,&b);
      total += v;
      res[s][i] = v;
      schedule[i]=make_pair(a,b);
      times.insert(a);times.insert(b);
    }
    vector<pair<int,int> > n2i;
    map<pair<int,int>, int> i2n;
    int prev = -1;
    for(int a : times){
      if(prev!=-1){
        i2n[make_pair(prev,a)] = n2i.size();
        n2i.push_back(make_pair(prev,a));
      }
      prev = a;
    }
    t = n+1+n2i.size();
    MAX_V = t+1;
    for(int i=0;i<n2i.size();i++){
      for(int j=1;j<=n;j++){
        if(schedule[j].first<= n2i[i].first && schedule[j].second >= n2i[i].second){
          res[j][n+1+i] = n2i[i].second-n2i[i].first;
        }
      }
      res[n+1+i][t] = m*(n2i[i].second-n2i[i].first);
    }

    mf = 0;
    while(1){
      f = 0;
      vi dist(MAX_V,INF);dist[s]=0;queue<int> q;q.push(s);
      p.assign(MAX_V,-1);
      while(!q.empty()){
        int u = q.front();q.pop();
        if(u == t) break;
        for(int v=0;v < MAX_V;v++)
          if(res[u][v]>0 && dist[v]==INF){
            dist[v]=dist[u]+1;q.push(v);p[v]=u;
          }
      }
      augment(t,INF);
      if(f==0) break;
      mf+=f;
    }
    printf("Case %d: ",tc++);
    if(mf < total) printf("No\n");
    else{
      printf("Yes\n");
      vector<int> nxt(n2i.size(),0);
      for(int j=0;j<n2i.size();j++){
        nxt[j] = n2i[j].first;
      }
      for(int i=1;i<=n;i++){
        vector<pair<int,int> > intervals;
        for(int j=0;j<n2i.size();j++){
          if(res[j+1+n][i] > 0){
            int k = res[j+1+n][i];
            if(nxt[j]+k<=n2i[j].second){
              intervals.push_back(make_pair(nxt[j],nxt[j]+k));
              nxt[j] += k;
              if(nxt[j] == n2i[j].second) nxt[j]=n2i[j].first;
            }
            else{
              int k1 = n2i[j].second - nxt[j];
              int k2 = k - k1;
              intervals.push_back(make_pair(n2i[j].first,n2i[j].first+k2));
              intervals.push_back(make_pair(nxt[j],n2i[j].second));
              nxt[j] = n2i[j].first + k2;
            }
          }
        }
        vector<pair<int,int> > merged;
        pair<int,int> prev = make_pair(-1,-1);
        for(auto p : intervals){
          if(prev.first != -1){
            if(p.first == prev.second){
              merged[merged.size()-1].second = p.second;
            }
            else{
              merged.push_back(p);
            }
          }
          else{
            merged.push_back(p);
          }
          prev = p;
        }
        printf("%d",merged.size());
        for(auto p:merged){
          printf(" (%d,%d)",p.first,p.second);
        }
        putchar('\n');
      }
    }

  }
}

