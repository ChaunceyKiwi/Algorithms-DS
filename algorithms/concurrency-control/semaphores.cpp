/* P(S) blocks the calling process if S <= 0, once unblocked it decrements S */
/* V(S) increments S. If S > 0, then one process blocked on P(S) becomes unblocked */

P(S) {
  while (S <= 0);
  S--;
}

V(S) {
  S++;
}

/* Application1: critical section */
while(1) {
  P(S);
  Critical Section;
  V(S);
  Non-critical Section;
}

/* Application2: process synchronization, initialize S as 0 */
/* wants P1 to complete before P2 begins */
P1:
  code for P1;
  V(S);

P2:
  P(S);
  code for P2;


/* Producer and Consumer using Semaphore */
/* Tag1 cannot be swapped with Tag2: if so, producer will be prevented from producing new item if buffer is full, since buffer might be available when
 a new item is being produced, swapping will lower down the efficiency */
/* Tag2 cannot be swapped with Tag3: if so, it could result in a situation that the producer is allowed to enter its critical section and be blocked on
 P(empty) since there is no free buffer. And only consumer can free the buffer, which does not hold mutex and is blocked. Thus it will be a deadlock. */

SEM full = 0;
SEM empty = N;
SEM mutex = 1;

Producer:
while(1) {
  Tag1: produce new item;
  Tag2: P(empty); /* make sure there is at least one empty buffer */
  Tag3: P(mutex); /* to guard against concurrent buffer manipulation */
  add new item to the buffer;
  V(mutex); /* signal OK for buffer access by consumer */
  V(full);  /* records addition of item to buffer */
}

Consumer:
while(1) {
  P(full); /* wait until at least 1 buffer is filled */
  P(mutex); /* wait for concurrency OK from producer */
  remove item from buffer;
  V(mutex); /* signal concurrency OK to producer */
  V(empty); /* record the addition of 1 empty buffer */
  consume item;
}

typedef struct sem {
  int value;
  list_of_process plist; /* processes blocked on this semaphore */
} semaphore;

P(S):
  S.value--;
  if (S.value < 0) {
    add this process to S.plist;
    block;
  }

V(S):
  S.value++;
  if (S.value <= 0) {
    get a process P from P.plist;
    wakeup(P);
  }


/* Readers and Writers problem */
/* When a writer is writing data, no readers should be allowed to read. */
/* When a reader is reading data, no writer should be allowed to write. */
SEM mutex = 1;
SEM wrt = 1;
int readcount = 1;

writer:
  while (1) {
    P(wrt);
    /* writing is performed */
    V(wrt);
  }

reader:
  while(1) {
    P(mutex);
    readcount++;
    if (readcount == 1) {
      P(wrt);
    }
    V(mutex);
    /* reading is performed */
    P(mutex);
    readcount--;
    if (readcount == 0) {
      V(wrt);
    }
    V(mutex);
  }

/* Dining-Philosophers Problem */
/* Can lead to dead lock if each pholosopher grabs its first chopstick*/
while(1) {
  P(chopstick[i]);
  P(chopstick[(i+1) % 5]);
  /* eat */
  V(chopstick[i]);
  P(chopstick[(i+1) % 5]);
  /* think */
}
