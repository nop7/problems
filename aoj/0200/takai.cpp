#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define rep(n) REP(i,n)

#define MAX_M 100
#define INF 1e9
#define COST 0
#define TIME 1

int cost[MAX_M][MAX_M];
int cost_time[MAX_M][MAX_M];
int d[MAX_M];
bool used[MAX_M];
int m;

void dijkstra(int s, int flg)
{
	fill(d, d+m, INF);
	fill(used, used+m, false);
	d[s]=0;
	while(true)
	{
		int v = -1;
		REP(u, m) if(!used[u] && (v==-1||d[u]<d[v])) v=u;
		if(v==-1) break;
		used[v] = true;
		if(flg==COST) REP(u, m) d[u]=min(d[u], d[v]+cost[v][u]);
		else if(flg==TIME) REP(u, m) d[u]=min(d[u], d[v]+cost_time[v][u]);
	}
}

int main()
{
	int n;
	while(cin>>n>>m)
	{
		REP(i, MAX_M)
		{
			REP(j, MAX_M)
			{
				cost[i][j] = INF;
				cost_time[i][j] = INF;
			}
		}
		if(n==0&&m==0) break;
		REP(i, n)
		{
			int a, b, c, time;
			cin>>a>>b>>c>>time;
			a--; b--;
			cost[a][b] = c;
			cost[b][a] = c;
			cost_time[a][b] = time;
			cost_time[b][a] = time;
		}
		int k;
		cin>>k;
		rep(k)
		{
			int p, q, r;
			cin>>p>>q>>r;
			p--; q--;
			dijkstra(p, r);
			cout << d[q] << endl;
		}
	}
	return 0;
}
