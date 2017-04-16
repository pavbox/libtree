

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

  // for (size_t idx_i = 0; idx_i < 9; idx_i++) {
  //   tree = insertKeyToSubtree(tree, defaultValues[idx_i]);
  // }

  struct Tree* root = new Tree(10, 10, 0, 0, 0, nullptr, nullptr);

	// struct Node *resultRoot = newNode(0);

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

  std::cout << '\n' << '\n';
  // printTree(tree, 1);
  printTree(root, 1);

  // tree = findMaxPathRoot(tree);

  // printMaxPathNodes(tree->left);

  Tree* subtreeRoot = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);

  int maxsum = INT_MIN;
  subtreeRoot = getMaxSumAndRoot(root, maxsum);

  std::cout << "Max path sum:  " << maxsum << '\n';
  std::cout << "Max path root: " << subtreeRoot->key << '\n';

  printTree(root, 1);

  Tree* copied = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);
  copied = copyTree(root, copied);

  copied = getCenterOfTree(copied);

  // remove center and root of max path
  inorder(root);
  std::cout << '\n';

  if (compareNodes(copied, subtreeRoot)) {
    std::cout << "center and root max path is one element, just delete." << '\n';
    removeNodeByKey(root, subtreeRoot->key);
  } else {
    removeNodeByKey(root, copied->key);
    removeNodeByKey(root, subtreeRoot->key);
  }

  inorder(root);
  std::cout << '\n';

  printTree(root, 1);

  std::cout << "amount of lists: " << getNodeAmount(copied) << '\n';
  std::cout << "center: " << copied->key << '\n';

  int stop;
  cin >> stop;
  return 0;
}
