#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef pair<int,int> Edge;
#define to   first
#define cost second
vector< vector<Edge> > G;

const int MAXN=512;
int dp[MAXN];

bool visit(int v,vector<int>& order,vector<int>& visited)
{
	visited[v]=1;
	rep(i,G[v].size())
	{
		if(visited[G[v][i].to]==2) continue;
		if(visited[G[v][i].to]==1||!visit(G[v][i].to,order,visited)) return false;
	}
	order.push_back(v);
	visited[v]=2;
	return true;
}

bool tsort(vector<int>& order)
{
	vector<int> visited(G.size());
	rep(i,G.size()) if(!visited[i]&&!visit(i,order,visited)) return false;
	reverse(order.begin(),order.end());
	return true;
}

int main()
{
	int n,m,a,b,c;
	vector<int> order;
	cin>>n>>m;

	G.assign(n,vector<Edge>());
	rep(i,m){ cin>>a>>b>>c; G[a].push_back(Edge(b,c)); }
	tsort(order);
	
	rep(i,order.size())
	{
		const int from = order[i];
		rep(j,G[from].size())
		{
			const int to   = G[from][j].to;
			const int cost = G[from][j].cost;
			dp[to] = max(dp[to],dp[from]+cost);
		}
	}
	
	cout<<dp[n-1]<<endl;
	return 0;
}

