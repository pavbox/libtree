
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
      printf ("%i   \n", root->key);

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
      return 0;
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






  // 33) Вспомогательная процедура (по левой ветви) ПЕЧАТИ узлов пути максимальной длины, проходящей через заданный узел
  void printMaxPathLeft(Tree* root) {
    if ((root->left == nullptr) && (root->right == nullptr)) {
      std::cout << root->key << ' ';
    } else {
      if ((root->left != nullptr) && (root->right == nullptr)) printMaxPathLeft(root->left);
      if ((root->left == nullptr) && (root->right != nullptr)) printMaxPathLeft(root->right);
      if ((root->left != nullptr) && (root->right != nullptr)) {
        if (root->left->height >= root->right->height)
          printMaxPathLeft(root->left);
        else
          printMaxPathLeft(root->right);
      }

      std::cout << root->key << ' ';
    }
  }


  // 34) Вспомогательная процедура (по правой ветви) ПЕЧАТИ узлов пути максимальной длины, проходящей через заданный узел
  void printMaxPathRight(Tree* root) {
    if ((root->left == nullptr) && (root->right == nullptr)) {
      std::cout << root->key << ' ';
    } else {
      std::cout << root->key << ' ';
      if ((root->left != nullptr) && (root->right == nullptr)) printMaxPathRight(root->left);
      if ((root->left == nullptr) && (root->right != nullptr)) printMaxPathRight(root->right);
      if ((root->left != nullptr) && (root->right != nullptr)) {
        if (root->left->height >= root->right->height)
          printMaxPathRight(root->left);
        else
          printMaxPathRight(root->right);
      }


    }
  }

  // 35) Основная процедура(по обеим ветвям) ПЕЧАТИ узлов пути максимальной длины, проходящей через заданный узел
  void printMaxPathNodes(Tree* root) {
    if (root != nullptr) {
      if (root->left != nullptr) printMaxPathLeft(root->left);
      std::cout << root->key << ' ';
      if (root->right != nullptr) printMaxPathRight(root->right);
    }
    std::cout << '\n';
  }




  /**
   *
  */

  // 13) ОСНОВНАЯ Функция определения МИНИМАЛЬНОЙ длины пути, проходящего через заданный узел
  int getMinPathLength(Tree* root) {
    int minLength = 0;

    if (root != nullptr) {
      if (root->left  != nullptr) minLength += minLengthPathFromNode(root->left)  + 1;
      if (root->right != nullptr) minLength += minLengthPathFromNode(root->right) + 1;
    }

    return minLength;
  }



  // 14) ВСПОМОГАТЕЛЬНАЯ Функция определения МИНИМАЛЬНОЙ длины пути, проходящего через заданный узел
  int minLengthPathFromNode(Tree* root) {
    int minLength = 0;
    if (root != nullptr) {
      if ((root->left != nullptr) && (root->right != nullptr)) {
        if (root->left->height < root->right->height)
        minLength += minLengthPathFromNode(root->left)  + 1;
        else
        minLength += minLengthPathFromNode(root->right) + 1;
      }

      if ((root->left != nullptr) && (root->right == nullptr)) minLength += minLengthPathFromNode(root->left)  + 1;
      if ((root->left == nullptr) && (root->right != nullptr)) minLength += minLengthPathFromNode(root->right) + 1;
    }

    return minLength;
  }



  // maximum


  // This function returns overall maximum path sum in 'res'
  // And returns max path sum going through root.

  Tree* subtreeRoot = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);
  int getMaxPathUtil(Tree* root, int &res) {
    //Base Case
    if (root == NULL)
      return 0;

    // leftChildSum and rightChildSum store maximum path sum going through left and
    // right child of root respectively
    int leftChildSum  = getMaxPathUtil(root->left,  res);
    int rightChildSum = getMaxPathUtil(root->right, res);

    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = std::max(std::max(leftChildSum, rightChildSum) + root->key, root->key);

    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = std::max(max_single, leftChildSum + rightChildSum + root->key);

    res = std::max(res, max_top); // Store the Maximum Result.
    // if ((max(l, r) + root->key) > root->key)
    if (res <= max_top) {
  	    subtreeRoot = root;
        std::cout << "path root changed to: " << subtreeRoot->key << '\n';
  	}
    return max_single;
  }


  // Returns maximum path sum in tree with given root
  Tree* getMaxSumAndRoot(Tree* root, int &res) {
    // Initialize result
    res = INT_MIN;

    // Compute and return result
    getMaxPathUtil(root, res);
    // return res;
    return subtreeRoot;
  }

  /* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct Tree* minValueNode(struct Tree* node)
{
    struct Tree* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
  /* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
  struct Tree* deleteNode(struct Tree* root, int key)
  {
      // base case
      if (root == NULL) return root;


      // If the key to be deleted is smaller than the root's key,
      // then it lies in left subtree
      if (key < root->key)
          root->left = deleteNode(root->left, key);

      // If the key to be deleted is greater than the root's key,
      // then it lies in right subtree
      else if (key > root->key)
          root->right = deleteNode(root->right, key);

      // if key is same as root's key, then This is the node
      // to be deleted
      else {
          // node with only one child or no child
          if (root->left == NULL)
          {
              struct Tree* temp = root->right;
              std::cout << "delete: " << root->key << '\n';
              free(root);
              return temp;
          }
          else if (root->right == NULL)
          {
              struct Tree* temp = root->left;
              std::cout << "delete: " << root->key << '\n';
              free(root);
              return temp;
          }

          // node with two children: Get the inorder successor (smallest
          // in the right subtree)
          struct Tree* temp = minValueNode(root->right);

          // Copy the inorder successor's content to this node
          root->key = temp->key;

          // Delete the inorder successor
          root->right = deleteNode(root->right, temp->key);
      }
      return root;
  }


  // A utility function to do inorder traversal of BST
  void inorder(struct Tree* root)
  {
      if (root != NULL)
      {
          inorder(root->left);
          printf("%d ", root->key);
          inorder(root->right);
      }
  }


  struct Tree* Delete(struct Tree *root, int key){
    if(root == NULL) return root;
    else if(key < root->key) root->left = Delete(root->left,key);
    else if(key > root->key) root->right = Delete(root->right, key);
    else {
      // Case 1: No Child
      if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL;
      // Case 2: one child
      } else if(root->left == NULL){
        struct Tree *temp = root;
        root = root->right;
        delete temp;
      } else if(root->right == NULL){
        struct Tree *temp = root;
        root = root->left;
        delete temp;
      } else{
        struct Tree *temp = FindMin(root->right);
        root->key = temp->key;
        root->right = Delete(root->right, temp->key);
      }
    }
    return root;
  }

  Tree* FindMin(Tree* root){
    while(root->left != NULL) root = root->left;
    return root;
  }

  Tree* Insert(Tree *root, char key){
  if(root == NULL){
    root = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);;
    root->key = key;
    root->left = root->right = NULL;
  } else if(key <= root->key){
    root->left = Insert(root->left, key);
  } else {
    root->right = Insert(root->right, key);
  }
  return root;
}






void removeNode(Tree* &node) {
  Tree* current;
  Tree* trailing;
  Tree* temp;

  if (node == nullptr) {
    std::cout << "Can not remove from empty tree (1)" << std::endl;
  } else if (node->left == nullptr && node->right == nullptr) {
    std::cout << "Case 1: Both Childs are Empty" << std::endl;
    temp = node;
    node = nullptr;
    delete temp;
  } else if (node->left == nullptr) {
    std::cout << "Case 2a: Left Child is Empty" << std::endl;
    temp = node;
    node = node->right;
    delete temp;
  } else if (node->right==nullptr) {
  std::cout << "Case 2b: Right Child is Empty" << std::endl;
    temp = node;
    node = node->left;
    delete temp;
  } else {
    std::cout << "Case 3: Both Childs are Non Empty" << std::endl;
    current = node->left;
    trailing = nullptr;

    while (current->right != nullptr) {
      trailing=current;
      current = current->right;
    }

    node->key = current->key;
    if(trailing == nullptr)
      node->left = current->left;
    else
      trailing->right = current->left;

    delete current;
  }
}


void removeNodeByKey(Tree* root, int key) {
  Tree* current;
  Tree* trailCurrent;
  bool found = false;

  if (root == nullptr) {
    std::cout << "No cookie for you" << std::endl;
  } else {
    current = root;
    while (current != nullptr && !found) {
      if (current->key == key) {
        found = true;
      } else {
        trailCurrent = current;
        if (key < current->key)
          current = current->left;
        else
          current = current->right;
      }
    }

    if(current == nullptr) {
      std::cout << "Node to be deleted is not in tree"<<std::endl;
    } else if(found) {
      if(current==root)
        removeNode(root);
      else
        if(key < trailCurrent->key)
          removeNode(trailCurrent->left);
        else
          removeNode(trailCurrent->right);
    }
  }
}




}
