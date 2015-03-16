// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;
class ThePermutationGameDiv2 {
    public:
    typedef long long ll;

    ll gcd(ll a, ll b){
         if(b==0) return a;
         return gcd(b, a%b);
    }

    ll lcm(ll a, ll b) {
         return a*b/gcd(a,b);
    }

    ll Lcms(vector<ll> candidate) {
        ll res;
        for(int i = 1; i < candidate.size(); ++i)
        {
            res = lcm(candidate[i-1], candidate[i]);
            candidate[i] = res;
        }
        return candidate[candidate.size()-1];
    }

    long long findMin(int N)
    {
        vector<ll> list;
        REP(i, 1, N+1) list.push_back(i);
        return Lcms(list);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 60LL; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 11; long long Arg1 = 27720LL; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 25; long long Arg1 = 26771144400LL; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ThePermutationGameDiv2 ___test;
___test.run_test(-1);
}
// END CUT HERE 
