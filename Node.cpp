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

void restructure(Node *grand_parent, Node *parent, Node *uncle, Node *child, Node **root) {
  if (child->key <= parent->key) {
    if (parent->key <= grand_parent->key) {
      parent->left = child;
      child->parent = parent;
      parent->right = grand_parent;
      grand_parent->parent = parent;
      parent->isRed = false;
      child->isRed = true;
      grand_parent->isRed = true;
      *root = parent;
    }
    else {
      child->left = parent;
      child->right = grand_parent;
      parent->parent = child;
      grand_parent->parent = child;
      child->isRed = false;
      parent->isRed = true;
      grand_parent->isRed = true;
      *root = child;
    }
  }
  else {
    if (parent->key <= grand_parent->key) {
      child->right = parent;
      child->left = grand_parent;
      parent->parent = child;
      grand_parent->parent = child;
      child->isRed = false;
      parent->isRed = true;
      grand_parent->isRed = true;
      *root = child;
    }
    else {
      parent->right = grand_parent;
      parent->left = child;
      child->parent = parent;
      grand_parent->parent = parent;
      parent->isRed = false;
      child->isRed = true;
      grand_parent->isRed = true;
      *root = parent;
    }
  }
}

void recolor(Node *grand_parent, Node *parent, Node *uncle, Node *child, Node **root) {
  uncle->isRed = false;
  child->isRed = true;
  grand_parent->isRed = true;
  parent->isRed = false;
}

Node *insert_node(Node **grand_parent, Node *parent,  Node *new_node, bool left) {
  if (!(*grand_parent)) {
    if (!parent) {
      *grand_parent = new_node;
      new_node->parent = NULL;
      new_node->isRoot = true;
      new_node->isRed = false;
      return new_node;
    }
    else {
      *grand_parent = parent;
      parent->parent = NULL;
      new_node->isRoot = false;
      new_node->parent = parent;
      if (left) {
        parent->left = new_node;
      }
      else {
        parent->right = new_node;
      }
      return parent;
    }
  }
  else {
    if (!parent) {
      if (new_node->key <= (*grand_parent)->key) {
        (*grand_parent)->left = new_node;
        return *grand_parent;
      }
      else {
        (*grand_parent)->right = new_node;
        return *grand_parent;
      }
    }
  }
  Node *child = NULL;
  Node *uncle = NULL;
  if (new_node->key < parent->key) {
    insert_node(&parent, parent->left, new_node, true);
    child = parent->left;

  }
  else {
    insert_node(&parent, parent->right, new_node, false);
    child = parent->right;
  }
  uncle = (*grand_parent)->key >= parent->key ? (*grand_parent)->right : (*grand_parent)->left;
  if (child->isRed && parent->isRed) {
    if (!uncle || !uncle->isRed) {
      restructure(*grand_parent, parent, uncle, child, &((*grand_parent)->parent));
    }
    else {
      recolor(*grand_parent, parent, uncle, child, grand_parent);
    }
  }

  /*    if (!parent) {
      *root = new_node;
      new_node->parent = NULL;
      new_node->isRoot = true;
      new_node->isRed = false;
      return *root;
    }

    if (parent->isRoot) {
      *root = new_node;
      new_node->parent = parent;
      return *root;
    }

    if (new_node->isRed && parent->isRed) {
      Node *child = new_node;
      Node *uncle = (left ? parent->parent->right 
                          : parent->parent->left);
      Node *grand_parent = parent->parent;
      if (!uncle || !uncle->isRed) {
        restructure(grand_parent, parent, uncle, child, root);
      }
      else {
        recolor(grand_parent, parent, uncle, child, root);
      }
    }

    return *root;
  }

  if (new_node->key <= (*root)->key) {
    insert_node((*root), (*root), new_node, true);    
  }
  else {
    insert_node(&((*root)->right), (*root), new_node, false);
  }
  if (parent && parent->isRed && (*root)->isRed) {
      Node *child = (*root);
      Node *uncle = (left ? parent->parent->right 
                          : parent->parent->left);
      Node *grand_parent = parent->parent;
      if (!uncle || !uncle->isRed) {
        restructure(grand_parent, parent, uncle, child, root);
      }
      else {
        recolor(grand_parent, parent, uncle, child, root);
      }
    }*/
  return *grand_parent;
}

void add_key(Node **root, int key) {
  Node *new_node = new Node {NULL, NULL, NULL, key, true, false};
  insert_node(root, NULL, new_node, false);
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

