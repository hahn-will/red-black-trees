#include "RedBlackTree.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  RedBlackTree *rbt = new RedBlackTree();
  srand (time(NULL));

  for (int i = 0; i < 30; i++) {
    int val = rand() %50 + 1;
    rbt->AddKey(val);
    cout << val << endl;
  }
  

  rbt->TreeOut(cout);
  delete(rbt);
}
