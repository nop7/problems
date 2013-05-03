#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,p,n) for(i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long unsigned int ll;
const int MAXN=(1e7)+1;
bool sieve1[MAXN];
bool sieve2[MAXN];
vector<ll> primes;
vector<ll> distances;

int main()
{
	ll a,b,c; cin>>a>>b>>c;

	ll i,j;
	//-----------------------------------------------------
	// interval sieve of Eratosthenes
	//-----------------------------------------------------
	for(i=2;i*i<b;++i) if(!sieve1[i])
	{
		for(j=i*2;j*j<b;j+=i) sieve1[j]=true;
		for(j=max<ll>(2LL,(a+i-1)/i)*i;j<b;j+=i) sieve2[j-a]=true;
	}

	REP(i,a,b) if(!sieve2[i-a]) primes.push_back(i);
	rep(i,primes.size()-1) distances.push_back(primes[i+1]-primes[i]);

	//-----------------------------------------------------
	// sum of distances, inchworm movement and  binary search
	//-----------------------------------------------------
	ll lhs=1,rhs=distances.size();
	while(lhs<rhs)
	{
		bool ok=false;
		ll med = (lhs+rhs)/2, sum=0;
		rep(i,med-1) sum+=distances[i];
		REP(i,i,distances.size())
		{ 
			sum+=distances[i]; 
			if(sum>=c){ ok=true; break; } 
			sum-=distances[i-med+1]; 
		}

		if(ok){ rhs=med; } else { lhs=med+1; }
	}

	cout<<primes.size()<<" "<<lhs<<endl;
	return 0;
}

