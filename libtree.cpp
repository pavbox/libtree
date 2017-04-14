
/**
 * Tree lib contains structures and functions for work with trees
 *
 * Created by pavbox.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "libtree.h"

namespace Libtree {
  /**
   * Create Tree structure.
   */


  void showItem(Tree* tree) {
    std::cout << tree->value << " ";
  }

  void showTree(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      showItem(tree);
      showTree(tree->left);
      showTree(tree->right);
    }
  }


  // building Tree by array.
  Tree* buildTree(Tree* tree, int value) {
    // Указатель передается по значению
    // соответственно, в контексте выше вызова функции он все еще 0x0 (nullptr)
    // и так как нам нужно изменить дефолтный указатель, мы возвращаем его.
    if (tree == nullptr) {
      tree = new Tree(value, nullptr, nullptr);
    } else {
      if (value < tree->value) tree->left  = buildTree(tree->left, value);
      if (value > tree->value) tree->right = buildTree(tree->right, value);
    }

    return tree;
  }

  void printTree(Tree* root, int offset) {
    int i;
    if (root != nullptr) {
      printTree(root->left, offset + 1);

      for (i = 1; i < offset; i++) std::cout << "----";
      printf ("%i   \n", root->value);

      printTree(root->right, offset + 1);
    }
  }
}
