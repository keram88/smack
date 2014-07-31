#include <stdio.h>
#include <stdlib.h>
#include "smack.h"

// @expect 2 verified, 0 errors?

int g;

void p() {
  requires(g > 0);
  ensures(g > 0);
  for (int i=0; i < 10; i++) {
    invariant(g > 0);
    g++;
  }
  return;
}

int main(void) {
  g = 1;
  for (int i=0; i<10; i++) {
    invariant(g > 0);
    p();
  }
  __SMACK_assert(g > 0);
  return 0;
}