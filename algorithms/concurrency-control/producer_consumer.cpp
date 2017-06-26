typedef struct node {
  int item;
  node *next;
} NODE;

Producer:
  /* Produce a new item */
  (big piece of code);

  newnode = (NODE*)malloc(sizeof(NODE));
  newnode->item = NewItem;
  newnode->next = first;
  first = newnode;

Consumer:
  while(!first);
  mynode = first;
  first = first->next;
  item = mynode->item;

  /* Consume the item */
  (big piece of code);

/* Case where producer's item get ignored  */
C: mynode = first;
P: newnode->next = first;
P: first = newnode;
C: first = first->next;

/* Case where consumer's deletion get ignored */
C: mynode = first;
P: newnode->next = first;
C: first = first->next;
P: first = newnode;
