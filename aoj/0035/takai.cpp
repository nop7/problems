#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <complex>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define rep(n) REP(i,n)
#define EPS 1e-7

typedef complex<double> P;

double cross(P a, P b)
{
	return (a.real() * b.imag() - a.imag() * b.real());
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

int main()
{
	double xa, ya, xb, yb, xc, yc, xd, yd;
	while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd) != EOF)
	{
		P a(xa, ya), b(xb, yb), c(xc, yc), d(xd, yd);
		if (is_intersected_ls(a, c, b, d))
		{
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
