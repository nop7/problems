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
	int n,m,a,b,c;
	cin >> n >> m;
	Graph g(n);

	while(cin>>a >>b>>c)
	{
		Edge e(a, b, c);
		g[a].push_back(e);
	}
	vector<int> order;
	topologicalSort(g, order);
	int temp[n];
	REP(i, n)
	{
		temp[i]=-1;
	}
	temp[0]=0;
	REP(i, n)
	{
		REP(j, g[order[i]].size())
		{
			int src = g[order[i]][j].src;
			int dst = g[order[i]][j].dst;
			int weight = g[order[i]][j].weight;
			temp[dst] = max(temp[dst], temp[src]+weight);
		}
	}
	cout << temp[n-1] << endl;
	return 0;
}
