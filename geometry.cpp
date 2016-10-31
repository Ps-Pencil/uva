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

