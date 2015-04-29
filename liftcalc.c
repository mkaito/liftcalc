#include <stdio.h>
#include <stdlib.h>

void print_help() {
  puts("Usage:\n"
       "\tliftcalc EMPTY WORK [SETS]");
}

/*
  Figure out how many reps a given set should have.

  TODO: Do not drop reps until the last 3 sets.
 */
int reps(int set) {
  switch (set) {
  case 1:
    return 5;
  case 2:
    return 3;
  default:
    return 2;
  }
}

/*
  Calculate weight for set

  TODO: Put on a curve, so we make bigger jumps at lighter weights, and smaller
  jumps at higher weights. Probably not important unless working very high
  weights and/or doing lots of steps.
 */
int weight(int empty, int wta, int step, int set) {
  /* Using integer division to round down to nearest multiple of 5 */
  return (empty + wta * (step * set) / 100) / 5 * 5;
}

int main(int argc, char *argv[]) {
  /*
    wta = weight to add, i.e., the difference between your lightest warmup and
    your work weight.
  */
  int empty, work, step, wta, i = 0;
  int sets = 3;

  /*
    argv[0] is the program name, so add 1 to desired argc.

    duncecap.png
  */
  if (argc >= 3) {

    if (argc >= 5) {
      puts("Unknown trailing arguments.");
      print_help();
      return 1;

    } else {
      empty = atoi(argv[1]);
      work = atoi(argv[2]);
      wta = work - empty;

      if (argc == 4) {
        sets = atoi(argv[3]) - 1;
      }

      /*
        Last step is implied in the jump to working weight
      */
      step = 100 / (sets + 1);

      printf("%ix5x2 ", empty);

      for (i = 1; i <= sets; i++) {
        printf("%ix%i ", weight(empty, wta, step, i), reps(i));
      }

      printf("%ix5x3\n", work);

      return 0;
    }

  } else {
    puts("Please provide at least two arguments.");
    print_help();
    return 1;
  }

  return 0;
}
