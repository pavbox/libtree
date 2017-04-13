
/**
 * Tree lib contains structures and functions for work with threes
 *
 * Created by pavbox.
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


/**
 * Create Tree structure.
 */
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


// prototypes
Tree* buildTree(Tree* tree, int value);
void showTree(Tree* tree);
void showItem(Tree* tree);


void showItem(Tree* tree) {
  cout << "Item: " << tree->value << '\n';
}

void showTree(Tree* tree) {
  std::cout << "showing tree..." << '\n';
  if (tree != nullptr) {
    showItem(tree);
    if (tree->left  != nullptr) showTree(tree->left);
    if (tree->right != nullptr) showTree(tree->right);
  }
}


// building Tree by array.
Tree* buildTree(Tree* tree, int value) {
  // BUG: баг с выводом значения, потому что указатель передается по значению
  // соответственно, в контексте выше вызова функции он все еще 0x0 (nullptr)
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


int main() {
  char answer = 'n';
  Tree* tree = nullptr;

  long int value;
  do {
    cout << "Please write item's value: ";
    cin >> value;

    // set tree
    tree = buildTree(tree, value);

    cout << "Can you add a new item to the Tree? (y/n) ";
    cin >> answer;
  } while (answer != 'n');

  printTree(tree, 1);
  int stop;
  cin >> stop;
  return 0;
}
