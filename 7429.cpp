//https://icpcarchive.ecs.baylor.edu/external/74/7429.pdf

#include <cstdio>
#include <algorithm>
#include <vector>

#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
using namespace std;

int N;
int a[3][200100];
// tmp for merge sort
int tmp[100100];

long long count_inversion(int t[],int start, int end){
  if(end==start) return 0;
  int mid = (start+end)/2;
  long long ans = count_inversion(t,start,mid)+count_inversion(t,mid+1,end);
  for(int i=0;i+start<=mid;i++)
    tmp[i]=t[i+start];
  int cursor1 = 0, cursor2=mid+1,output=start;
  while(cursor1 + start <= mid && cursor2 <= end){
    if(tmp[cursor1]<=t[cursor2]){
      t[output++] = tmp[cursor1++];
    }
    else{
      ans+= mid - start + 1 - cursor1;
      t[output++] = t[cursor2++];
    }
  }
  while(cursor1 + start <= mid)
    t[output++] = tmp[cursor1++];
  while(cursor2 <= end)
    t[output++] = t[cursor2++];
  return ans;
}

long long count_inversion(int p1, int p2){
  int t1[200100],t2[200100];
  // debug(a[p1],N+1);
  // debug(a[p2],N+1);
  for(int i=1;i<=N;i++){
    t1[a[p1][i]] = i;
  }
  for(int i=1;i<=N;i++){
    t2[i] = t1[a[p2][i]];
  }
  // debug(t2,N+1);
  // printf("\n");
  return count_inversion(t2,1,N);
}
int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<3;i++){
      for(int j=1;j<=N;j++){
        scanf("%d",&a[i][j]);
      }
    }
    long long inv1 = count_inversion(0,1);
    long long inv2 = count_inversion(0,2);
    long long inv3 = count_inversion(1,2);
    printf("%lld\n",(long long)N*((long long)N-1)/2-( (long long)inv1+(long long)inv2+(long long)inv3 )/2);
  }
}
