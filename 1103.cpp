//https://uva.onlinejudge.org/external/11/1103.pdf

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define debug(A,B) {for(int index=0;index<B;index++)printf("%d ",A[index]);printf("\n");}

using namespace std;
int h,w;

int graph[300][300];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int noh[20000];
char table[] = {'W','A','K','J','S','D'};

void fill(int x, int y, int from, int to){
  if(x < 0 || x >= w || y < 0 || y >= h || graph[y][x] != from){
    return;
  }
  graph[y][x] = to;
  for(int i=0;i<4;i++)
    fill(x+dx[i],y+dy[i],from,to);
}
int todec(char c){
  if(c-'0' >=0 && c-'0' <= 9)
    return c-'0';
  return c-'a'+10;
}
int main(){
  int index=1;
  while(scanf("%d %d",&h,&w),h+w){
    printf("Case %d: ",index++);
    char tmp[60];
    for(int i=0;i<h;i++){
      scanf("%s",tmp);
      for(int j=0;tmp[j];j++){
        int t = todec(tmp[j]);
        graph[i][j*4] = (( t&(1<<3) ) != 0);
        graph[i][j*4+1] = ( ( t&(1<<2) )!=0 );
        graph[i][j*4+2] = ( ( t&(1<<1)  )!= 0);
        graph[i][j*4+3] = ( ( t&(1) ) != 0 );
      }
    }
    w *= 4;
    // initial colouring
    for(int x=0;x+1<w;x++)
      {
        fill(x,0,0,-1);
        fill(x+1,h-1,0,-1);
      }
    for(int y=0;y+1<h;y++)
      {
        fill(0,y+1,0,-1);
        fill(w-1,y,0,-1);
      }
    int no=1;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(graph[i][j] == 1){
          noh[no] = 0;
          fill(j,i,1,++no);
        }
        else if(graph[i][j] == 0){
          noh[graph[i][j-1]-1] ++;
          fill(j,i,0,-1);
        }
      }
    }
    // for(int i=0;i<h;i++)
    //   debug(graph[i],w);
    // debug(noh,no);
    vector<char> result;
    for(int i=1;i<no;i++){
      result.push_back(table[noh[i]]);
    }
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++)
      putchar(result[i]);
    putchar('\n');
  }
}
