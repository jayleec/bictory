struct List {
  struct List *next;
  int val;
};

struct List * make_node(int x){
  struct List *node = malloc (sizeof(struct List));
  if (node == 0) exit(1);
  node->val = x + 1;
  return node;
}

int use_nodes(){
  int x = 10;
  struct List *cur = make_node(x);
  if (cur->val > x){
    cur->next = make_node(x + 1);
  } 
  
  x = x / (cur->val - cur->next->val + 1); //@violation DIV_BY_ZERO
  
  if (cur->next->val < x + 1){ 
    free(cur->next);
  }
  
  free(cur);
  return x; //@violation LEAK.MEMORY
}
