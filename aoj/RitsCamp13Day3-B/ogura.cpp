#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;++i)
#define rep(i,n) REP(i,0,n)

const int MAXW=400;
int dp[MAXW];

int main()
{
	int n,m,s,l,p;

	fill(dp,dp+MAXW,-1);
	dp[0]=0;

	cin>>n;
	rep(k,n)
	{
		cin>>s>>l>>p;
		rep(i,MAXW) REP(j,s,l+1) if(i+j<MAXW&&dp[i]!=-1) dp[i+j]=max(dp[i+j],dp[i]+p);
	}

	cin>>m;
	vector<int> res(m);
	rep(i,m){ cin>>res[i]; res[i]=dp[res[i]]; }

	if(find(res.begin(),res.end(),-1)==res.end()){ rep(i,m) cout<<res[i]<<endl; }
	else                                         { cout<<-1<<endl; }

	return 0;
}
