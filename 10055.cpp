// https://uva.onlinejudge.org/external/100/10055.pdf
#include <cstdio>

using namespace std;

int main(){
  unsigned long long m,n;
  while(scanf("%llu %llu",&m,&n) == 2){
    if( n < m){
      unsigned long long t = n;
      n = m;
      m = t;
    }
    printf("%llu\n",n-m);
  }
}
