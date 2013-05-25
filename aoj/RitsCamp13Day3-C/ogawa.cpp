//トポロジカルソート間に合わなかった＞＜
#include<iostream>
#include<list>

#define M_MAX 800
#define P_MAX 400
using namespace std;

struct point_info{
  int id;
	int day;
	point_info(int a_id,int aDay):id(a_id),day(aDay){}
};

int main(void){
	int n,m;
	int a[M_MAX],b[M_MAX],c[M_MAX];
	list<point_info> p_i[P_MAX];
	int cost[P_MAX] = {0};
	int point_max =0;
	

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i] >>c[i];
		p_i[a[i]].push_back(point_info(b[i],c[i]));
		if(a[i]>point_max)point_max=a[i];
	}


	for(int j=point_max;j>=0;j--){
		list<point_info>::iterator i = p_i[j].begin();
		int max = 0;
		while(i != p_i[j].end()){
			if(max<cost[(*i).id]+(*i).day){
				int id = (*i).id;
				max = cost[id]+(*i).day;
			}
			cost[j] = max;
			i++;
		}
	}

	cout << cost[0] << endl;

	return 0;
}
