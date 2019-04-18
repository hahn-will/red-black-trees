#include "Node.h"

Node *find_node(Node *root, int key) {
  if (!root) {
    return NULL;
  }

  if (root->key == key) {
    return root;
  }  

  if (key <= root->key) {
    return find_node(root->left, key);
  }
  return find_node(root->right, key);
}

Node *insert_node(Node **root, Node *new_node) {
  if (!(*root)) {
    *root = new_node;
    return *root;
  }

  if (new_node->key < (*root)->key) {
    insert_node(&((*root)->left), new_node);
    return *root;
  }
  if (new_node->key > (*root)->key) {
    insert_node(&((*root)->right), new_node);
    return *root;
  }
}

void add_key(Node **root, int key) {
  Node *new_node = new Node {NULL, NULL, NULL, key};
  insert_node(root, new_node);
}

void tree_command(Node *root, ostream output) {
  if (!root) {
    return
  }
  output << 
  tree_command(
}
