#include <iostream>
#include <complex>
#include <cstdio>
using namespace std;

#define EPS 1e-7

typedef complex<double> P;
#define X real()
#define Y imag()

double cross(P a,P b){ return (a.X*b.Y)-(a.Y*b.X); }

int isIntersected(P a1,P a2,P b1,P b2)
{
	return cross(a2-a1,b1-a1) * cross(a2-a1,b2-a1) < EPS &&
		   cross(b2-b1,a1-b1) * cross(b2-b1,a2-b1) < EPS;
}

int main()
{
	double a,b,c,d,e,f,g,h;

	while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&a,&b,&c,&d,&e,&f,&g,&h))
	{
		P aa(a,b), bb(c,d), cc(e,f), dd(g,h);
		cout<<( isIntersected(aa,cc,bb,dd)>0.0 || isIntersected(bb,dd,aa,cc)>0.0 ? "YES" : "NO" )<<endl;
	}

	return 0;
}
