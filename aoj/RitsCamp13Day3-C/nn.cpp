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
#define PI (acos(-1))

typedef long long unsigned int ll;
typedef complex<double> P;
#define X real()
#define Y imag()

typedef pair<double,double> pdd; // pair同士の比較では、firstが同じならsecondが比較される。
#define A top().first // for priority_queue<pdd>
#define B top().second

const int MAXN=400;
const int MAXM=800;

typedef pair<int,int> Edge;
vector<Edge> G[MAXN];
bool visited[MAXN];

void visit(int n, vector<int> &order) {
    if(!visited[n]) {
        visited[n] = true;
        REP(i,G[n].size()) {
            visit(G[n][i].first, order);
        }
        order.push_back(n);
    }
}

int dp[MAXN];

int main() {
    fill(visited, visited+MAXN, false);

    int n,m;
    cin>>n>>m;

    REP(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        Edge tmp;
        tmp.first=b;
        tmp.second=c;
        G[a].push_back(tmp);
    }

    vector<int> L;
    visit(0,L);
    reverse(L.begin(), L.end());

    fill(dp,dp+n,-1);
    dp[0] = 0;

    REP(i,n) {
        REP(j, G[L[i]].size()) {
            dp[G[L[i]][j].first] = max(dp[G[L[i]][j].first], dp[L[i]] + G[L[i]][j].second);
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}
