//https://uva.onlinejudge.org/external/103/10369.pdf


#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


struct pt{
  int x,y;
} post[600];
int m,n;
typedef pair<int,int> ii;
priority_queue<pair<double,ii>, vector<pair<double,ii> >, greater<pair<double,ii> > > q;
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
double d(pt a, pt b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    while(!q.empty())q.pop();
    int cutoff;
    scanf("%d %d",&cutoff,&n);
    for(int i=0;i<n;i++){
      scanf("%d %d",&post[i].x,&post[i].y);
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        q.push(make_pair(d(post[i],post[j]),ii(i,j)));
      }
    }
    for(int i=0;i<n;i++) C[i]=i;
    for(int i=0;i<n;i++) ra[i]=1;
    int initial = n;
    double last;
    while((!q.empty()) && initial != cutoff){
      auto a = q.top();q.pop();
      if(find(a.second.first) == find(a.second.second)) {
        continue;
      }
      initial--;
      last = a.first;
      u(find(a.second.first),find(a.second.second));
    }
    printf("%.2f\n",last);
  }
}
