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

class SuperMan
{
private:
	int pi, qi;
public:	
	SuperMan(){pi=0; qi=0;}
	void InputPi(int n){pi=n;}
	void InputQi(int n){qi=n;}
	int OutputPi(){return pi;}
	int OutputQi(){return qi;}
	static bool CompareSuperManPredicate(SuperMan left, SuperMan right){return (left.qi > right.qi);}
};

int main()
{
	double p=0.000;
	int N, k;
	vector<SuperMan> superMen;

	while(1)
	{
		superMen.resize(0);
		k=1;
		cin>>N;
		cin>>p;
		if(N==0&&p==0) break;
		rep(N)
		{
			SuperMan temp;
			int temp2;
			cin>>temp2;;
			temp.InputPi(temp2);
			cin>>temp2;
			temp.InputQi(temp2);
			superMen.push_back(temp);
		}

		// 超人たちをQiの降順でソート
		sort(superMen.begin(), superMen.end(), SuperMan::CompareSuperManPredicate);

		// 超人たちを上から走査→倒せる奴にあたったら戦闘
		while(1)
		{
			bool noMoreWeak = true;	// もう倒せる奴がいない
			if(superMen.size() < 0) break;
			vector<SuperMan>::iterator it=superMen.begin();
			while(it!=superMen.end())
			{
				// 勝てるかどうか比較
				if((double)it->OutputPi() <= p)
				{
					// パワーアップ
					p += (double)(it->OutputQi()) / (double)k;
					superMen.erase(it);	// 倒した奴は削除
					noMoreWeak = false;
					break;
				}
				++it;
			}
			if(noMoreWeak) break;
			k++;
		}
		printf("%.1lf\n", p);
	}

	return 0;
}
