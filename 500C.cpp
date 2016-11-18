// http://codeforces.com/problemset/problem/500/C

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int w[600],b[1002];
int n,m;
vector<int> v;
int level[600],weight[600];
int seen[600];
int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i!=n;i++)
    scanf("%d",&w[i]);
  for(int i=0;i!=m;i++)
    scanf("%d",&b[i]);
  int ans = 0;
  for(int i=1;i!=m;i++){
    memset(seen,0,sizeof(seen));
    for(int j=i-1;j!=-1;j--){
      if(b[j] == b[i]) break;
      if(!seen[b[j]]){
        ans += w[b[j]-1];
        seen[b[j]] = 1;
      }
    }
  }
  printf("%d\n",ans);

}
