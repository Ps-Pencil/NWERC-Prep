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
