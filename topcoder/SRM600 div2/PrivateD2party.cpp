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

// 有効グラフとして考える。
// 辺で繋がれている頂点ごとに組に分け、
// 組ごとに一度行った頂点への辺を除いた辺の合計を求め、それを足す。
// ただし、この辺の合計には、自己ループの辺もカウントする。

using namespace std;
class PrivateD2party {
    public:
    bool isEnd(vector<int> his, int num)
    {
        rep(i, his.size())
        {
            if(his[i] == num) return true;
        }
        return false;
    }
    int getsz(vector <int> a)
    {
        int ans = 0;
        vector<int> start, hate, his;
        rep(i, 100) hate.push_back(0);
        rep(i, a.size())
        {
            hate[a[i]]++;
        }
        rep(i, a.size())
        {
            int s = a[i];
            vector<int> roop;
            if(hate[i] == 0) start.push_back(i);
            if(isEnd(his, s)) continue;
            while(!isEnd(roop, s))
            {
                roop.push_back(s);
                s = a[s];
            }
            if(roop[0] == s)
            {
                rep(j, roop.size())
                {
                    his.push_back(roop[j]);
                }
                if(roop.size() == 1) ans++;
                else ans += roop.size() - 1;
            }
        }
        rep(i, start.size())
        {
            int s = start[i];
            while(!isEnd(his, s))
            {
                his.push_back(s);
                s = a[s];
                ans++;
            }
        }
        return ans;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getsz(Arg0)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getsz(Arg0)); }
	void test_case_2() { int Arr0[] = {1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getsz(Arg0)); }
	void test_case_3() { int Arr0[] = {5,2,2,4,5,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getsz(Arg0)); }
	void test_case_4() { int Arr0[] = {3,2,1,0,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, getsz(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrivateD2party ___test;
___test.run_test(-1);
}
// END CUT HERE 
