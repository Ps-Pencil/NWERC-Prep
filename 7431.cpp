// https://icpcarchive.ecs.baylor.edu/external/74/7431.pdf

#include <cstdio>
#include <cstring>
using namespace std;

char s[50];

int dx[] = {0,1,0,1};
int dy[] = {0,0,1,1};
int main(){
  int N;
  while(scanf("%s",s)!=EOF){
    int len = strlen(s);
    printf("%d ",len);
    int x=0,y=0;
    int c = 1;
    for(int i=len-1;i>=0;i--){
      x += c*dx[s[i]-'0'];
      y += c*dy[s[i]-'0'];
      c *= 2;
    }
    printf("%d %d\n",x,y);
  }
}
