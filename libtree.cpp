
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
   * Shows node key
   */
  void showItem(Tree* node) {
    std::cout << node->value << " ";
  }


  /**
   *  Print tree: pre-order left method
   */
  void preOrderLeft(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      showItem(node);
      preOrderLeft(node->left);
      preOrderLeft(node->right);
    }
  }


  /**
   *  Print tree: pre-order right method
   */
  void preOrderRight(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      showItem(node);
      preOrderRight(node->right);
      preOrderRight(node->left);
    }
  }


  /**
   *  Print tree: post-order left method
   */
  void postOrderLeft(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      postOrderLeft(node->left);
      postOrderLeft(node->right);
      showItem(node);
    }
  }


  /**
   *  Print tree: post-order right method
   */
  void postOrderRight(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      postOrderRight(node->right);
      postOrderRight(node->left);
      showItem(node);
    }
  }


  /**
   *  Print tree: in-order left method
   */
  void inOrderLeft(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      inOrderLeft(node->left);
      showItem(node);
      inOrderLeft(node->right);
    }
  }


  /**
   *  Print tree: in-order right method
   */
  void inOrderRight(Tree* node) {
    if (node != nullptr) {
      std::cout << "Nodes: ";
      inOrderRight(node->right);
      showItem(node);
      inOrderRight(node->left);
    }
  }


  /**
   *  Print tree: Graphical Method.
   *  Created by N. Virt.
   */
  void printTree(Tree* node, int offset) {
    int i;
    if (node != nullptr) {
      printTree(node->left, offset + 1);

      for (i = 1; i < offset; i++) std::cout << "--->";
      std::cout << node->key << '\n';

      printTree(node->right, offset + 1);
    }
  }


  /**
   *  Build fully balanced tree with optional height.
   *  Nodes equals node height.
   */
  void buildBalancedTree(Tree* node, int height) {
    Tree* newLeftNode;
    Tree* newRightNode;

    if (height > 0) {
      newLeftNode  = new Tree(height, height, 0, 0, 0, nullptr, nullptr);
      newRightNode = new Tree(height, height, 0, 0, 0, nullptr, nullptr);

      node->left  = newLeftNode;
      node->right = newRightNode;

      buildBalancedTree(node->left,  height - 1);
      buildBalancedTree(node->right, height - 1);
    }
  }


  /**
   *  Get height of Node
   */
  int getNodeHeight(Tree* node) {
    int result = 0;
    if (node != nullptr) {
      result = node->height;
    }
    return result;
  }


  /**
   *  Find height of Node and set to object.
   */
  int setNodeHeight(Tree* node) {
    int left = 0, right = 0;

    if (node != nullptr) {
      left  = setNodeHeight(node->left);
      right = setNodeHeight(node->right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    } else {
      return 0;
    }
  }


  /**
   *  Insert new Node to tree (or subtree).
   *  New node will be is list.
   */
  Tree* insertKeyToSubtree(Tree* node, int key) {
    if (node == nullptr) {
      node = new Tree(key, key, 0, 0, 0, nullptr, nullptr);
    } else {
      if (key < node->key)
        node->left = insertKeyToSubtree(node->left, key);
      else
        node->right = insertKeyToSubtree(node->right, key);
    }

    updateTreeNodes(node, 0, 0);
    return node;
  }


  /**
   *  Updates all params of a nodes of the tree.
   */
  void updateTreeNodes(Tree* node, int depth, int weight) {
    if (node != nullptr) {
      node->depth = depth;
      node->weight = weight;
      node->height = setNodeHeight(node);

      if (node->left  != nullptr) updateTreeNodes(node->left,  depth + 1, weight - 1);
      if (node->right != nullptr) updateTreeNodes(node->right, depth + 1, weight + 1);
    }
  }


  /**
   *  Finds node with minimum key in the tree.
   *  It's works only for BST (Binary Search Tree)
   */
  Tree* findMinNodeByKey(Tree* node) {
    if (node->left != nullptr) {
      return findMinNodeByKey(node->left);
    } else {
      return node;
    }
  }


  /**
   *  Finds node with maximum key in the tree.
   *  It's works only for BST (Binary Search Tree)
   */
  Tree* findMaxNodeByKey(Tree* node) {
    if (node->right != nullptr) {
      return findMaxNodeByKey(node->right);
    } else {
      return node;
    }
  }


  /**
   *  Finds and removes node with minimal key.
   */
  Tree* removeMinNode(Tree* node) {
    if (node->left == nullptr) {
      return node->right;
    } else {
      node->left = removeMinNode(node->left);
      return node;
    }
  }


  /**
   *  Finds and removes node with maximal key.
   */
  Tree* removeMaxNode(Tree* node) {
    if (node->right == nullptr) {
      return node->left;
    } else {
      node->right = removeMinNode(node->right);
      return node;
    }
  }


  /**
   *  Finds and removes node with maximal key.
   */
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


  /**
   *  Gets children count of node.
   */
  int getChildsAmount(Tree* node) {
    if (node != nullptr) {
      return (1 + getChildsAmount(node->left) + getChildsAmount(node->right));
    } else {
      return 0;
    }
  }





  /**
   *  Default function for building the tree.
   *  Creates Binary Tree.
   */
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


  /**
   *  Utility function for calculate sum of lists for max path of this node.
   */
  int getMaxPathUtil(Tree* node) {
    if ((node->left == nullptr) && (node->right == nullptr)) return node->key;
    if ((node->left != nullptr) && (node->right == nullptr)) return getMaxPathUtil(node->left);
    if ((node->left == nullptr) && (node->right != nullptr)) return getMaxPathUtil(node->right);
    if ((node->left != nullptr) && (node->right != nullptr)) {
      // check length of a subtrees
      if ((node->left->height) >= (node->right->height))
        return getMaxPathUtil(node->left);
      else
        return getMaxPathUtil(node->right);
    }
  }


  /**
   *  Calculates sum of lists for max path of this node.
   *  Calculate only max path lists of this node.
   */
  int getMaxPathAvg(Tree* node) {
    int maxLength = 0;
    if (node != nullptr) {
      if (node->left != nullptr)
        maxLength += getMaxPath(node->left);
      else
        maxLength += node->key;

      if (node->right != nullptr)
        maxLength += getMaxPath(node->right);
      else
        maxLength += node->key;
    }
    return maxLength;
  }


  /**
   *  Gets max path that passing through this node.
   */
  int getMaxPathFromNode(Tree* node) {
    int maxLength = 0;

    if (node != nullptr) {
      if (node->left  != nullptr) maxLength += node->left->height  + 1;
      if (node->right != nullptr) maxLength += node->right->height + 1;
    }
    return maxLength;
  }


  /**
   *  Main function for finding max path Root.
   *  And selects between two max path that,
   *  which has max sum of key of nodes
   *  TODO: Test and do somethind (remove or describe).
   */
  Tree* findMaxPathRoot(Tree* node) {
    int maxLength = 0;
    int rootListSum = 10000;
    Tree* resultRoot = nullptr;

    resultRoot = compareNodesMaxPath(node, maxLength, rootListSum, resultRoot);
    return resultRoot;
  }


  /**
   *  Compares all Max path nodes
   *  TODO: Test and do somethind (remove or describe).
   */
  Tree* compareNodesMaxPath(Tree* node, int maxLength, int rootListSum, Tree* resultRoot) {
    int tmpLength = 0;
    if (node != nullptr) {
      tmpLength = getMaxPathFromNode(node);

      if ((tmpLength > maxLength) || ((tmpLength == maxLength) && (getMaxPathAvg(node) < rootListSum))) {
        resultRoot = node;
        maxLength = tmpLength;
        rootListSum = getMaxPathAvg(node);
      }

      compareNodesMaxPath(node->left,  maxLength, rootListSum, resultRoot);
      compareNodesMaxPath(node->right, maxLength, rootListSum, resultRoot);

      return resultRoot;
    }
  }



  /**
   *  Utility function for printing all nodes of max path
   *  of left subtree for this root.
   */
  void printMaxPathLeft(Tree* node) {
    if ((node->left == nullptr) && (node->right == nullptr)) {
      std::cout << node->key << ' ';
    } else {
      if ((node->left != nullptr) && (node->right == nullptr)) printMaxPathLeft(node->left);
      if ((node->left == nullptr) && (node->right != nullptr)) printMaxPathLeft(node->right);
      if ((node->left != nullptr) && (node->right != nullptr)) {
        if (node->left->height >= node->right->height)
          printMaxPathLeft(node->left);
        else
          printMaxPathLeft(node->right);
      }

      std::cout << node->key << ' ';
    }
  }


  /**
   *  Utility function for printing all nodes of max path
   *  of right subtree for this root.
   */
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


  /**
   *  Prints all nodes of max path for this root.
   *  Print method: in-order left.
   */
  void printMaxPathNodes(Tree* root) {
    if (root != nullptr) {
      if (root->left != nullptr) printMaxPathLeft(root->left);
      std::cout << root->key << ' ';
      if (root->right != nullptr) printMaxPathRight(root->right);
    }
    std::cout << '\n';
  }



  /**
   *  Gets minimal length value for this root of the tree.
   */
  int getMinPathLength(Tree* root) {
    int minLength = 0;

    if (root != nullptr) {
      if (root->left  != nullptr) minLength += getMinPathLengthUtil(root->left)  + 1;
      if (root->right != nullptr) minLength += getMinPathLengthUtil(root->right) + 1;
    }

    return minLength;
  }


  /**
   *  Utility function for calculate minimum length
   *  for this node.
   */
  int getMinPathLengthUtil(Tree* root) {
    int minLength = 0;
    if (root != nullptr) {
      if ((root->left != nullptr) && (root->right != nullptr)) {
        if (root->left->height < root->right->height)
        minLength += getMinPathLengthUtil(root->left)  + 1;
        else
        minLength += getMinPathLengthUtil(root->right) + 1;
      }

      if ((root->left != nullptr) && (root->right == nullptr)) minLength += getMinPathLengthUtil(root->left)  + 1;
      if ((root->left == nullptr) && (root->right != nullptr)) minLength += getMinPathLengthUtil(root->right) + 1;
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


  struct Tree* Delete(struct Tree *root, int key){
    if(root == NULL) return root;
    else if(key < root->key) root->left  = Delete(root->left,key);
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


/**
 1. find start list
 2. find maximum second list
 3. compare results for all lists
 4. save node that have radius
*/

Tree* copyTree(Tree* node, Tree* newNode) {
  if (node != nullptr) {
    newNode = new Tree(node->value, node->key, node->weight, node->depth, node->height, node->left, node->right);
    newNode->left  = copyTree(node->left,  newNode->left);
    newNode->right = copyTree(node->right, newNode->right);
    return newNode;
  } else {
    return nullptr;
  }
}

Tree* getCenterOfTree(Tree* node) {
  while (getNodeAmount(node) > 2) {
    removeLists(node);
  }
  if ((node->left != nullptr) && (node->right == nullptr)) return node->left;
  if ((node->left == nullptr) && (node->right != nullptr)) return node->right;

  // else
  return node;
}

int isList(Tree* node) {
  // if left child is list
  if (node->left == nullptr && node->right == nullptr)
    return 1;
  else
    return 0;

}

void removeLists(Tree* node) {
  // std::cout << "is list left: " << isList(node->left) << '\n';
  if (node->left != nullptr && !isList(node->left))
    removeLists(node->left);
  else
    node->left = nullptr;

  if (node->right != nullptr && !isList(node->right))
    removeLists(node->right);
  else
    node->right = nullptr;

}

int getNodeAmount(Tree* node) {
  int nodeAmount = 0;
  if (node != nullptr) {
    nodeAmount += getNodeAmount(node->right) + getNodeAmount(node->left) + 1;
  }
  // std::cout << "amount: " << nodeAmount << '\n';
  return nodeAmount;
}


int compareNodes(Tree* source, Tree* newest) {
  if (
      source->value == newest->value
      && source->key == newest->key
      && source->weight == newest->weight
      && source->depth == newest->depth
      && source->height == newest->height) {
        return 1;
      } else {
        return 0;
      }
}




}
