//https://uva.onlinejudge.org/external/117/11747.pdf

#include <cstdio>
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
  while(scanf("%d %d",&n,&m),m+n){
    for(int i=0;i<m;i++){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      q.push(make_pair(c,ii(a,b)));
    }
    for(int i=0;i<n;i++) C[i]=i;
    for(int i=0;i<n;i++) ra[i]=1;
    vector<int> res;
    while(!q.empty()){
      auto a = q.top();q.pop();
      if(find(a.second.first) == find(a.second.second)) {
        res.push_back(a.first);
        continue;
      }
      u(find(a.second.first),find(a.second.second));
    }
    if(res.size()==0) printf("forest\n");
    else
      {
        for(int i=0;i<res.size();i++){
          if(i!=0) putchar(' ');
          printf("%d",res[i]);
        }
        putchar('\n');
      }
  }
}
