// union-find
#include <queue>
#include <cstring>
#include <algorithm>
typedef pair<int,int> ii;
priority_queue<pair<int,ii>, vector<pair<int,ii> >, greater<pair<int,ii> > > q;
int C[200001];
int ra[200001];
int find(int i){
  return (C[i]==i)?i:C[i]=find(C[i]);
}
int u(int i, int j){
  if(ra[i] == ra[j]){
    C[i] = j;
    ra[j]++;
  }
  else if(ra[i]<ra[j]) C[i]=j;
  else C[j]=i;
}
int main(){
  while(!q.empty())q.pop();
  for(int i=0;i<n;i++) C[i]=i;
  for(int i=0;i<n;i++) ra[i]=1;
  int counter = n;
  while((!q.empty()) && counter != 1){
    auto a = q.top();q.pop();
    if(find(a.second.first) == find(a.second.second)) {
      continue;
    }
    counter--;
    // do stuff
    u(find(a.second.first),find(a.second.second));
  }
}
