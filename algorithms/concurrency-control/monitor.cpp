/* Binary Semaphore via a Monitor */
/* Here P() and V() is atomic */
MONITOR SEM
  shared data:
    int busy;
    condition non-busy;

  Procedure:
    P() {
      if (busy) {
        nonbusy.wait();
      }
      busy++;
    }

    V() {
      busy = 0;
      nonbusy.signal(); /* If someone is waiting overhere, wake it up */
    }

  Init Code:
    begin() {
      busy = 0;
    }
END SEM


/* Producer and Consumer via Monitor */
MONITOR LISTMON
  shared data:
    LIST itemList;
    int maxListSize = N;
    condition bufAvail, itemAvail;

  Procedure:
  enqueueItem(item) {
    if (ListCount(itemList) == maxListSize) { /* no buffer available */
      bufAvail.wait();
    }
    ListPrepend(itemList, item);
    itemAvail.signal();
  }

  getItem() {
    if (ListCount(itemList) == 0) {
      itemAvail.wait();
    }
    item = ListTrim(itemList);
    bufAvail.signal();
    return item;
  }

  InitCode:
    itemList = ListCreate();
END LISTMON


/* Dining Philosophers via monitor */
monitor DP {
  enum {THINK, HUNGRY, EATING} state[5];
  condition self[5];

  void pickup(int i) {
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING) {
      self[i].wait();
    }
  }

  void putdown(int i) {
    state[i] = THINKING;
    test((i + 4) % 5);
    test((i + 1) % 5)
  }

  void test(int i) {
    if (state[(i+4) % 5] != EATING) && (state[i] == HUNGRY) && (state[(i+1)%5] != EATING) {
        state[i] = EATING;
        self[i].signal();
    }
  }

  initialization_code() {
    for (int i = 0; i < 5; i++) {
      state[i] = THINKING;
    }
  }
}


/*  Each philosopher invokes the operations in the following sequence: */

/* Think */
DinningPhilosopher.pickup();
/* Eat */
DinningPhilosopher.putdown();



/* Monitor Implementation using Semaphores */
Variables:
  SEM mutex = 1;
  SEM next = 0; /* how many processes are waiting */
  int next_count = 0;

/* Each procedure will be replaced by */
  P(mutex);
  // body of F
  if (next_count  = 0) {
    V(next);
  } else {
    V(mutex);
  }

/* For each condition variable, we have */
SEM x_sem = 0;
int x_count = 0;

/* x.wait() can be implemented as */
  x_count++;
  if (next_count > 0) {
    V(next);
   } else {
    V(mutex);
   }
  P(x_sem);
  x_count--;

/* x.signal() canbe implmented as */
if (x_count > 0) {
  next_count++;
  V(x_sem);
  P(next);
  next_count--;
}
