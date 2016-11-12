//https://uva.onlinejudge.org/external/8/872.pdf

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char i2a[30];
int a2i[256];
vector<int> adj[30];
int n;
string line;
vector<vector<int> > ans;
bool valid(int start, int mask){
  for(int i=0;i<adj[start].size();i++){
    if(mask & (1<<adj[start][i]))
      return false;
  }
  return true;
}
void dfs(int start, unsigned int mask,vector<int> path){
  // printf("dfs called with %d %x\n",start,mask);
  if(mask & (1<<start)) return;
  if(!valid(start,mask)) return;
  mask |= 1<<start;
  for(int i=0;i<n;i++){
    if(i!=start && !(mask & (1<<i))){
      path.push_back(i);
      dfs(i,mask,path);
      path.pop_back();
    }
  }
  if(mask == (1<<n)-1){
    // printf("PATH\n");
    // for(int i=0;i<path.size();i++)printf("%d\n",path[i]);
    ans.push_back(path);
  }
  // printf("Backtrack\n");
}
int main(){
  int T;
  scanf("%d",&T);
  getchar();
  for(int index=0;index<T;index++){
    if(index!=0)
      putchar('\n');
    ans.clear();
    memset(i2a,0,sizeof(i2a));
    memset(a2i,0,sizeof(a2i));

    for(int i=0;i<30;i++)adj[i].clear();

    getchar();
    getline(cin,line);
    n=0;
    for(int i=0;i<line.size();i+=2,n++){
      i2a[i/2] = line[i];
      a2i[line[i]]= i/2;
    }
    // parse the line break
    getline(cin,line);
    for(int i=0;i<line.size();i+=4){
      adj[a2i[line[i]]].push_back(a2i[line[i+2]]);
    }
    // for(int i=0;i<n;i++){
    //   printf("%c: ",i2a[i]);
    //   for(int j:adj[i])
    //     printf("%c ",i2a[j]);
    //   putchar('\n');
    // }
    vector<int> x;
    for(int i=0;i<n;i++){
      x.push_back(i);
      dfs(i,0,x);
      x.pop_back();
    }
    if(ans.size() == 0){
      printf("NO\n");
      continue;
    }
    for(int i=0;i<ans.size();i++)
      for(int j=0;j<ans[i].size();j++)
        ans[i][j] = i2a[ans[i][j]];
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
      printf("%c",ans[i][0]);
      for(int j=1;j<ans[i].size();j++){
        printf(" %c",ans[i][j]);
      }
      putchar('\n');
    }
  }
}
