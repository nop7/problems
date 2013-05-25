#include <iostream>
#include <cmath>
using namespace std;

int state[10][10000];

void reverse (int i, int c)
{
    int cnt = 0;
    while ( i != 0 )
    {
        if ( i % 2 ==  1 )
        {
            for (int j = 0; j<c; j++)
                state[cnt][j] = 1-state[cnt][j];
        }
        i = i / 2;
        cnt++;
    }
}

int main (int argc, const char * argv[])
{
    while ( 1 ) 
    {
        int r, c;
        cin >> r >> c;
        if ( r == 0 && c == 0 )
            break;
        for ( int i=0; i<r; i++ )
        {
            for (int j=0; j<c; j++ )
                cin >> state[i][j];
        }
        int max_num_0 = 0;
        for ( int i=0; i<pow(2.0,r); i++ )
        {
            reverse( i, c );

            int num_0 = 0;
            for ( int j=0; j<c; j++ )
            {
                int temp = 0;
                for ( int k=0; k<r; k++ )
                {
                    if (state[k][j] == 0)
                        temp++;
                }
                if ( temp > r - temp )
                    num_0 += temp;
                else
                    num_0 += r - temp;
            }
            if (num_0 > max_num_0)
                max_num_0 = num_0;
            
            reverse( i, c );
            
        }
        cout << max_num_0 << endl;
    }
}


