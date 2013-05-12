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
#define INF 1e9;

typedef long long unsigned int ll;
typedef complex<double> P;
#define X real()
#define Y imag()

typedef pair<double,double> pdd;
#define A top().first
#define B top().second

int main() {

    int n,p;
    while(cin>>n>>p&&(n||p)) {

        priority_queue<pdd,vector<pdd>,greater<pdd> > Q1; // greaterで小さい順になる(sortとは逆)。less<pdd>がデフォルトであるため、明示的に変更を記述。その際、vector<pdd>は変更しないが記述が必要。
        priority_queue<pdd> Q2; // "priority_queue<pdd,vector<pdd>,less<pdd> > Q2" と同じ意味。

        double a,b,pp=p;
        REP(i,n) {
            cin>>a>>b;
            Q1.push(pdd(a,b));
        }

        REP(i,n) {

            while(!Q1.empty() && Q1.A<=pp) { // pair同士の比較では、firstが同じならsecondが比較される。
                Q2.push(pdd(Q1.B, Q1.A)); // そのため、ここではpp以下でsecondが最大のものが渡される
                Q1.pop();
            }
            if( Q2.empty() ) break;

            pp += Q2.A/double(i+1);
            Q2.pop();
        }
        printf("%.01lf\n", pp);
    }
    return 0;
}
