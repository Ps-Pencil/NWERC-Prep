//http://codeforces.com/problemset/problem/578/B
#include <cstdio>

#define fo(A,B,C) for(int A=B;i!=C;A++)
#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}

using namespace std;

int num[200500];
int pre[200500],post[200500];
int n,k,x;
int Pre(int i){
  if(i < 0 ) return 0;
  else return pre[i];
}
int Post(int i){
  if(i >= n ) return 0;
  else return post[i];
}
int main(){
  scanf("%d %d %d",&n,&k,&x);
  for(int i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  long long ans = 1;
  while(k--) ans*=x;
  pre[0] = num[0];
  post[n-1] = num[n-1];
  for(int i=1;i<n;i++){
    pre[i] = pre[i-1] | num[i];
    post[n-1-i] = post[n-i] | num[n-i-1];
  }
  long long max = 0;
  for(int i=0;i<n;i++){
    long long t = (ans * num[i]) | Pre(i-1) | Post(i+1);
    if(t>max)
      max = t;
  }
  printf("%lld\n",max);
}
