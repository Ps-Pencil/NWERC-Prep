#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include "geometry.cpp"

using namespace std;


struct pipe{
  PT start, end;
  int wellno;
};
bool is_bip(vector<int> adj[],int length){
  int colour[1000];
  memset(colour,0,sizeof(colour));
  for(int i=0;i<length;i++){
    if(colour[i] != 0) continue;
    queue<int> bfs;
    bfs.push(i);
    colour[i] = 1;
    while(!bfs.empty()){
      int x = bfs.front();bfs.pop();
      for(int j : adj[x]){
        if(colour[j] == 0){
          colour[j] = 3 - colour[x];
          bfs.push(j);
        }
        else if(colour[j] == colour[x]){
          return false;
        }
      }
    }
  }
  return true;
}
int main(){
  int w,p;
  vector<pipe> pipes;
  vector<PT> wells;
  while(scanf("%d %d",&w,&p)>0)
    {
      vector<int> adj[1000];
      pipes.clear();
      wells.clear();
      for(int i=0;i<w;i++)
        {
          int a,b;
          scanf("%d %d",&a,&b);
          wells.push_back(PT(a,b));
        }
      for(int i=0;i<p;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pipe x;
        x.wellno = a-1;
        x.start = wells[a-1];
        x.end = PT(b,c);
        pipes.push_back(x);
      }
      for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
          if(pipes[i].wellno != pipes[j].wellno && segmentsIntersect(pipes[i].start,pipes[i].end,pipes[j].start,pipes[j].end)){
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
      if(is_bip(adj,p)) printf("possible\n");
      else printf("impossible\n");
    }
}
