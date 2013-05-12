#include <iostream>
#include <set>
#include <complex>
#include <iomanip>
using namespace std;

#define EPS 0.0

class Block
{
public:
    int minx, miny, maxx, maxy, h;
    Block(int mx, int my, int Mx, int My, int vh) { minx = mx; miny = my; maxx = Mx; maxy = My; h = vh; };
};

bool operator> (const Block a, const Block b)
{
    return a.minx > b.minx;
}

typedef complex<double> P;

//以下deq notesより
double dot(P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

double distance_ls_p(P a, P b, P c) {
    if ( dot(b-a, c-a) < EPS ) return abs(c-a);
    if ( dot(a-b, c-b) < EPS ) return abs(c-b);
    return abs(cross(b-a, c-a)) / abs(b-a);
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
    ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

double min( double a, double b)
{
    if ( a < b )
        return a;
    else
        return b;
}

int main (int argc, const char * argv[])
{
    while (1)
    {
        set<Block, greater<Block> > blocks;
        int N;
        int sx, sy, ex, ey;
        int minx, miny, maxx, maxy, h;
        
        blocks.clear();
        
        cin >> N;
        if ( N == 0 )
        {
            break;
        }
        
        cin >> sx >> sy >> ex >> ey;
        
        for ( int i=0; i<N; i++ )
        {  
            cin >> minx >> miny >> maxx >> maxy >> h;
            blocks.insert( Block( minx, miny, maxx, maxy, h ) );
        }
        
        //各ブロックに対して半径を計算し、最小となる値を求める
        set<Block>::iterator it = blocks.begin();
        double r = 20000.0; //半径
        
        while ( it != blocks.end() )
        {
            double dist = 20000.0; //線分とブロックの距離
            
            P a, b, c, d;
            a.real() = sx; a.imag() = sy; //始点
            b.real() = ex; b.imag() = ey; //終点
            
            //ブロックと線分の関係は4通り
            //1.線分がブロックに含まれる(r=0)
            //2.線分上にブロックがある(r=0)
            //3.線分がブロックの一つの角と最も近い
            //4.線分の端点がブロックの一辺と最も近い
            
            //1.線分がブロックに含まれる場合
            if( (*it).minx <= sx && sx <= (*it).maxx &&
               (*it).miny <= sy && sy <= (*it).maxy &&
               (*it).minx <= ex && ex <= (*it).maxx &&
               (*it).miny <= ey && ey <= (*it).maxy )
            {
                r = 0;
                break;
            }
            
            //2.線分上にブロックがある場合
            int flag = 1;
            c.real() = (*it).minx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).maxy;
            flag *= !is_intersected_ls(a, b, c, d);
            
            c.real() = (*it).minx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).maxy;
            flag *= !is_intersected_ls(a, b, c, d);
            
            c.real() = (*it).maxx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).miny;
            flag *= !is_intersected_ls(a, b, c, d);
            
            c.real() = (*it).maxx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).miny;
            flag *= !is_intersected_ls(a, b, c, d);
            
            if ( !flag )
            {
                r = 0;
                break;
            }
            
            //3.線分がブロックの一つの角と最も近い場合
            c.real() = (*it).minx; c.imag() = (*it).miny;
            dist = min( distance_ls_p(a, b, c), dist );
            
            c.real() = (*it).maxx; c.imag() = (*it).miny;
            dist = min( distance_ls_p(a, b, c), dist );
            
            c.real() = (*it).minx; c.imag() = (*it).maxy;
            dist = min( distance_ls_p(a, b, c), dist );
            
            c.real() = (*it).maxx; c.imag() = (*it).maxy;
            dist = min( distance_ls_p(a, b, c), dist );
            
            //4.線分の端点がブロックの一辺と最も近い
            c.real() = (*it).minx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).maxy;
            dist = min( distance_ls_p(c, d, a), dist ); //sとの判定
            dist = min( distance_ls_p(c, d, b), dist ); //eとの判定
            
            c.real() = (*it).minx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).maxy;
            dist = min( distance_ls_p(c, d, a), dist ); //sとの判定
            dist = min( distance_ls_p(c, d, b), dist ); //eとの判定
            
            c.real() = (*it).maxx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).miny;
            dist = min( distance_ls_p(c, d, a), dist ); //sとの判定
            dist = min( distance_ls_p(c, d, b), dist ); //eとの判定
            
            c.real() = (*it).maxx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).miny;
            dist = min( distance_ls_p(c, d, a), dist ); //sとの判定
            dist = min( distance_ls_p(c, d, b), dist ); //eとの判定
            
            if (r <= dist)
            {
                ++it;
                continue;
            }
            //距離よりhが大きかったらr=d（小さければ更新）
            if ((*it).h > dist)
            {
                r = min( dist, r );
            }
            //距離がhより大きければr=(d^2+h^2)/2h
            else
            {
                double temp = (pow(dist,2)+(pow((double)(*it).h,2)))/(2*(*it).h);
                r = min ( temp, r );
            }
            ++it;
        }
        cout << fixed << setprecision(6) << r << endl;
    }
    return 0;
}

