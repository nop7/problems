#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
  int w, h;
  int i, j, k;
  int senbei[10][10000];
  
  while (cin >> h >> w && h && w) {

    for (i = 0; i < h; ++i) {
      for (j = 0; j < w; ++j) {
	cin >> senbei[i][j];
      }
    }
    /*
      cout << "w:" << w << "h:" << h << endl;
      for (i = 0; i < h; ++i) {
      for (j = 0; j < w; ++j) {
      cout << senbei[i][j];
      }
      cout << endl;
      }
    */
    int max_count = 0;
    
    int mask_max = pow(2, h);
    int new_senbei[10][10000];
    for (i = 0; i <= mask_max; ++i) {
      for (j = 0; j < h; ++j) {
	if ( ((i >> j) & 0x01) == 0x01 ) {
	  for (k = 0; k < w; ++k) new_senbei[j][k] = (senbei[j][k] == 1) ? 0 : 1;
	} else {
	  for (k = 0; k < w; ++k) new_senbei[j][k] = (senbei[j][k] == 1) ? 1 : 0;
	}
      }

      // count
      int count = 0;
      for (j = 0; j < w; ++j) {
	int c = 0;
	for (k = 0; k < h; ++k) {
	  c += new_senbei[k][j];
	}
	count += max(c, h - c);
      }
      
      if (max_count < count) max_count = count;
    }
    
    cout << max_count << endl;
  }
}
