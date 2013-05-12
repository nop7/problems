#include<stdio.h>
#include<vector>
#include <algorithm>

using namespace std;

const int	MAXN = (1e5)+1;

int			n;
double		p;
vector<pair<int,int> > enemy;

int BSarch(int w){
	int ub=enemy.size()-1,lb=0;
	while(ub-lb > 1){
		int mid = (lb + ub) /2;
		if(enemy[mid].first < w){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	return (enemy[ub].first > w ) ? lb : ub;
}

//“|‚¹‚é‚â‚Â‚ğ¶‚Ì‚Ù‚¤‚©‚ç‚³‚ª‚·.
int Left(int i,int q){
	if(i < 0 || i > enemy.size()-1 ) return -1;
	if(enemy[i].first == q ){
		if(p >= enemy[i].second){
			return i;
		}
		return Left(i-1,q);
	}
	return -1;
}

void Solve(){
	int q = 100;
	int prevQ = 100;
	int k = 0;

	while(k <= n){

		int id = BSarch(q);

		prevQ = q;
		q = enemy[id].first - 1;

		int target = Left(id,enemy[id].first);

		if(target != -1){//“|‚·
			p += (double)enemy[target].first / (double)(k+1);
			k++;
			q = 100;
			vector<pair<int,int> >::iterator it = enemy.begin();
			enemy.erase(it+target);	
		}

		if(id==0 && q == prevQ){// “|i‚¹‚é“z‚¢‚È‚­‚È‚Á‚½ 
			return;
		}
	}
}

int main(){

	while(scanf("%d %lf",&n,&p) != EOF){
		if(n==0 && p==0)return 0;
		enemy.clear();
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			enemy.push_back(pair<int,int>(b,a));
		}
		sort(enemy.begin(),enemy.end());
		Solve();
		printf("%.1lf\n",p);
	}


}
