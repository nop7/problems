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
	bool battled;	// ���ɐ퓬�ς݂�
	int pi, qi;
public:	
	SuperMan(){battled=false; pi=0; qi=0;}
	void SwitchBattled(){battled=!battled;}
	void InputPi(int n){pi=n;}
	void InputQi(int n){qi=n;}
	bool OutputBattled(){return battled;}
	int OutputPi(){return pi;}
	int OutputQi(){return qi;}	
};

int main()
{
	double max=0.000, p=0.000;
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
		// ��������p���[���炦����&&���󏟂Ă�z��I��
		while(1)
		{
			int candidate_i=-1, candidate_q=-1;
			bool allBattled = true;	// �S���Ɛ퓬������
			rep(N)
			{
				if(superMen[i].OutputBattled())
					continue;
				else
					allBattled = false;
				// ���󏟂Ă�z���
				if((double)superMen[i].OutputPi() <= p && superMen[i].OutputQi() > candidate_q)
				{
					candidate_i=i;
					candidate_q=superMen[i].OutputQi();
				}
			}
			if(candidate_i < 0) break;
			if(allBattled) break;
			// ��Ԋ��̗ǂ����|���ăp���[�A�b�v
			superMen[candidate_i].SwitchBattled();
			p += (double)candidate_q / (double)k;
			/// debug
			//cout << "battle Pi:" << superMen[candidate_i].OutputPi() << " Qi:" << candidate_q << " gain:" << (double)candidate_q/(double)k << endl;
			///
			k++;
		}
		printf("%.1lf\n", p);
	}

	return 0;
}
