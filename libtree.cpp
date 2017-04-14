
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

  void preOrderLeft(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      showItem(tree);
      preOrderLeft(tree->left);
      preOrderLeft(tree->right);
    }
  }

  void preOrderRight(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      showItem(tree);
      preOrderRight(tree->right);
      preOrderRight(tree->left);
    }
  }

  void postOrderLeft(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      postOrderLeft(tree->left);
      postOrderLeft(tree->right);
      showItem(tree);
    }
  }

  void postOrderRight(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      postOrderRight(tree->right);
      postOrderRight(tree->left);
      showItem(tree);
    }
  }


  void inOrderLeft(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      inOrderLeft(tree->left);
      showItem(tree);
      inOrderLeft(tree->right);
    }
  }

  void inOrderRight(Tree* tree) {
    if (tree != nullptr) {
      std::cout << "Items: ";
      inOrderRight(tree->right);
      showItem(tree);
      inOrderRight(tree->left);
    }
  }



  // N. Virt - print tree
  void printTree(Tree* root, int offset) {
    int i;
    if (root != nullptr) {
      printTree(root->left, offset + 1);

      for (i = 1; i < offset; i++) std::cout << "--->";
      printf ("%i:%i   \n", root->value, root->key);

      printTree(root->right, offset + 1);
    }
  }


  // build fully balanced tree
  void buildBalancedTree(Tree* tree, int height) {
    Tree* newLeftNode;
    Tree* newRightNode;

    if (height > 0) {
      newLeftNode  = new Tree(height, height, 0, 0, 0, nullptr, nullptr);
      newRightNode = new Tree(height, height, 0, 0, 0, nullptr, nullptr);

      tree->left  = newLeftNode;
      tree->right = newRightNode;

      buildBalancedTree(tree->left,  height - 1);
      buildBalancedTree(tree->right, height - 1);
    }
  }


  int getNodeHeight(Tree* tree) {
    int result = 0;
    if (tree != nullptr) {
      result = tree->height;
    }
    return result;
  }


  int setNodeHeight(Tree* tree) {
    int left = 0, right = 0;

    if (tree != nullptr) {
      left = setNodeHeight(tree->left);
      right = setNodeHeight(tree->right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    } else {
      return -1;
    }
  }


  Tree* insertKeyToSubtree(Tree* root, int key) {
    if (root == nullptr) {
      root = new Tree(key, key, 0, 0, 0, nullptr, nullptr);
    } else {
      if (key < root->key)
        root->left = insertKeyToSubtree(root->left, key);
      else
        root->right = insertKeyToSubtree(root->right, key);
    }

    updateTreeNodes(root, 0, 0);
    return root;
  }

  void updateTreeNodes(Tree* node, int depth, int weight) {
    if (node != nullptr) {
      node->depth = depth;
      node->weight = weight;
      node->height = setNodeHeight(node);

      if (node->left  != nullptr) updateTreeNodes(node->left,  depth + 1, weight - 1);
      if (node->right != nullptr) updateTreeNodes(node->right, depth + 1, weight + 1);
    }
  }


  Tree* findMinNodeByKey(Tree* node) {
    if (node->left != nullptr) {
      return findMinNodeByKey(node->left);
    } else {
      return node;
    }
  }

  Tree* findMaxNodeByKey(Tree* node) {
    if (node->right != nullptr) {
      return findMaxNodeByKey(node->right);
    } else {
      return node;
    }
  }



  Tree* removeMinNode(Tree* node) {
    if (node->left == nullptr) {
      return node->right;
    } else {
      node->left = removeMinNode(node->left);
      return node;
    }
  }


  Tree* removeMaxNode(Tree* node) {
    if (node->right == nullptr) {
      return node->left;
    } else {
      node->right = removeMinNode(node->right);
      return node;
    }
  }


  Tree* removeNodeByKeyRight(Tree* node, int key) {
    Tree* leftSubtree;
    Tree* rightSubtree;
    Tree* minNode;

    if (node == nullptr) return nullptr;

    if (key < node->key) node->left = removeNodeByKeyRight(node->left, key);
    if (key > node->key) node->left = removeNodeByKeyRight(node->left, key);
    if (key == node->key) {
      leftSubtree = node->left;
      rightSubtree = node->right;

      if (rightSubtree == nullptr) {
        node = leftSubtree;
      } else {
        minNode = findMinNodeByKey(rightSubtree);
        minNode->right = removeMinNode(rightSubtree); // returns all childs ?
        minNode->left = leftSubtree;
        node = minNode;
        return node;
      }
    }
    // if (node != nullptr) return node; // ???
    if (node == nullptr)
      return nullptr;
    else
      return node;
  }



  Tree* removeNodeByKeyLeft(Tree* node, int key) {
    Tree* leftSubtree;
    Tree* rightSubtree;
    Tree* maxNode;

    if (node == nullptr) return nullptr;

    if (key < node->key) node->left = removeNodeByKeyLeft(node->left, key);
    if (key > node->key) node->left = removeNodeByKeyLeft(node->left, key);
    if (key == node->key) {
      leftSubtree = node->left;
      rightSubtree = node->right;

      if (rightSubtree == nullptr) {
        node = leftSubtree;
      } else {
        maxNode = findMaxNodeByKey(rightSubtree);
        maxNode->right = removeMaxNode(rightSubtree); // returns all childs ?
        maxNode->left = leftSubtree;
        node = maxNode;
        return node;
      }
    }

    if (node == nullptr)
      return nullptr;
    else
      return node;
  }


  int getChildsAmount(Tree* node) {
    if (node != nullptr) {
      return (1 + getChildsAmount(node->left) + getChildsAmount(node->right));
    } else {
      return 0;
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



  // 29) Вспомогательная Функция (по одной ветви) вычисления суммы конечных элементов пути максимальной длины,
  // проходящей через заданный узел

  int getMaxPath(Tree* root) {
    if ((root->left == nullptr) && (root->right == nullptr)) return root->key;
    if ((root->left != nullptr) && (root->right == nullptr)) return getMaxPath(root->left);
    if ((root->left == nullptr) && (root->right != nullptr)) return getMaxPath(root->right);
    if ((root->left != nullptr) && (root->right != nullptr)) {
      // check length of a subtrees
      if ((root->left->height) >= (root->right->height))
        return getMaxPath(root->left);
      else
        return getMaxPath(root->right);
    }
  }

  // Основная Функция (по обеим ветвям) вычисления суммы конечных элементов пути
  // максимальной длины, проходящей через заданный узел
  // складывает два листа лол
  int getMaxPathAvg(Tree* root) {
    int maxLength = 0;
    if (root != nullptr) {
      if (root->left != nullptr)
        maxLength += getMaxPath(root->left);
      else
        maxLength += root->key;

      if (root->right != nullptr)
        maxLength += getMaxPath(root->right);
      else
        maxLength += root->key;
    }
    return maxLength;
  }


  // Функция определения максимальной длины пути, проходящего через заданный узел
  int getMaxPathFromNode(Tree* root) {
    int maxLength = 0;

    if (root != nullptr) {
      if (root->left  != nullptr) maxLength += root->left->height  + 1;
      if (root->right != nullptr) maxLength += root->right->height + 1;
    }
    return maxLength;
  }






  Tree* findMaxPathRoot(Tree* root) {
    int maxLength = 0;
    int rootListSum = 10000;
    Tree* resultRoot = nullptr;

    resultRoot = compareNodesMaxPath(root, maxLength, rootListSum, resultRoot);
    return resultRoot;
  }

  Tree* compareNodesMaxPath(Tree* root, int maxLength, int rootListSum, Tree* resultRoot) {
    int tmpLength = 0;
    if (root != nullptr) {
      tmpLength = getMaxPathFromNode(root);

      if ((tmpLength > maxLength) || ((tmpLength == maxLength) && (getMaxPathAvg(root) < rootListSum))) {
        resultRoot = root;
        maxLength = tmpLength;
        rootListSum = getMaxPathAvg(root);
      }

      compareNodesMaxPath(root->left,  maxLength, rootListSum, resultRoot);
      compareNodesMaxPath(root->right, maxLength, rootListSum, resultRoot);

      return resultRoot;
    }
  }








}
