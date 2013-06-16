#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)n; i++)
#define rep(n) REP(i,n)
#define EPS (1e-7)
#define INF 1e9

struct Node {int cost,x,y,left,right,oxigen; Node(int a,int b,int c,int d,int e,int f):cost(a),x(b),y(c),left(d),right(e),oxigen(f){}};
bool operator <(const Node& a, const Node& b){return a.cost > b.cost;} //Priority Queueでcostが小さい順に出てくるように不等号の向きを逆に。

const int MAXW=16,MAXH=16,MAXO=64;
int G[MAXH][MAXW]; //y,x
bool used[MAXW][MAXH][MAXW][MAXW][MAXO];
int W,H,F,M,O;

inline int cs(int x, int y, int c) { return c+(G[y][x]<0?-G[y][x]:0); }
inline int ox(int x, int y, int o) { return min(M, o-1+(G[y][x]>0?G[y][x]:0)); }

int dk() {
    if(O<=1) return INF;
    priority_queue<Node> Q;
    REP(x,W) Q.push(Node(cs(x,0,0),x,0,x,x,ox(x,0,O)));
    fill((bool *)used, (bool *)(used+MAXW), false);

    while(!Q.empty()) {
        const Node node = Q.top(); Q.pop();
        if(node.y==H-1) return node.cost; //埋蔵金セルの深さはH-1 (AOJの図だとHのようにも見えたけど)
        if(node.oxigen==1) continue;
        used[node.x][node.y][node.left][node.right][node.oxigen] = true;

        const int dx[]={-1,1};
        REP(i,2) {
            const int x=node.x+dx[i], y=node.y;
            if(x<0||W<=x) continue;

            const int left=min(x, node.left), right=max(x, node.right);
            const int oxigen=(node.left==left&&node.right==right) ? (node.oxigen-1) : ox(x,y,node.oxigen);
            const int cost=(node.left==left&&node.right==right) ? (node.cost) : cs(x,y,node.cost);
            if(used[x][y][left][right][oxigen]) continue;
            Q.push(Node(cost,x,y,left,right,oxigen));
        }
        {
            const int x=node.x, y=node.y+1;
            const int oxigen=ox(x,y,node.oxigen);
            const int cost=cs(x,y,node.cost);
            if(used[x][y][x][x][oxigen]) continue;
            Q.push(Node(cost,x,y,x,x,oxigen));
        }
    }
    return INF;
}

int main() {
    while(cin>>W>>H&&(W|H)) {
        cin>>F>>M>>O;
        REP(y,H) REP(x,W) cin>>G[y][x];

        int res = dk();
        if(res>F) cout << "NA" << endl;
        else cout << res << endl;
    }
    return 0;
}
