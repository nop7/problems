#include <stdio.h>

#define INPUT_FILE "in2"
#define OUTPUT_FILE "out.txt"
#define MAX_SUPERMAN 10000

typedef struct _SUPERMAN {
  int p, q;
} SUPERMAN;

double CalcPMax();

SUPERMAN superman[MAX_SUPERMAN];
int num_superman;
int player_power;

int main()
{
  int i;
  FILE* fp_in;
  FILE* fp_out;

  fp_in = fopen(INPUT_FILE, "r");
  fp_out = fopen(OUTPUT_FILE, "w");

  while (!feof(fp_in)) {
    fscanf(fp_in, "%d %d", &num_superman, &player_power);
    //    printf("%d %d\n", num_superman, player_power);

    if (num_superman <= 0) break;

    for (i = 0; i < num_superman; ++i) {
      fscanf(fp_in, "%d %d", &superman[i].p, &superman[i].q);
      //printf("%d: %d %d\n", i, superman[i].p, superman[i].q);
    }

    fprintf(fp_out, "%.1lf\n", CalcPMax());
  }

  fclose(fp_out);
  fclose(fp_in);
}

double CalcPMax()
{
  int max_q, max_idx;
  double cur_p;
  int num_turn;
  char superman_flag[MAX_SUPERMAN] = {0};
  int i;

  //  for (i = 0; i < num_superman; ++i) superman_flag[i] = 1;
  num_turn = 1;
  cur_p = player_power;

  while (1) {
    max_q = -1;
    max_idx = -1;
    for (i = 0; i < num_superman; ++i) {
      if (superman_flag[i] == 0 && superman[i].p <= cur_p) {
	if (superman[i].q > max_q) {
	  max_idx = i;
	  max_q = superman[i].q;
	}
      }
    }

    if (max_idx >= 0) {
      //printf("-- fight %d : p=%d q=%d\n", max_idx, superman[max_idx].p, superman[max_idx].q);

      superman_flag[max_idx] = 1;
      cur_p += (double)superman[max_idx].q / (double)num_turn;
      ++num_turn;
    } else {
      break;
    }
  }

  return cur_p;
}
