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

const int MAXW=400;
const int MAXN=400;
int s[MAXN];
int l[MAXN];
int p[MAXN];
int res[MAXW];
int ans[MAXW];

int main() {
    int n;
    cin>>n;
    REP(i,n) cin>>s[i]>>l[i]>>p[i];
    fill(res,res+MAXW,-1);
    res[0] = 0;

    REP(i,MAXW) if(res[i] >= 0) {
        REP(j,n) {
            REP(k,l[j]-s[j]+1) {
                int len = k+s[j];
                if(i+len>=MAXW) {
                    continue;
                }
                res[i+len] = max(res[i+len], res[i]+p[j]);
            }
        }
    }

    int m;
    cin>>m;
    bool pass = true;

    REP(i,m) {
        int w;
        cin>>w;
        if(res[w] < 0) {
            pass = false;
            break;
        }
        else {
            ans[i] = res[w];
        }
    }

    if(pass) {
        REP(i,m) {
            cout << ans[i] << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
