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

int main()
{
	int n, a, b, c, d, w, sum=-1;
	int A[2],B[2],C[2],D[2];
	cin >> n >> a >> b >> c >> d;

	for(int i=0;i<n;i++)
	{
		w=n-i;
		A[0]=a%w-1; A[1]=a/w;
		B[0]=b%w-1; B[1]=b/w;
		C[0]=c%w-1; C[1]=c/w;
		D[0]=d%w-1; D[1]=d/w;
		int temp = abs(A[0]-B[0])+abs(A[1]-B[1])+abs(C[0]-D[0])+abs(C[1]-D[1]);
		if(sum==-1||sum>temp)
			sum = temp;		
	}
	cout << sum << endl;
	return 0;
}
