#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<double,double> pdd;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define A top().first
#define B top().second

int main()
{
	int n,p;
	while(cin>>n>>p&&(n|p))
	{
		priority_queue<pdd,vector<pdd>,greater<pdd> > Q1;
		priority_queue<pdd> Q2;

		double a,b,pp=p;
		rep(i,n){ cin>>a>>b; Q1.push(pdd(a,b)); }

		rep(i,n)
		{
			while(!Q1.empty()&&Q1.A<=p){ Q2.push(pdd(Q1.B,Q1.A)); Q1.pop(); }
			if(Q2.empty()) break;

			pp += Q2.A/double(i+1);
			Q2.pop();
		}

		printf("%.01lf\n",pp);
	}


	return 0;
}
