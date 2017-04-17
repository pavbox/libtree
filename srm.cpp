

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

  int defaultValues[9] = { 7, 8, 20, 6, 9, 3, 10, 4, 5 };



  // init specific tree
  struct Tree* root = new Tree(10, 10, 0, 0, 0, nullptr, nullptr);

	root->left = new Tree(2, 2, 0, 0, 0, nullptr, nullptr);
	root->right = new Tree(9, 9, 0, 0, 0, nullptr, nullptr);
	root->left->left = new Tree(21, 21, 0, 0, 0, nullptr, nullptr);
	root->left->right = new Tree(1, 1, 0, 0, 0, nullptr, nullptr);

	root->left->left->left = new Tree(7, 7, 0, 0, 0, nullptr, nullptr);
  root->left->left->left->right = new Tree(1, 1, 0, 0, 0, nullptr, nullptr);

	root->left->right->left = new Tree(12, 12, 0, 0, 0, nullptr, nullptr);
	root->left->right->left->left = new Tree(8, 8, 0, 0, 0, nullptr, nullptr);
	root->left->right->left->right = new Tree(6, 6, 0, 0, 0, nullptr, nullptr);

	root->left->right->right = new Tree(25, 25, 0, 0, 0, nullptr, nullptr);
	root->left->right->right->left = new Tree(4, 4, 0, 0, 0, nullptr, nullptr);
	root->left->right->right->right = new Tree(3, 3, 0, 0, 0, nullptr, nullptr);

  // print source tree
  std::cout << '\n' << "[#] Source tree:" << '\n' << '\n';
  printTree(root, 1);


  // init default value for subtreeRoot node
  Tree* subtreeRoot = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);

  // get max path sum and root node
  int maxsum = INT_MIN;
  subtreeRoot = getMaxSumAndRoot(root, maxsum);

  std::cout << "Max path sum:  " << maxsum << '\n';
  std::cout << "Max path root: " << subtreeRoot->key << '\n';

  // init default root of clone tree
  Tree* copied = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);

  // copy source tree
  copied = copyTree(root, copied);

  // get cented of clonned tree.
  // is equals center of source tree
  copied = getCenterOfTree(copied);

  // show center node
  std::cout << "Center node of max path: " << copied->key << '\n';

  // inorder print of source tree
  inOrderLeft(root);
  std::cout << '\n';

  // if center element equals tree node -> remove element once
  // else remove both elements
  if (compareNodes(copied, subtreeRoot)) {
    std::cout << " [#] -> Center node and root node of max path is one element, just delete." << '\n';
    removeNodeByKey(root, subtreeRoot->key);
  } else {
    removeNodeByKey(root, copied->key);
    removeNodeByKey(root, subtreeRoot->key);
  }

  // inorder print of source tree
  inOrderLeft(root);
  std::cout << '\n';

  // print result source tree
  printTree(root, 1);

  int stop;
  cin >> stop;
  return 0;
}
