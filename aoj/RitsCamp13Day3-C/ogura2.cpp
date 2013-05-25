#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef pair<int,int> Edge;
vector< vector<Edge> > G;
#define to(i,j)   G[i][j].first
#define cost(i,j) G[i][j].second
vector<int> vs,order;

const int MAXN=512;
int dp[MAXN];

bool visit(int v)
{
	vs[v] = 1;
	rep(i,G[v].size()) if(vs[to(v,i)]!=2&&(vs[to(v,i)]==1||!visit(to(v,i)))) return false;
	vs[v] = 2;
	order.push_back(v);
	return true;
}

bool tsort(){ rep(i,G[i].size()){ if(!vs[i]&&!visit(i)) return false; } return true; }

int main()
{
	int n,m,a,b,c;
	cin>>n>>m;

	vs.assign(n,0);
	G.assign(n,vector<Edge>());
	rep(i,m){ cin>>a>>b>>c; G[a].push_back(Edge(b,c)); }

	tsort();
	reverse(order.begin(),order.end());

	rep(i,order.size()) rep(j,G[order[i]].size()) 
		dp[to(order[i],j)] = max(dp[to(order[i],j)],dp[order[i]]+cost(order[i],j));

	cout<<dp[n-1]<<endl;
	return 0;
}

