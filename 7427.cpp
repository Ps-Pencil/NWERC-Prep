// https://icpcarchive.ecs.baylor.edu/external/74/7427.pdf

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

typedef pair<long long, long long> ii;
int N, m;
ii num[3000];
long long value[10000];
int match[13000];
set<long long> temp;

vector<int> adj[3000];
vector<int> vis;
int aug(int l){
  // printf("%d %d\n",l,vis[l]);
  if(vis[l] != 0) return 0;
  vis[l] = 1;
  for(int i=0;i<adj[l].size();i++){
    int r = adj[l][i] + 3000;
    if(match[r] == -1 ||
       aug(match[r])){
      // printf("matching %d with %d\n",l,r-3000);
      match[l] = r;
      match[r]  = l ;
      return 1;
    }
  }
  return 0;
}
int mcbm(){
  // for(int i=0;i<N;i++){
  //   printf("%lld,%lld: ",num[i].first,num[i].second);
  //   for(int j : adj[i]){
  //     printf("%lld ",value[j]);
  //   }
  //   printf("\n");
  // }
  if(m < N) return 0;
  int ans = 0;
  for(int i = 0; i< N;i++){
    vis.assign(N,0);
    ans += aug(i);
  }
  return ans;
}

int main(){
  while(scanf("%d",&N) != EOF){
    for(int i=0;i!=N;i++){
      long long a,b;
      scanf("%lld %lld",&a,&b);
      num[i] = ii(a,b);
      value[i*3] = a + b;
      value[i*3 + 1] = a-b;
      value[i*3+2] = a * b;
      // printf("%lld,%lld: %lld %lld %lld\n",a,b,value[i*3],value[i*3+1],value[i*3+2]);
    }
    sort(value,value+N*3);
    int a,b;
    a = b = 1;
    while(b != 3 * N){
      if(value[b] != value[a-1]){
        value[a++] = value[b++];
      }
      else{
        b++;
      }
    }
    m = a;
    // for(int i=0;i<m;i++)
    //   printf("%lld ",value[i]);
    // printf("\n");
    for(int i=0;i<N;i++){
      temp.clear();
      adj[i].clear();
      temp.insert(num[i].first + num[i].second);
      temp.insert(num[i].first - num[i].second);
      temp.insert(num[i].first * num[i].second);
      for(long long k : temp){
        int index = lower_bound(value,value+m,k)-value;
        adj[i].push_back(index);
      }
    }
    memset(match,-1,sizeof(match));
    if(mcbm() == N){
      for(int i=0;i<N;i++){
        char c;
        long long v = value[match[i]-3000];
        if(v == num[i].first + num[i].second) c = '+';
        if(v == num[i].first - num[i].second) c = '-';
        if(v == num[i].first * num[i].second) c = '*';
        printf("%lld %c %lld = %lld\n",num[i].first,c,num[i].second,v);
      }
    }
    else{
      printf("impossible\n");
    }
  }
}
