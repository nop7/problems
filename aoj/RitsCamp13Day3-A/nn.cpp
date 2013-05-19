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

int main() {
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    --a;--b;--c;--d;
    int res = INF;
    REP(i,n) {
        int w = i+1;
        int dist_ab = abs(a%w-b%w) + abs(a/w-b/w);
        int dist_cd = abs(c%w-d%w) + abs(c/w-d/w);
        res = min(res, dist_ab+dist_cd);
    }
    cout << res << endl;
    return 0;
}
