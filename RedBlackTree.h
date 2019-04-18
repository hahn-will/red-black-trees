#ifndef RED_BLACK_TREE_H__

#include <fstream>

#include "Node.h"

class RedBlackTree{
  public:
    RedBlackTree();
    ~RedBlackTree();

    Node *FindNode(int key);
    Node *InsertNode(Node *);
    Node *DeleteNode(Node *);
    Node *DeleteKey(int key);
    void AddKey(int key);
    void TreeOut(ostream);

  private:
    Node *root;

    void flushTree();
};
#endif
