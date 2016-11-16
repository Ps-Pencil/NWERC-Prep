// https://icpcarchive.ecs.baylor.edu/external/74/7432.pdf

#include <cstdio>
#include<cstring>

using namespace std;
int lut[256];
int main(){
  memset(lut,-1,sizeof(lut));
  for(int i = 0 ; i != 256; i++){
    lut[(i ^ (i << 1)) % 256] = i;
  }
  int N;
  scanf("%d",&N);
  while(N--){
    int x;
    scanf("%d",&x);
    printf("%d",lut[x]);
    if(N)
      putchar(' ');
  }
  printf("\n");
}
