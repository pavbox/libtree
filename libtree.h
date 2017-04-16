
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
    int key; // wat
    int weight; // Смещение влево-вправо относительно корневого элемента (по горизонтали)
    int depth; // расстояние в дугах от корня до узла
    int height; // расстояние в дугах от узла до наиболее удаленного потомка
    Tree* left; // left child
    Tree* right; // right child

    Tree() {}

    // struct constructor
    Tree(int v, Tree* l, Tree* r) {
      value = v;
      left = l;
      right = r;
    }

    Tree(int v, int k, int w, int d, int h, Tree* l, Tree* r) {
      value = v;
      key = k;
      weight = w;
      depth = d;
      height = h;
      left = l;
      right = r;
    }
  };




  void showItem(Tree* tree);

  void preOrderLeft(Tree* tree);   // Root -> left  -> right
  void preOrderRight(Tree* tree);  // Root -> right -> left
  void postOrderLeft(Tree* tree);  // left  -> right -> Root
  void postOrderRight(Tree* tree); // right -> left  -> Root
  void inOrderLeft(Tree* tree);    // left  -> Root -> right
  void inOrderRight(Tree* tree);   // right -> Root -> left
  void printTree(Tree* root, int offset);

  // FrontOrderLeftPosition
  // CopyFullTree
  // PrintLeftTree
  // .PrintLevel

  // methods
  int getNodeHeight(Tree* tree);
  int setNodeHeight(Tree* tree);

  Tree* insertKeyToSubtree(Tree* root, int key);
  void updateTreeNodes(Tree* node, int depth, int weight);

  Tree* findMinNodeByKey(Tree* node); // ???
  Tree* findMaxNodeByKey(Tree* node); // ???

  Tree* removeMinNode(Tree* node); // remove list
  Tree* removeMaxNode(Tree* node); // remove list

  Tree* removeNodeByKeyRight(Tree* node, int key);
  Tree* removeNodeByKeyLeft(Tree* node, int key);

  int getChildsAmount(Tree* node);

  // building Tree by array.
  Tree* buildTree(Tree* tree, int value);
  // building balanced tree with program filling.
  void buildBalancedTree(Tree* tree, int height);

  int getMaxPathAvg(Tree* root);
  int getMaxPathFromNode(Tree* root);

  Tree* compareNodesMaxPath(Tree* root, int maxLength, int rootListSum, Tree* resultRoot);
  Tree* findMaxPathRoot(Tree* root);

  void printMaxPathLeft(Tree* root);
  void printMaxPathRight(Tree* root);
  void printMaxPathNodes(Tree* root);

  //minway
  int getMinPathLength(Tree* root);
  int minLengthPathFromNode(Tree* root);

  //maxway
  int getMaxPathUtil(Tree* root, int &res);
  Tree* getMaxSumAndRoot(Tree* root, int &res);

  struct Tree* deleteNode(struct Tree* root, int key);
  void inorder(struct Tree* root);

  struct Tree* Delete(struct Tree *root, int key);
  Tree* FindMin(Tree* root);
  Tree* Insert(Tree *root, char key);

  void removeNode(Tree* &p);
  void removeNodeByKey(Tree* root, int item);
  Tree* copyTree(Tree* node, Tree* newNode);

  int getNodeAmount(Tree* node);
  Tree* getCenterOfTree(Tree* node);
  void removeLists(Tree* node);
  int compareNodes(Tree* source, Tree* newest);
  // Tree* subtreeRoot = new Tree(0, 0, 0, 0, 0, nullptr, nullptr);
}
