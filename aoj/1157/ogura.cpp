#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstdio>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;i++)
#define rep(i,n) REP(i,0,n)

#define EPS (1e-10)
#define INF (1e+4)
#define EQ(a,b) (abs(a-b)<EPS)
#define PI (acos(-1))

typedef complex<double> P;
#define X real()
#define Y imag()
double dot(const P& a,const P& b){ return (a.X*b.X)+(a.Y*b.Y); }
double cross(const P& a,const P& b){ return (a.X*b.Y)-(a.Y*b.X); }
double rad(double theta){ return (theta/180.0)*PI; }

double distance_lp2(const P& a,const P& b,const P& c)
{
  if(dot(b-a,c-a)<EPS) return abs(c-a);
	if(dot(a-b,c-b)<EPS) return abs(c-b);
	return abs(cross(b-a,c-a)/abs(b-a));
}

bool is_intersected_ll2(const P& a1,const P& a2,const P& b1,const P& b2)
{
	if(abs(cross(a2-a1,b2-b1))<EPS) return false;
	return (cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1)<EPS) && (cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1)<EPS);
}

bool is_include4(const P& p,const P& lhs,const P& rhs)
{
	return min(lhs.X,rhs.X)<=p.X && p.X<=max(lhs.X,rhs.X) &&
		   min(lhs.Y,rhs.Y)<=p.Y && p.Y<=max(lhs.Y,rhs.Y);
}

bool len3(double d,double r,double h){ return d*d+(r-h)*(r-h)<(r*r); }

bool check(double d1,double d2,double d3,double d4,double h,double r)
{
	if(r<=h){ if(d1<r||d2<r||d3<r||d4<r){ return false; } }
	else    { if(len3(d1,r,h)||len3(d2,r,h)||len3(d3,r,h)||len3(d4,r,h)){ return false; } }

	return true;
}


P S,G;

int main()
{
	int n;
	while(cin>>n&&n)
	{
		cin>>S.X>>S.Y>>G.X>>G.Y;

		double ans = INF;

		rep(i,n)
		{
			double h;
			P p1,p2;

			cin>>p1.X>>p1.Y>>p2.X>>p2.Y>>h;
			if(ans<EPS){ ans=0; continue; }
			
			bool a = is_intersected_ll2(S,G,p1,P(p1.X,p2.Y));
			bool b = is_intersected_ll2(S,G,p1,P(p2.X,p1.Y));
			bool c = is_intersected_ll2(S,G,p2,P(p1.X,p2.Y));
			bool d = is_intersected_ll2(S,G,p2,P(p2.X,p1.Y));
			bool e = is_include4(S,p1,p2);
			bool f = is_include4(G,p1,p2);

			if(a||b||c||c||d||e||f){ ans=0; continue; }

			double d1 = distance_lp2(S,G,p1);
			double d2 = distance_lp2(S,G,p2);
			double d3 = distance_lp2(S,G,P(p1.X,p2.Y));
			double d4 = distance_lp2(S,G,P(p2.X,p1.Y));

			double s1 = distance_lp2(p1,P(p1.X,p2.Y),S);
			double s2 = distance_lp2(p1,P(p2.X,p1.Y),S);
			double s3 = distance_lp2(p2,P(p1.X,p2.Y),S);
			double s4 = distance_lp2(p2,P(p2.X,p1.Y),S);

			double g1 = distance_lp2(p1,P(p1.X,p2.Y),G);
			double g2 = distance_lp2(p1,P(p2.X,p1.Y),G);
			double g3 = distance_lp2(p2,P(p1.X,p2.Y),G);
			double g4 = distance_lp2(p2,P(p2.X,p1.Y),G);

			double lhs=0,rhs=INF;

			while(abs(rhs-lhs)>EPS)
			{
				double med = (lhs+rhs)/2.0;
				double dd = check(d1,d2,d3,d4,h,med);
				double ss = check(s1,s2,s3,s4,h,med);
				double gg = check(g1,g2,g3,g4,h,med);

				if(dd&&ss&&gg){ lhs=med; } else { rhs=med; }
			}

			if(rhs<ans) ans=rhs;
		}

		printf("%0.10lf\n",ans);
	}

    return 0;
}
