//https://uva.onlinejudge.org/external/111/11101.pdf

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int graph[2001][2001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int h,w,mh,mw;
void line(int a, int b, int a1, int b1,int c){
  if(a==a1)
  for(int k=min(b,b1);k<=max(b,b1);k++)
    graph[a][k]=c;
  else
    for(int k=min(a,a1);k<=max(a,a1);k++)
      graph[k][b]=c;
}
int s_r,s_c;
void getpoly(int m1,int num){
  int lasta=-1,lastb=-1;
  int firsta,firstb;
  for(int i=0;i<m1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    // printf("%d %d\n",a,b);
    h=max(h,a);
    w=max(w,b);
    mh = min(mh,a);
    mw=min(mw,b);
    graph[a][b]=num;
    // if(i==0){
    //   firsta=a;firstb=b;
    // }
    // if(lasta!=-1){
      // line(a,b,lasta,lastb,num);
    // }
    // lasta =a ;
    // lastb=b;
  }
  // if(num == 2)
  //   {
  //     s_r = firsta;
  //     s_c = firstb;
  //   }
  // line(lasta,lastb,firsta,firstb,num);
}
struct pt{
  int x,  y;
  pt(int x, int y):x(x),y(y){}
  pt(){}
};
bool ingraph(pt a){
  return a.x >= mw && a.x < w && a.y >=mh && a.y<h;
}
queue<pair<int,pt> > q;
bool vis[2001][2001];
int bfs(){
  memset(vis,0,sizeof(vis));
  while(!q.empty()) q.pop();
  for(int i=mh;i<h;i++)
    for(int j=mw;j<w;j++)
      if(graph[i][j] == 2)
        {
          q.push(make_pair(0,pt(j,i)));
          vis[i][j]=1;
        }
  while(!q.empty()){
    auto a = q.front();q.pop();
    // printf("%d %d %d\n",a.first,a.second.x,a.second.y);
    for(int i=0;i<4;i++){
      pt newp = a.second;
      newp.x += dx[i];
      newp.y += dy[i];
      // printf("- %d %d %d %d\n",newp.x,newp.y,ingraph(newp),vis[newp.y][newp.x]);
      if(!ingraph(newp)) continue;
      if(graph[newp.y][newp.x] == 1) return a.first+1;
      if(!vis[newp.y][newp.x]){
        q.push(make_pair(a.first+1,newp));
        vis[newp.y][newp.x]=1;
      }
    }
  }
}
int main(){
  int m1,m2;
  while(scanf("%d",&m1),m1){
    memset(graph,0,sizeof(graph));
    h=w=0;
    mh=mw=1000000;
    getpoly(m1,2);
    scanf("%d",&m2);
    getpoly(m2,1);
    // printf("%d %d %d %d\n",mh,h,mw,w);
    h++;
    w++;
    printf("%d\n",bfs());
    // for(int i=mh;i<h;i++)
    //   {
    //     for(int j=mw;j<w;j++)
    //       printf("%d ",graph[i][j]);
    //     printf("\n");
    //   }

  }
}
