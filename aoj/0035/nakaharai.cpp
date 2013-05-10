#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <complex>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define rep(n) REP(i,n)
#define EPS 1e-7

typedef complex<double> P; // http://www.deqnotes.net/acmicpc/2d_geometry/

double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

int main() {

    double xa,ya,xb,yb,xc,yc,xd,yd;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd) != EOF) {
        P a(xa,ya),b(xb,yb),c(xc,yc),d(xd,yd);

        if (cross(c-a,b-a)*cross(c-a,d-a) < EPS && cross(d-b,a-b)*cross(d-b,c-b) < EPS) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
