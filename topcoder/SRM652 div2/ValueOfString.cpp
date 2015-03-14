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
class ValueOfString {
    public:
    int findValue(string s)
    {
		int res = 0;
		map<char, int> alph_map;
		map<char, int> count_map;
		string alph = "abcdefghijklmnopqrstuvwxyz";
		// create map
		rep(i, alph.length())
		{
			alph_map[alph[i]] = i+1;
			count_map[alph[i]] = 0;
		}
		rep(i, s.length())
		{
			if(count_map[s[i]] > 0)continue;
			rep(j, s.length())
			{
				if(alph_map[s[i]] >= alph_map[s[j]])
				{
					count_map[s[i]]++;
				}
			}
		}
		// calc
		rep(i, s.length())
		{
			res += count_map[s[i]] * alph_map[s[i]];
		}
		return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "babca"; int Arg1 = 35; verify_case(0, Arg1, findValue(Arg0)); }
	void test_case_1() { string Arg0 = "zz"; int Arg1 = 104; verify_case(1, Arg1, findValue(Arg0)); }
	void test_case_2() { string Arg0 = "y"; int Arg1 = 25; verify_case(2, Arg1, findValue(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbc"; int Arg1 = 47; verify_case(3, Arg1, findValue(Arg0)); }
	void test_case_4() { string Arg0 = "topcoder"; int Arg1 = 558; verify_case(4, Arg1, findValue(Arg0)); }
	void test_case_5() { string Arg0 = "thequickbrownfoxjumpsoverthelazydog"; int Arg1 = 11187; verify_case(5, Arg1, findValue(Arg0)); }
	void test_case_6() { string Arg0 = "zyxwvutsrqponmlkjihgfedcba"; int Arg1 = 6201; verify_case(6, Arg1, findValue(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ValueOfString ___test;
___test.run_test(-1);
}
// END CUT HERE 
