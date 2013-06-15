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
#define INF 1e9

const int MAXN=3000;
const int MAXM=100;

typedef pair<int,int> Edge;
#define to first
#define val second
vector<Edge> G[2][MAXM];

bool used[MAXM];
int dist[MAXM];

int main() {
    int n,m;
    while(cin>>n>>m&&(n|m)) {
        REP(i,2) REP(j,m) G[i][j].clear();

        REP(i,n) {
            int a,b,cost,time; cin>>a>>b>>cost>>time;
            --a; --b;
            G[0][a].push_back(Edge(b,cost));
            G[0][b].push_back(Edge(a,cost));
            G[1][a].push_back(Edge(b,time));
            G[1][b].push_back(Edge(a,time));
        }
        int k; cin>>k;

        rep(k) {
            int p,q,r; cin>>p>>q>>r;
            --p; --q;
            fill(used, used+m, false);
            fill(dist, dist+m, INF);
            dist[p]=0;

            while(true) {
                int v = -1;
                REP(i,m) if(!used[i] && (v==-1 || dist[i]<dist[v])) v=i;

                if(v==q) {cout << dist[q] << endl; break;}
                used[v]=true;
                REP(i,G[r][v].size()) dist[G[r][v][i].to] = min(dist[G[r][v][i].to], dist[v]+G[r][v][i].val);
            }
        }
    }
    return 0;
}
