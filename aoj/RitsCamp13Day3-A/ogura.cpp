#include <iostream>
#include <cstdlib>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;++i)
#define rep(i,n) REP(i,0,n)

int main()
{
	int n,a,b,c,d,ans=int(1e9);
	cin>>n>>a>>b>>c>>d;
	--a; --b; --c; --d;

	REP(i,1,n)
	{
		const int ab = abs((a%i)-(b%i))+abs((a/i)-(b/i));
		const int cd = abs((c%i)-(d%i))+abs((c/i)-(d/i));
		ans = min(ans,ab+cd);
	}

	cout<<ans<<endl;

	return 0;
}
