#include <iostream>
#include <algorithm>
#include <cstdio>
#include <complex>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define rep(n) REP(i,n)

#define EPS 1e-7
#define INF 1e9

typedef complex<double> P;
#define X real()
#define Y imag()

// 内積 (dot product) : a⋅b = |a||b|cosθ
double dot(P a, P b) {
    return a.X*b.X + a.Y*b.Y;
}

// 外積 (cross product) : a×b = |a||b|sinθ
double cross(P a, P b) {
    return a.X*b.Y - a.Y*b.X;
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
    return (cross(a2-a1, b1-a1)*cross(a2-a1, b2-a1) < EPS) &&
        (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS);
}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
    if ( dot(b-a, c-a) < EPS ) return abs(c-a);
    if ( dot(a-b, c-b) < EPS ) return abs(c-b);
    // 平行四辺形の面積/底辺の長さ = 平行四辺形の高さ = 線分と点cとの距離
    return abs(cross(b-a, c-a)) / abs(b-a);
}

int main() {
    int N;
    while(cin>>N&&N) {
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        P s = P(sx,sy);
        P e = P(ex,ey);
        double r = INF;
        rep(N) {
            int minx,miny,maxx,maxy,h;
            cin>>minx>>miny>>maxx>>maxy>>h;
            P bv[4]; //block vertex
            // 0  _  3
            //   |_|
            // 1     2
            bv[0] = P(minx,miny);
            bv[1] = P(minx,maxy);
            bv[2] = P(maxx,maxy);
            bv[3] = P(maxx,miny);

            // 直方体の底面の4つの辺のいずれかが線分s-eと交わる
            bool flg=false;
            REP(i,4) REP(j,4) if(i<j&&j-i!=2) if(is_intersected_ls(s,e,bv[i],bv[j])) {r=0.0;i=j=4;flg=true;}
            if (flg) break;

            double dds[4], dde[4], ddd[4];
            int k=0;
            REP(i,4) REP(j,4) if(i<j&&j-i!=2) {
                //    1
                //    _
                // 0 |_| 3
                //    2
                dds[k] = distance_ls_p(bv[i],bv[j],s); //点sと直方体の底面の辺との距離
                dde[k] = distance_ls_p(bv[i],bv[j],e); //点eと直方体の底面の辺との距離
                ddd[k++] = abs(bv[i]-bv[j]); //直方体の底面の辺の長さ
            }

            // いま、直方体の底面と線分s-eの関係は、包含されるかされないかの2通り
            // その判定方法: 点sと直方体の底面の4辺との距離が以下の条件を満たすかどうか
            if(dds[0]<ddd[1]+EPS && dds[3]<ddd[1]+EPS
               && dds[1]<ddd[0]+EPS && dds[2]<ddd[0]+EPS) {r=0.0;break;}

            // 大玉を転がしていったときの、ブロックとの最小距離
            double distMin = INF;
            REP(i,4) distMin = min(distMin,distance_ls_p(s,e,bv[i]));
            REP(i,4) REP(j,4) if(i<j&&j-i!=2) distMin = min(distMin,distance_ls_p(bv[i],bv[j],s));
            REP(i,4) REP(j,4) if(i<j&&j-i!=2) distMin = min(distMin,distance_ls_p(bv[i],bv[j],e));

            // このブロックに対する最大半径を計算し、minで更新
            if(distMin < h) r = min(r, distMin);
            else r = min(r, (h*h+distMin*distMin)/(2.0*h));
        }
        printf("%.3lf\n",r);
    }
    return 0;
}
