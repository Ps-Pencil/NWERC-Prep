//https://uva.onlinejudge.org/external/121/12160.pdf

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int l,r,u;
vector<int> options;
int bfs(){
  vector<int> vis(10000,0);
  queue<pair<int,int> > q;
  vis[l]=1;
  q.push(make_pair(l,0));
  while(!q.empty()){
    auto a = q.front();q.pop();
    if(a.first == r) return a.second;
    for(int k : options){
      int nxt = (a.first + k)%10000;
      if(!vis[nxt]){
        q.push(make_pair(nxt,a.second+1));
        vis[nxt]=1;
      }
    }
  }
  return -1;
}
int main(){
  int tc = 1;
  while(scanf("%d %d %d",&l,&r,&u),l+r+u){
    printf("Case %d: ",tc++);
    options.clear();
    for(int i=0;i<u;i++){
      int a;
      scanf("%d",&a);
      options.push_back(a);
    }
    int ans = bfs();
    if(ans == -1){
      printf("Permanently Locked\n");
    }
    else{
      printf("%d\n",ans);
    }
  }
}
