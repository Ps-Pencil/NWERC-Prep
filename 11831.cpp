//https://uva.onlinejudge.org/external/118/11831.pdf

#include <cstdio>

using namespace std;

int N,M,S;
char grid[200][200];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
char inst[60000];
bool stuck(int x, int y){
  return x <= 0 || x > M || y <= 0 || y > N || grid[y][x] == '#';
}
int main(){
  int x,y,d;
  while(scanf("%d %d %d",&N,&M,&S),N+M+S){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
        scanf("%c",&grid[i][j]);
        if(grid[i][j] == '\n')
          scanf("%c",&grid[i][j]);
        if(grid[i][j]=='N'){
          x = j;
          y = i;
          d = 0;
        }
        if(grid[i][j]=='S'){
          x = j;
          y = i;
          d = 2;
        }
        if(grid[i][j]=='L'){
          x = j;
          y = i;
          d = 1;
        }
        if(grid[i][j]=='O'){
          x = j;
          y = i;
          d = 3;
        }
      }
    }
    scanf("%s",inst);
    int ans=0;
    for(int i=0;i<S;i++){
      switch(inst[i]){
      case 'D':
        d = (d+4+1)%4;
        break;
      case 'E':
        d = (d+4-1)%4;
        break;
      case 'F':
        x+=dx[d];
        y+=dy[d];
        if(stuck(x,y)){
          x-=dx[d];
          y-=dy[d];
        }
      }
      if(grid[y][x] == '*'){
        ans++;
        grid[y][x] = '.';
      }
      // printf("%d %c %d (%d,%d) %d\n",i,inst[i],d,x,y,ans);
    }
    printf("%d\n",ans);
  }
}
