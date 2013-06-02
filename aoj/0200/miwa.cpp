#include <iostream>
#include <queue>
using namespace std;

#define REP(i,p,n) for(int i=p; i<n; i++ )
#define rep(i,n) REP(i,0,n)

typedef struct State
{
    int station;
    int cost;
    State( int s, int c ) { station = s; cost = c; };
} state;

bool operator> ( const state &a, const state &b ) { return a.cost > b.cost; }

int main (int argc, const char * argv[])
{
    while ( 1 )
    {
        int n, m;
        cin >> n >> m;
        if ( n==0 && m==0 ) { break; }
        int cost[100][100], time[100][100];
        rep(i,m) { rep(j,m) { cost[i][j] = 0; time[i][j] = 0; } }
        
        rep(i,n)
        {
            int a, b, c, t;
            cin >> a >> b >> c >> t;
            a--; b--;
            cost[a][b] = c; cost[b][a] = c;
            time[a][b] = t; time[b][a] = t;
        }
        
        int k;
        cin >> k;
        rep(i,k)
        {
            int p, q, r;
            cin >> p >> q >> r;
            p--; q--;
            int check[100];
            rep(j,m) { check[j] = 0; }
            
            priority_queue< state, vector<state>, greater<state> > qu;
            state now_station( 0, 0 );
            qu.push( state( p, 0 ) );
            while ( !qu.empty() )
            {
                now_station = qu.top();
                qu.pop();
                
                if ( check[ now_station.station ] == 0 ) { check[ now_station.station ] = 1; }
                else { continue; }
                
                if ( now_station.station == q )
                {
                    cout << now_station.cost << endl;
                    break;
                }
                
                rep(j,m)
                {
                    if ( r == 0 && cost[now_station.station][j] != 0 )
                        qu.push( state( j, now_station.cost + cost[now_station.station][j] ) );
                    else if ( time[now_station.station][j] != 0 )
                        qu.push( state( j, now_station.cost + time[now_station.station][j] ) );
                }
            }        
        }
    }
}

