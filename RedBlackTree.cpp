#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
  root = NULL;
}

RedBlackTree::~RedBlackTree() {
  flushTree();
}

Node *RedBlackTree::FindNode(int key) {
  return find_node(root, key);
}

Node *RedBlackTree::InsertNode(Node *new_node) {
  return insert_node(&root, new_node);
}

void RedBlackTree::AddKey(int key) {
  add_key(&root, key);
}

void RedBlackTree::TreeOut(ostream output) {
  tree_command(root, output);
}

Node *RedBlackTree::DeleteNode(Node *node) {
  return delete_node(node);
}

Node *RedBlackTree::DeleteKey(int key) {
  return delete_key(key)
}
