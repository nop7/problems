#include <iostream>
#include <queue>
using namespace std;

#define REP(i,p,n) for(int i=0;i<n;++i)
#define rep(i,n) REP(i,0,n)

struct Node { int cost,x,y,left,right,oxigen; Node(int a,int b,int c,int d,int e,int f):cost(a),x(b),y(c),left(d),right(e),oxigen(f){} };
bool operator<(const Node& a,const Node& b){ return a.cost>b.cost; }
const int MAXN=16,MAXO=64;
const int INF=1<<28;
int T[MAXN][MAXN];
int W,H,F,M,O;

bool visited[MAXN][MAXN][MAXN][MAXN][MAXO];
inline int ox(int x,int y,int o){ return min( o+(T[y][x]>0?T[y][x]:0)-1, M ); }
inline int cs(int x,int y,int c){ return c+(T[y][x]<0?-T[y][x]:0); }

int dk()
{
	if(O<2) return INF;
	rep(x,MAXN) rep(y,MAXN) rep(l,MAXN) rep(r,MAXN) rep(o,MAXO) visited[x][y][l][r][o]=false;
	
	priority_queue<Node> Q;
	rep(i,W) Q.push(Node( cs(i,0,0), i, 0, i, i, ox(i,0,O) ));

	while(!Q.empty())
	{
		const Node node = Q.top(); Q.pop();
		if(node.y==H-1){ return node.cost; }

		if(visited[node.x][node.y][node.left][node.right][node.oxigen]) continue;
		visited[node.x][node.y][node.left][node.right][node.oxigen]=true;
	
		if(node.oxigen==1) continue;
		const int dx[] = { 1, -1 };
		rep(i,2)
		{
			const int x = node.x+dx[i], y = node.y;
			if(x<0||x>=W) continue;

			const int left = min(x,node.left), right = max(x,node.right);
			const int cost   = ((node.left==left&&node.right==right)?node.cost:cs(x,y,node.cost));
			const int oxigen = ((node.left==left&&node.right==right)?node.oxigen-1:ox(x,y,node.oxigen)); 
			if(oxigen<=0) continue;
			if(visited[x][y][left][right][oxigen]) continue;
			Q.push(Node(cost,x,y,left,right,oxigen));
		}
		
		{
			const int x = node.x, y = node.y+1;
			const int cost   = cs(x,y,node.cost); 
			const int oxigen = ox(x,y,node.oxigen); 
			if(oxigen<=0) continue;
			if(visited[x][y][x][x][oxigen]) continue;
			Q.push(Node(cost,x,y,x,x,oxigen));
		}
	}

	return INF;
}

int main()
{
	while(cin>>W>>H&&(W|H))
	{
		cin>>F>>M>>O;
		rep(y,H) rep(x,W) cin>>T[y][x];
		
		int res = dk();
		if(res>F){ cout<<"NA"<<endl; } else { cout<<res<<endl; }
	}

	return 0;
}


