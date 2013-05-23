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

#define REP(i,n) for(int i=0; i<n; i++)
#define rep(n) REP(i,n)
#define EPS 1e-7
#define INF 1e9

const int MAXW=400; //393
const int MAXN=393;
const int MAXM=393;
int s[MAXN];
int l[MAXN];
int p[MAXN];

int dp[MAXW];
int res[MAXM];

int main() {
    int n; cin>>n;
    REP(i,n) cin>>s[i]>>l[i]>>p[i];

    fill(dp, dp+MAXW, -1);
    dp[0]=0;

    REP(i,MAXW) if(dp[i]!=-1) {
        REP(j,n) REP(k,l[j]-s[j]+1) if(i+s[j]+k < MAXW) {
            dp[i+s[j]+k] = max(dp[i+s[j]+k], dp[i]+p[j]);
        }
    }

    int m; cin>>m;
    bool ok=true;
    REP(i,m) {
        int w; cin>>w;
        if(dp[w] == -1) {ok=false;break;}
        res[i] = dp[w];
    }
    if(ok) REP(i,m) cout << res[i] << endl;
    else cout << -1 << endl;

    return 0;
}
