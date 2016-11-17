#include "stdio.h"
#include <cmath>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;
struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}
bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || 
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

int main()
{
 	int n;
 	scanf("%d",&n);
 	printf("INTERSECTING LINES OUTPUT\n");
 	while (n--)
 	{
	 	  double lx1,ly1,lx2,ly2,rx1,ry1,rx2,ry2;
 		  scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&lx1,&ly1,&lx2,&ly2,&rx1,&ry1,&rx2,&ry2);
 		  PT l1(lx1,ly1);
 		  PT l2(lx2,ly2);
 		  PT r1(rx1,ry1);
 		  PT r2(rx2,ry2);
 		  if (LinesCollinear(l1,l2,r1,r2)) printf("LINE\n");
 		  else if (LinesParallel(l1,l2,r1,r2)) printf("NONE\n");
 		  else
 		  {
		   	  PT ans = ComputeLineIntersection(l1,l2,r1,r2);
		   	  printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
		  }
    }
    printf("END OF OUTPUT\n");
 	return 0;
}
