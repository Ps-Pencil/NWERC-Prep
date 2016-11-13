//https://uva.onlinejudge.org/external/116/11631.pdf
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int m,n;
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
  else if(ra[i]<ra[j])
    C[i]=j;
  else
    C[j]=i;
}
int main(){
  while(scanf("%d %d",&n,&m),n+m){
    while(!q.empty())q.pop();
    int orig = 0;
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      orig += c;
      q.push(make_pair(c,ii(a,b)));
    }
    for(int i=0;i<n;i++) C[i]=i;
    for(int i=0;i<n;i++) ra[i]=1;
    int counter = n, cost = 0;
    while(counter != 1){
      auto a = q.top();q.pop();
      if(find(a.second.first) == find(a.second.second)) continue;
      // printf("%d %d\n",a.second.first, a.second.second);
      counter --;
      cost += a.first;
      u(find(a.second.first),find(a.second.second));
    }
    printf("%d\n",orig-cost);
  }
}
