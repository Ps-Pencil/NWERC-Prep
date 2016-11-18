//https://uva.onlinejudge.org/external/110/11094.pdf

#include <cstdio>
#include <algorithm>
using namespace std;
#define debug(A,B) {for(int index=0;index<B;index++)printf("%c ",A[index]);printf("\n");}
#define P(a) printf(#a"=%d\n",a);

char graph[100][100];
int h,w;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void fill(int x, int y, char from, char to,int &count){
  if(x<0 || x>=w){
    x = (x+w)%w;
  }
  if(y < 0 || y >= h || graph[y][x] != from){
    // P(graph[y][x]);P(from);
    return;
  }
  graph[y][x] = to;
  count++;
  for(int i=0;i<4;i++)
    fill(x+dx[i],y+dy[i],from,to,count);
}
int main(){
  while(scanf("%d %d",&h,&w)!=EOF){
    int ans = 0;
    for(int i=0;i<h;i++){
      scanf("%s",graph[i]);
    }
    int startx, starty;
    scanf("%d %d",&starty, &startx);
    char land = graph[starty][startx];
    char water=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(graph[i][j]!=land)
          {
            water = graph[i][j];break;
          }
      }
      if(water) break;
    }
    if(!water){printf("0\n");continue;}
    int count = 0;
    fill(startx,starty,land,water,count);
    // for(int i=0;i<h;i++)
    //   debug(graph[i],w);
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(graph[i][j] == land){
          count = 0;
          // P(j);P(i);
          fill(j,i,land,water,count);
          ans = max(ans,count);
        }
      }
    }
    // for(int i=0;i<h;i++)
    //   debug(graph[i],w);
    printf("%d\n",ans);
  }
}


