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

const int MAXR=10;
const int MAXC=10000;

int mtx[MAXR][MAXC];
int mtxTmp[MAXR][MAXC];
int r,c,res;

void rec(int ii) {
    if(ii<r) {
        rec(ii+1);
        REP(j,c) mtx[ii][j]=(mtx[ii][j]==0)?1:0;
        rec(ii+1);
    }
    // REP(i,r) REP(j,c) mtxTmp[i][j] = mtx[i][j];
    REP(j,c) {
        int tmp=0;
        REP(i,r) if (mtx[i][j]==0) ++tmp;
        if(tmp<=r/2) REP(i,r) mtx[i][j]=(mtx[i][j]==0)?1:0;
    }
    int tmp=0;
    REP(i,r) REP(j,c) if(mtx[i][j]==0) ++tmp;
    res = max(res, tmp);
}

int main() {
    while(cin>>r>>c&&(r||c)) {
        REP(i,r) REP(j,c) cin>>mtx[i][j];
        res=0;
        rec(0);
        cout << res << endl;
    }
    return 0;
}
