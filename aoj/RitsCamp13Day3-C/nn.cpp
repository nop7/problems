#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)n; i++)
#define rep(n) REP(i,n)
#define EPS 1e-7
#define INF 1e9

const int MAXN=400;
const int MAXM=800;
int dp[MAXN];

typedef pair<int,int> Edge;
#define to first
#define cost second
vector<Edge> G[MAXN];

bool visited[MAXN];

void visit(int v, vector<int>& order) {
    visited[v] = true;
    REP(i,G[v].size()) if(!visited[G[v][i].to]) visit(G[v][i].to, order);
    order.push_back(v);
}

void tsort(vector<int>& order) {
    fill(visited, visited+MAXN, false);
    visit(0,order);
    reverse(order.begin(), order.end());
}

int main() {
    int n,m; cin>>n>>m;
    REP(i,m) {
        int a,b,c; cin>>a>>b>>c;
        G[a].push_back(Edge(b,c));
    }

    vector<int> order;
    tsort(order);

    fill(dp,dp+n,-1);
    dp[0] = 0;

    REP(i,n) {
        int from = order[i];
        REP(j, G[from].size()) {
            int to = G[from][j].to;
            int cost = G[from][j].cost;
            dp[to] = max(dp[to], dp[from]+cost);
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}
