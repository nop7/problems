//
//  main.cpp
//  AOJ1157
//
//  Created by 直樹 三輪 on 13/05/12.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <set>
#include <complex>
#include <iomanip>
using namespace std;

struct Block
{
    int minx, miny, maxx, maxy, h;
    Block(int mx, int my, int Mx, int My, int vh)
    {
        minx = mx; miny = my; maxx = Mx; maxy = My; h = vh;
    };
};

bool operator> (const Block a, const Block b)
{
    return a.minx > b.minx;
}

typedef complex<double> P;

double dot(P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

double distance_ls_p(P a, P b, P c) {
    if ( dot(b-a, c-a) < 0.0 ) return abs(c-a);
    if ( dot(a-b, c-b) < 0.0 ) return abs(c-b);
    return abs(cross(b-a, c-a)) / abs(b-a);
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < 0.0 ) &&
    ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < 0.0 );
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
            blocks.insert(Block(minx, miny, maxx, maxy, h));
        }
        
        //各ブロックに対して
        set<Block>::iterator it = blocks.begin();
        double r = 20000.0;
        while (it != blocks.end())
        {
            double dist = 20000.0;
            double d_cmp = 0;
            //sとeが含まれてるなら
            if((*it).minx <= sx && sx <= (*it).maxx &&
               (*it).miny <= sy && sy <= (*it).maxy &&
               (*it).minx <= ex && ex <= (*it).maxx &&
               (*it).miny <= ey && ey <= (*it).maxy )
            {
                r = 0;
                break;
            }
            //線分が交われば0
            P a, b, c, d;
            a.real() = sx; a.imag() = sy;
            b.real() = ex; b.imag() = ey;
            c.real() = (*it).minx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).maxy;
            //線分判定
            if (is_intersected_ls(a, b, c, d))
            {
                r = 0;
                break;
            }
            //sとの判定
            d_cmp = distance_ls_p(c, d, a);
            if (dist > d_cmp)
                dist = d_cmp;
            //eとの判定
            d_cmp = distance_ls_p(c, d, b);
            if (dist > d_cmp)
                dist = d_cmp;
            c.real() = (*it).minx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).maxy;
            //線分判定
            if (is_intersected_ls(a, b, c, d))
            {
                r = 0;
                break;
            }
            //sとの判定
            d_cmp = distance_ls_p(c, d, a);
            if (dist > d_cmp)
                dist = d_cmp;
            //eとの判定
            d_cmp = distance_ls_p(c, d, b);
            if (dist > d_cmp)
                dist = d_cmp;
            c.real() = (*it).maxx; c.imag() = (*it).maxy;
            d.real() = (*it).maxx; d.imag() = (*it).miny;
            //線分判定
            if (is_intersected_ls(a, b, c, d))
            {
                r = 0;
                break;
            }
            //sとの判定
            d_cmp = distance_ls_p(c, d, a);
            if (dist > d_cmp)
                dist = d_cmp;
            //eとの判定
            d_cmp = distance_ls_p(c, d, b);
            if (dist > d_cmp)
                dist = d_cmp;
            c.real() = (*it).maxx; c.imag() = (*it).miny;
            d.real() = (*it).minx; d.imag() = (*it).miny;
            //線分判定
            if (is_intersected_ls(a, b, c, d))
            {
                r = 0;
                break;
            }
            //sとの判定
            d_cmp = distance_ls_p(c, d, a);
            if (dist > d_cmp)
                dist = d_cmp;
            //eとの判定
            d_cmp = distance_ls_p(c, d, b);
            if (dist > d_cmp)
                dist = d_cmp;
            
            
            //線と最も近い点までの距離(d)を求める
            a.real() = sx; a.imag() = sy;
            b.real() = ex; b.imag() = ey;
            c.real() = (*it).minx; c.imag() = (*it).miny;
            if (dist > distance_ls_p(a, b, c))
                dist = distance_ls_p(a, b, c);
            c.real() = (*it).maxx; c.imag() = (*it).miny;
            if (dist > distance_ls_p(a, b, c))
                dist = distance_ls_p(a, b, c);
            c.real() = (*it).minx; c.imag() = (*it).maxy;
            if (dist > distance_ls_p(a, b, c))
                dist = distance_ls_p(a, b, c);
            c.real() = (*it).maxx; c.imag() = (*it).maxy;
            if (dist > distance_ls_p(a, b, c))
                dist = distance_ls_p(a, b, c);

            if (r <= dist)
            {
                ++it;
                continue;
            }
            //距離よりhが大きかったらr=d（小さければ更新）
            if ((*it).h > dist)
            {
                r = dist;
            }
            //距離がhより大きければr=(d^2+h^2)/2h
            else
            {
                double temp = (pow(dist,2)+(pow((double)(*it).h,2)))/(2*(*it).h);
                if (temp < r)
                    r = temp;
            }
            ++it;
        }
        cout << fixed << setprecision(6) << r << endl;
    }
    return 0;
}

