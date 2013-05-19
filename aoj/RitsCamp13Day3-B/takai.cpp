#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define rep(n) REP(i,n)

const int MAXW = 400;
int dp[MAXW];

int main()
{
	int n, m, s, l, p;

	fill(dp,dp+MAXW,-1);
	dp[0]=0;

	cin >> n;
	for(int k=0;k<n;k++)
	{
		cin>>s>>l>>p;
		for(int i=0;i<MAXW;i++)
		{
			for(int j=s;j<l+1;j++)
			{
				if(i+j<MAXW && dp[i] != -1)
					dp[i+j] = max(dp[i+j],dp[i]+p);
			}
		}
	}

	cin >> m;
	vector<int> res(m);
	for(int i = 0;i<m;i++)
	{
		cin>>res[i];
		res[i]=dp[res[i]];
	}

	if(find(res.begin(), res.end(),-1)==res.end())
	{
		for(int i=0;i<m;i++)
		{
			cout<<res[i]<<endl;
		}
	}
	else
	{
		cout<<-1<<endl;
	}

	return 0;
}
