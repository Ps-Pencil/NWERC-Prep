//https://uva.onlinejudge.org/external/110/11080.pdf
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,l;

vector<int> adj[300];
int c[3];
int ans;
int color[300];
bool bip(){
  ans=0;
  memset(color,0,sizeof(color));
  queue<int> q;
  for(int k=0;k<n;k++){
    if(!color[k]){
      memset(c,0,sizeof(c));
      q.push(k);
      color[k]=1;
      while(!q.empty()){
        int x=q.front();q.pop();
        c[color[x]]++;
        for(int i : adj[x]){
          if(color[i] == 0){
            color[i] = 3-color[x];
            q.push(i);
          }
          else if(color[i] == color[x]) return false;
        }
      }
      ans += min(c[1],c[2])==0?max(c[1],c[2]):min(c[1],c[2]);
    }
  }
  return true;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    scanf("%d",&l);
    for(int i=0;i<n;i++)
      adj[i].clear();
    for(int i=0;i<l;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if(bip()) printf("%d\n",ans==0?1:ans);
    else printf("-1\n");
  }
}
