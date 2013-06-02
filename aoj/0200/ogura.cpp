#include <iostream>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef pair<int,int> pii;
const int INF=1e6, MAXM=128;
int C[2][MAXM][MAXM], dist[MAXM], visited[MAXM], N, M;

int main()
{
	int a,b,c,d; 
	while(cin>>N>>M&&(N|M))
	{
		rep(i,M) rep(j,N) C[0][i][j]=C[1][i][j]=INF;
		rep(i,N){ cin>>a>>b>>c>>d; --a; --b; C[0][a][b]=C[0][b][a]=c; C[1][a][b]=C[1][b][a]=d; }

		cin>>d;
		rep(i,d)
		{
			fill(dist,dist+MAXM,INF);
			fill(visited,visited+MAXM,false);

			cin>>a>>b>>c; --a; --b;
			dist[a]=0; 

			while(true)
			{
				int from=-1; 
				rep(i,M) if(!visited[i]&&(from==-1||dist[i]<dist[from])){ from=i; }
				if(from==b){ cout<<dist[from]<<endl; break; } else { visited[from]=true; }

				rep(to,M) dist[to]=min(dist[to],dist[from]+C[c][from][to]); 
			}
		}
	}
	return 0;
}

