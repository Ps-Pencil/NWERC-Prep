// http://codeforces.com/problemset/problem/623/A

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;



int n,m;
vector<int> adj[600];
char assign[600];
bool mat[600][600];
bool valid(){
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(abs(assign[i]-assign[j])<=1 && mat[i][j] != 1 ||
         abs(assign[i]-assign[j])>1 && mat[i][j] != 0)
        return false;
    }
  }
  return true;
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    mat[a][b] = mat[b][a]=1;
  }
  for(int i=1;i<=n;i++){
    if(adj[i].size()==n-1)
      assign[i]='b';
  }
  int x=1;
  while(assign[x]!=0) x++;
  assign[x] = 'a';
  for(int i=0;i<adj[x].size();i++){
    if(!assign[adj[x][i]]) assign[adj[x][i]] = 'a';
  }
  for(int i=1;i<=n;i++){
    if(!assign[i]) assign[i] = 'c';
  }
  if(valid()){
    printf("Yes\n");
    for(int i=1;i<=n;i++) putchar(assign[i]);
    putchar('\n');
  }
  else
    printf("No\n");
}
