#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
// #include <stringstream>
// #include <cstdio>
using namespace std;

#define REP(i,k,n) for( long long int i = k; i<n; i++)
#define rep(n) REP(i,n)

int main() {

    long long int a,b,c;
    cin>>a>>b>>c;

    long long int n = 0;
    REP(i,a,b) {

        // [a,b) : [0]     [a]           [b-1]
        long long int j;
        for(j=2;j*j<=i;j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j*j>i) {
            n++;
        }

        // int tmp = b/2; // 13/2=6.5=6,   12/2=6
        // 37/2=18.5=18
    }

    cout << n << endl;
    return 0;
}
