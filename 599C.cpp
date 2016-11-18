//http://codeforces.com/problemset/problem/599/C

#include <cstdio>
#include <algorithm>
#include <map>
#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}
using namespace std;

int arr[100001];
int arrs[100001];
map<int,int> freq;
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int x;
    scanf("%d",&x);
    arr[i]=arrs[i]=x;
  }
  sort(arrs,arrs+N);
  // debug(arr,N);
  // debug(arrs,N);
  int i=0,j=0,ans=0;
  // invariant
  // arrs[0..i) is in arr[0..j]
  while(j!=N){
    while(arr[j]!=arrs[i])
      {
        freq[arr[j]]++;
        j++;
      }
    freq[arr[j++]]++;
    while(freq[arrs[i]]>0){
      freq[arrs[i]]--;
      i++;
    }
    if(i==j)
    ans++;
  }
  printf("%d\n",ans);
}
