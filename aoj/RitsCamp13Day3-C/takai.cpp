#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

#define MAX_N 410 

int dp[MAX_N];

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
  color[v] = 1;
  FOR(e, g[v]) {
    if (color[e->dst] == 2) continue;
    if (color[e->dst] == 1) return false;
    if (!visit(g, e->dst, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
  int n = g.size();
  vector<int> color(n);
  REP(u, n) if (!color[u] && !visit(g, u, order, color))
    return false;
  reverse(ALL(order));
  return true;
}


int main()
{
	int n, m, a, b, c;
	Edges temp;
	vector<int> order;

	fill(dp, dp+MAX_N, -1);
	dp[0]=0;

	cin >> n >> m;
	Graph g(n);
	for(int i=0;i<m;++i)
	{
		cin >> a >> b >> c;
		g[a].push_back(Edge(a, b, c));
	}

	topologicalSort(g, order);

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<g[order[i]].size();++j)
		{
			int src = g[order[i]][j].src;
			int dst = g[order[i]][j].dst;
			int weight = g[order[i]][j].weight;
			dp[dst] = max(dp[dst], dp[src]+weight);
		}
	}

	cout << dp[n-1] << endl;


	return 0;
}
