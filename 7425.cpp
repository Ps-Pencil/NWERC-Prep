// https://icpcarchive.ecs.baylor.edu/external/74/7425.pdf
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
/* geometry.cpp */
/* Some classes for geometry in competitive programming */
/* Put everything in a header file since there's a limit on reference material */
/* Everything is public since meant to be used by ourselves only */
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#define INF 1e100
#define EPS 1e-9

struct PT {
  double x,y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x),y(p.y) {}
  PT operator + (const PT &p) const {return PT(x+p.x, y+p.y);}
  PT operator - (const PT &p) const {return PT(x-p.x, y-p.y);}
  PT operator * (double c) const {return PT(c*x, c*y);}
  PT operator / (double c) const { return PT(x/c, y/c);}
};
double dot(PT p, PT q) { return p.x*q.x + p.y * q.y;}
double dist2(PT p, PT q) {return dot(p-q,p-q);}
double cross(PT p, PT q) {return p.x*q.y-p.y*q.x;}

bool linesParallel(PT a, PT b, PT c, PT d){
  return fabs(cross(b-a,c-d)) < EPS;
}
bool linesCollinear(PT a, PT b, PT c, PT d){
  return linesParallel(a,b,c,d) && fabs(cross(a-b,a-c)) < EPS && fabs(cross(c-d,c-a)) < EPS;
}
bool segmentsIntersect(PT a, PT b, PT c, PT d){
  if(linesCollinear(a,b,c,d)){
    if (dist2(a,c) < EPS || dist2(a,d) < EPS || dist2(b,c) < EPS || dist2(b,d) < EPS ) return true;
    if (dot(c-a,c-b)>0 && dot(d-a,d-b) > 0 && dot(c-b,d-b) > 0)
      return false;
    return true;
  }
  if(cross(d-a,b-a) * cross(c-a,b-a) > 0) return false;
  if(cross(a-c,d-c) * cross(b-c,d-c) > 0) return false;
  return true;
}

/* geometry.cpp */

int colour[1000];

struct pipe{
  PT start, end;
  int wellno;
};
bool is_bip(vector<int> adj[],int length){
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
