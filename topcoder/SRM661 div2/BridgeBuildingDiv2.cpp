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

const int N = 32;
int Edge[N][N];   // グラフ

using namespace std;
class BridgeBuildingDiv2 {
    public:
    int minDiameter(vector <int> a, vector <int> b, int K)
    {
        int n = a.size() + 1;
        int n2 = 2*n;
        int res = 1E9;
        // 縦の道をどれだけ張るかのパターン数を出す
        rep(i, 1 << n)
        {
            // グラフの初期化
            //fill(&Edge[0][0], &Edge[N-1][N-1], 1E9);
            rep(j, N){ rep(k, N){ Edge[j][k] = (j == k) ? 0 : 1E9; } }

            int kn = 0;
            rep(j, n){ if((i >> j) & 1){ kn++; }}

            if(kn != K){ continue; }

            // グラフを作成
            rep(j, a.size())
            {
                Edge[j][j+1] = Edge[j+1][j] = a[j];
            }
            rep(j, b.size())
            {
                Edge[j+n][j+n+1] = Edge[j+n+1][j+n] = b[j];
            }
            // 縦のエッジを作る
            rep(j, n)
            {
                if((i >> j) & 1){ Edge[j][j+n] = Edge[j+n][j] = 0; }
            }
            // ワーシャルフロイド
            rep(j, n2)
            {
                rep(s, n2)
                {
                    rep(g, n2)
                    {
                        Edge[s][g] = min(Edge[s][j] + Edge[j][g], Edge[s][g]);
                    }
                }
            }
            int maximum = 0;
            rep(j, n2)
            {
                rep(k, n2)
                {
                    maximum = max(maximum, Edge[j][k]);
                }
            }
            res = min(res, maximum);
        }
        return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,9,1,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,50,1,50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,1,50,1,50,1,50,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 8; verify_case(1, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,10,15,31,20,23,7,48,5,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,8,3,2,16,11,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 124; verify_case(2, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2,4,10,2,2,22,30,7,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,26,1,2,6,2,16,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 54; verify_case(3, Arg3, minDiameter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BridgeBuildingDiv2 ___test;
___test.run_test(-1);
}
// END CUT HERE 
