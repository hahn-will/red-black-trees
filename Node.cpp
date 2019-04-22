#include "Node.h"

#include <cassert>

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

void recolor(Node *grand_parent, Node *parent, Node *uncle, Node *child, Node **root) {
  uncle->isRed = false;
  child->isRed = true;
  grand_parent->isRed = true;
  parent->isRed = false;
}

Node *repair_double_red(Node *new_node) {
  if (!(new_node && new_node->parent && new_node->parent->parent))
    return (new_node ? new_node->parent ? new_node->parent : new_node : NULL);
}

Node *insert_node(Node **root, Node *new_node) {
  assert(root);
  if (!(*root)) {
    *root = new_node;
    new_node->isRed = false;
    new_node->isRoot = true;
    return new_node;
  }

  Node *temp_root = *root;
  Node *prev_root = *root;
  bool left = false;

  while (temp_root) {
    prev_root = temp_root;
    if (new_node->key <= temp_root->key) {
      temp_root = temp_root->left;
      left = true;
    }
    else {
      temp_root = temp_root->right;
      left = false;
    }
  }

  if (left) {
    prev_root->left = new_node;
  }
  else {
    prev_root->right = new_node;
  }
  new_node->parent = prev_root;

  if (new_node->isRed && new_node->parent->isRed) {
    repair_double_red;
  }

  return *root;
}

void add_key(Node **root, int key) {
  Node *new_node = new Node {NULL, NULL, NULL, key, true, false};
  insert_node(root, new_node);
}

void tree_command(Node *root, ostream &output, int depth) {
  if (!root) {
    return;
  }
  for (int i = 0; i < depth; i++) {
    output << "    ";
  }
  output << root->key << endl;
  tree_command(root->left, output, depth + 1);
  tree_command(root->right, output, depth + 1);
}

Node *delete_node(Node *node) {
  return NULL;
}

Node *delete_key(int key) {
  return NULL;
}

void flush_tree(Node **root) {
  if (!(*root)) {
    return;
  }

  flush_tree(&((*root)->left));
  flush_tree(&((*root)->right));

  (*root)->left = NULL;
  (*root)->right = NULL;
  (*root)->parent = NULL;

  delete(*root);
  *root = NULL;
}

