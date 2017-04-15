

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

  // int defaultValues[9] = { 10, 8, 20, 6, 9, 4, 7, 3, 5 };
  int defaultValues[9] = { 7, 8, 20, 6, 9, 3, 10, 4, 5 };

  for (size_t idx_i = 0; idx_i < 9; idx_i++) {
    tree = insertKeyToSubtree(tree, defaultValues[idx_i]);
  }

  std::cout << '\n' << '\n';
  printTree(tree, 1);

  tree = findMaxPathRoot(tree);

  printMaxPathNodes(tree->left);

  std::cout << tree->key << '\n';
  std::cout << tree->value << '\n';
  std::cout << tree->height << '\n';
  std::cout << tree->weight << '\n';

  int stop;
  cin >> stop;
  return 0;
}
