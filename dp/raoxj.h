#ifndef __RAOXJ_H
#define __RAOXJ_H

#include "stdio.h"
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define INF 1e100
#define EPS 1e-12

using namespace std;

struct PT
{
	double x,y;
	PT(double x,double y):x(x),y(y) {}
	PT(const PT &p):x(p.x),y(p.y) {}
	PT operator + (const PT &p) const {return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) const {return PT(x-p.x,y-p.y);}
	PT operator * (double c) const {return PT(x*c,y*c);}
	PT operator / (double c) const {return PT(x/c,y/c);}
};

double dot(PT p,PT q)	{return p.x*q.x+p.y*q.y;}
double dist2(PT p,PT q)	{return dot(p-q,p-q);}
double cross(PT p,PT q)	{return p.x*q.y-p.y*q.x;}
double area2(PT a,PT b,PT c) {return cross(a,b)+cross(b,c)+cross(c,a);}

PT RotateCCW90(PT p)	{return PT(-p.y,p.x);}
PT RotateCW90(PT p)	{return PT(p.y,-p.x);}
PT RotateCCW(PT p,double t){
	return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}
//project point c onto line through a and b, assuming a != b
PT ProjectPointLine(PT a,PT b,PT c){
	return a+(b-a)*dot(c-1,b-a)/dot(b-a,b-a);
};
