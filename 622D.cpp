// http://codeforces.com/problemset/problem/622/D
#include <cstdio>

using namespace std;


int main(){
  int n;
  scanf("%d",&n);
  int cur = 1;
  while(cur < n){
    printf("%d ",cur);
    cur += 2;
  }
  if(n%2 == 1) printf("%d ",n);
  cur -= 2;
  while(cur > 0){
    printf("%d ",cur);
    cur -= 2;
  }
  cur = 2;
  while(cur < n){
    printf("%d ",cur);
    cur += 2;
  }
  if(n%2 == 0) printf("%d ",n);
  cur -= 2;
  while(cur > 0){
    printf("%d ",cur);
    cur -= 2;
  }
  printf("%d\n",n);
  return 0;
}
