#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,k,n) for(int i=k;i<n;++i)
#define rep(i,n) REP(i,0,n)

int N,M,K;
const int MAXN=128;
const int INF=1e+9;
int G1[MAXN][MAXN];
int G2[MAXN][MAXN];

int main()
{
	while(cin>>M>>N&&(M||N))
	{
		rep(i,N){ rep(j,N){ G1[i][j]=G2[i][j]=(i==j?0:INF); } }

		rep(i,M)
		{ 
			int a,b,c,d;
			cin>>a>>b>>c>>d; --a; --b;
			G1[a][b]=G1[b][a]=c;
			G2[a][b]=G2[b][a]=d;
		}

		rep(point,N) rep(from,N) rep(to,N)
		{
			G1[from][to] = min(G1[from][to],G1[from][point]+G1[point][to]);
			G2[from][to] = min(G2[from][to],G2[from][point]+G2[point][to]);
		}

		cin>>K;
		rep(i,K)
		{
			int a,b,c; cin>>a>>b>>c; --a; --b;
			cout<<(c?G2[a][b]:G1[a][b])<<endl;
		}
	}

	return 0;
}
