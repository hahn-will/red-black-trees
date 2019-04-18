#ifndef NODE_H__

#include <fstream>

typedef struct node {
  struct node *left;
  struct node *right;
  struct node *parent;

  int key;
} Node;

Node *find_node(Node *, int key);

Node *insert_node(Node **, Node *);

void add_key(Node **, int);

void tree_command(Node *, ostream);

Node *create_node(int key);

Node *delete_node(Node *);

Node *delete_key(int);

#endif
