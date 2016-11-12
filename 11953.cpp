//https://uva.onlinejudge.org/external/119/11953.pdf

#include <cstdio>

using namespace std;

int N;
char grid[200][200];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool alive(int row, int col){
  if(row < 0 || row >=N || col < 0 || col >= N || grid[row][col] == '.' )
    return false;
  bool ans = false;
  if(grid[row][col] == 'x') ans = true;
  grid[row][col] = '.';
  for(int i=0;i<4;i++){
    ans |= alive(row+dx[i],col+dy[i]);
  }
  return ans;
}

int main(){
  int T;
  scanf("%d",&T);
  for(int x=1;x<=T;x++){
    printf("Case %d: ",x);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%s",grid[i]);
    int ans = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        int t = alive(i,j);
        ans += t;
        // printf("%d %d %d\n",i,j,t);
      }
    }
    printf("%d\n",ans);
  }
}
