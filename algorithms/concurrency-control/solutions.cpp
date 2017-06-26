/* Conditions for a solution */
/* 1. The execution of related critical sections must be mutually exclusive,
   that is, no two processes may access related critical sections simutaneously */
/* 2. One process, A, outside of its critical section, cannot prevent another process,
   B, from entering any of B's critical sections */
/* 3. When two processes want to enter their critical sections at the same time, the
   decision as to which one gets to go first cannot be postponed indefinitely */


/* Software non-solution 1 */
/* Violation to condition2: If the non-critical sections of Pi is much more time-consuming than Pj,
   Pj will be blocked from entering critical section in the next round until Pi is done. */
Pi:
while (1) {
  while (turn != i);
  Critical Section;
  turn = j;
  Non-critical Section;
}

Pj:
while (1) {
  while (turn != j);
  Critical Section;
  turn = i;
  Non-critical Section;
}

/* Software non-solution 2 */
/* Violation to condition1: Both processes can enter their critical sections at the same time */
Pi:
while (1) {
  while (flag[j]);
  flag[i] = true;
  Critical Section;
  flag[i] = false;
  Non-critical Section;
}

Pj:
while (1) {
  while (flag[i]);
  flag[j] = true;
  Critical Section;
  flag[j] = false;
  Non-critical Section;
}

/* Software non-solution 3 */
/* Violation to condition3: Decison as to who goes first is postphoned indefinitely */
Pi:
while (1) {
  flag[i] = true;
  while (flag[j]);
  Critical Section;
  flag[i] = false;
  Non-critical Section;
}

Pj:
while (1) {
  flag[j] = true;
  while (flag[i]);
  Critical Section;
  flag[j] = false;
  Non-critical Section;
}


/* Software feasible solution */
Pi:
while(1) {
  flag[i] = true;
  while (flag[j]) {
    if (turn == j) {
      flag[i] = false;
      while (turn == j);
      flag[i] = true;
    }
  }
  Critical Section;
  turn = j;
  flag[i] = false;
  Non-critical Section;
}

Pj:
while(1) {
  flag[j] = true;
  while (flag[i]) {
    if (turn == i) {
      flag[j] = false;
      while (turn == i);
      flag[j] = true;
    }
  }
  Critical Section;
  turn = i;
  flag[j] = false;
  Non-critical Section;
}

/* Hardware feasible solution */
BOOLEAN test_and_set(BOOLEAN *location) {
  BOOLEAN x;
  x = *location;
  *location = true;
  return(x);
}

while (1) {
  while(test_and_set(&lock)); /* busy wait */
  Critical Section;
  lock = false;
  Non-critical Section;
}
