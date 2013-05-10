#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <complex>
using namespace std;

#define REP(i,n) for(ll i=0; i<n; i++)
#define rep(n) REP(i,n)

typedef long long unsigned int ll;

const int MAXN=1e+7;
bool is_prime1[MAXN],is_prime2[MAXN]; // [0,1,...,sqrt(b),...], [a,a+1,...,b,...]

int main() {
    ll a,b,c,n=0;
    cin>>a>>b>>c;

    fill(is_prime1, is_prime1+MAXN, true);
    fill(is_prime2, is_prime2+MAXN, true);

    is_prime1[0]=is_prime1[1]=false;

    for(ll i=2; i*i<=b; ++i) {
        if (!is_prime1[i]) continue; //!!
        for(ll j=i; j*j<=b; j+=i) {
            is_prime1[j] = false;
        }
        for(ll j=ceil((double)a/i)*i-a; a+j<b; j+=i) {
            is_prime2[j] = false;
        }
    }

    REP(i,b-a) if (is_prime2[i]) n++;
    cout << n << endl;

    return 0;
}
