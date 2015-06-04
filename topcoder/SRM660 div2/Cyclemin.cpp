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

// 文字列の循環シフトを全パターン求める。
// その後その全パターンの先頭文字 k 個を 'a' に変え、ソートした一番上を返す。

using namespace std;
class Cyclemin {
    public:
    string bestmod(string s, int k)
    {
        set<string> cand;
        cand.insert(s);
        rep(i, s.length())
        {
            rotate(s.begin(), s.begin()+1, s.end());
            cand.insert(s);
        }
        set<string>::iterator it = cand.begin();
        set<string> cand2;
        while(it != cand.end())
        {
            string str = *it;
            int j = k;
            rep(i, str.length())
            {
                if(j <= 0) break;
                if(str[i] != 'a')
                {
                    str[i] = 'a';
                    j--;
                }
            }
            cand2.insert(str);
            ++it;
        }
        return *(cand2.begin());
    }

// BEGIN CUT HERE
    public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "aaa"; verify_case(0, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 0; string Arg2 = "aab"; verify_case(1, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bbb"; int Arg1 = 2; string Arg2 = "aab"; verify_case(2, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "sgsgaw"; int Arg1 = 1; string Arg2 = "aasgsg"; verify_case(3, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abacaba"; int Arg1 = 1; string Arg2 = "aaaabac"; verify_case(4, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "isgbiao"; int Arg1 = 2; string Arg2 = "aaaisgb"; verify_case(5, Arg2, bestmod(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Cyclemin ___test;
___test.run_test(-1);
}
// END CUT HERE 
