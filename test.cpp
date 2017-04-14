

/**
 *  test.cpp: file for testing sorts algorithms.
 *  Just creates eight identical arrays and sort with different algorithms.
 *
 *  Created by pavbox.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libtree.h"

using namespace std;
using namespace Libtree;

int main() {
  char answer = 'n';
  Tree* tree = nullptr;

  long int value;
  do {
    cout << "Please write item's value: ";
    cin >> value;
    // set tree
    tree = insertKeyToSubtree(tree, value);

    cout << "Can you add a new item to the Tree? (y/n) ";
    cin >> answer;
  } while (answer != 'n');

  // printTree(tree, 1);

  // insertKeyToSubtree(tree, value);
  std::cout << '\n' << '\n';
  buildBalancedTree(tree, 2);
  printTree(tree, 1);

  tree = findMaxPathRoot(tree);

  std::cout << tree->key << '\n';
  std::cout << tree->value << '\n';
  std::cout << tree->height << '\n';
  std::cout << tree->weight << '\n';

  int stop;
  cin >> stop;
  return 0;
}
