// http://codeforces.com/problemset/problem/414/A
#include <cstdio>
#include <set>

using namespace std;

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  if(k < n/2 ) {
    printf("-1\n");
    return 0;
  }
  if( k == 0 && n == 1){
    printf("1\n");
  }
  else if(k==0||n==1){
    printf("-1\n");
    return 0;
  }
  else{
    int x = k-(n/2-1);
    printf("%d %d",x,x*2);
    int cur = 1;
    for(int i=0;i<n/2-1;i++){
      while(cur == x || cur + 1 == x || cur == x*2 || cur+1 == x*2) cur += 1;
      printf(" %d %d",cur,cur+1);
      cur+=2;
    }
    if(n % 2 == 1){
      while(cur == x || cur == x*2 )  cur += 1;
      printf(" %d",cur);
    }
    printf("\n");
  }
}
