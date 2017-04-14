
/**
 * Tree lib contains structures and functions for work with trees
 *
 * Created by pavbox.
 */


/*
 *
 *  Whats contains;
 *  1. basic functions building tree
 *  2. basic print of tree
 *  3. basic delete/paste/add/move items of tree
 *  4. red-blue tree and methods
 *  5. abl-tree and methods
 *  6. advanced func: find max/min length, compare max/min paths, etc.
 *
 */

namespace Libtree {
  struct Tree {
    int value;
    Tree* left;
    Tree* right;

    Tree() {}

    // struct constructor
    Tree(int v, Tree* l, Tree* r) {
      value = v;
      left = l;
      right = r;
    }
  };

  void showTree(Tree* tree);
  void showItem(Tree* tree);
  void printTree(Tree* root, int offset);

  // building Tree by array.
  Tree* buildTree(Tree* tree, int value);
}
