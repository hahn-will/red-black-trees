#ifndef NODE_H__

#include <ostream>

using namespace std;

typedef struct node {
  struct node *left;
  struct node *right;
  struct node *parent;

  int key;
  bool isRed;
  bool isRoot;
} Node;

Node *find_node(Node *, int key);

Node *insert_node(Node **, Node *, Node *, bool);

void add_key(Node **, int);

void tree_command(Node *, ostream &, int);

Node *create_node(int key);

Node *delete_node(Node *);

Node *delete_key(int);

void flush_tree(Node **);

#endif
