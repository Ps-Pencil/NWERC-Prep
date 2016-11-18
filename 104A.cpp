//http://codeforces.com/problemset/problem/104/A
#include<cstdio>

using namespace std;
int ans[] = {0,4,4,4,4,4,4,4,4,4,15,4};
int main(){
  int n;
  scanf("%d",&n);
  if(n-10 > 11 || n-10 < 0) printf("0\n");
  else printf("%d\n",ans[n-10]);
}
