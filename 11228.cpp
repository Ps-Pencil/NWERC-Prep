//https://uva.onlinejudge.org/external/112/11228.pdf

#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

struct co{
  int x,y;
} pos[2000];

int n,r;

int C[2000];
typedef pair<int,int> ii;
priority_queue<pair<double,ii>, vector<pair<double,ii> >, greater<pair<double,ii> > > q;
int ra[2000];
double d(co a, co b){
  return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
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
  int T;
  scanf("%d",&T);
  for(int x=1;x<=T;x++){
    while(!q.empty()) q.pop();
    printf("Case #%d: ",x);
    memset(C,-1,sizeof(C));
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      pos[i].x=a;
      pos[i].y=b;
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        q.push(make_pair(d(pos[i],pos[j]),ii(i,j)));
      }
    }
    int states = n, counter = n;
    for(int i=0;i<n;i++) C[i]=i;
    for(int i=0;i<n;i++) ra[i]=1;
    double road=0,rail=0;
    while(!q.empty()){
      auto a = q.top();q.pop();
      if(find(a.second.first) == find(a.second.second)) continue;
      if(a.first > r)
        rail += a.first;
      else
        {
          road += a.first;
          states--;
        }
      u(find(a.second.first),find(a.second.second));
      counter --;
      if(counter == 1) break;
    }
    printf("%d %d %d\n",states,(int)(road + 0.5l),(int)(rail+0.5l));
  }
}
