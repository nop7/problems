#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define rep(n) REP(i,n)

const int MAX_L = 1e7;
bool is_prime[MAX_L], is_prime_small[MAX_L];

int main()
{
	long long int a, b, c, n, candidate;					
	long long int m = 0;
	
	vector<long long int> prime;
	while(cin >> a)
	{
		//cout << "start prime" << endl;	// debug
		cin >> b;
		cin >> c;

		//cout << "here!" << endl;

		// [a, b)‚Ì®”‚É‘Î‚µ‚Äâ¿‚ðs‚¤ is_prime[i-a]=true ¨ i‚ª‘f”
		for(int i=0; (long long int)i*i < b; i++)
			is_prime_small[i] = true;
		for(int i=0; i < b-a; i++)
			is_prime[i] = true;
		for(int i=2; (long long int)i*i<b;i++)
		{
			if(is_prime_small[i])
			{
				for(int j=2*i;(long long int)j*j<b;j+=i)
					is_prime_small[j] = false;
				for(long long int j=max(2LL, (a+i-1)/i)*i; j<b;j+=i)
					is_prime[j-a]=false;
			}
		}
		//cout << "ok1" << endl;	// debug
		int tmp;
		vector<long long int> prime_dist;
		for(int i=0;i <b-a;i++)
		{
			if(is_prime[i])
			{
				m++;
				prime_dist.push_back(abs(i-tmp));
				//prime.push_back(i);
				tmp = i;
			}
		}
		//	cout << "m is " << m << endl;	// debug

		// n‚ÌŒvŽZ
		n = 1;		

		bool check_end = false;
		
		for(n=1;n<m;n++)
		{
			for (int i=0;i<prime_dist.size()-n;i++)
			{
				//cout << "here" << endl;
				candidate = 0;
				for(int j=i;j-i<n;j++)
				{
					candidate += prime_dist[j];
				
				}
				cout << "c " << c << " candidate" << candidate << endl;
				if(c <= candidate)
				{
					check_end = true;
					break;
				}
			}
			if(check_end)
				break;
			/*
			for(int i=0;i<prime_dist.size()-n;i++)
			{
				candidate = 0;
				for(int j=0;j<n;j++)
				{
					candidate += prime_dist[j+i];
				}
				if(c <= candidate)
				{
					check_end = true;
					break;
				}
			}
			if(check_end)
				break;
				*/
		}
		

		cout << "input: " << a << " " << b << " " << c << endl;
		cout << "output: " << m << " " << n << endl;

		n = 0;
		m = 0;

	}
	return 0;
}
