# Алгоритмы и структуры данных: Библиотека для работы с деревьями libtree.

Library contains basic algorithms and structures for work with Trees.
Compiled with g++ as shared library (for mac/linux).

Узел дерева представляет собой структуру:

```cpp

struct Tree {
  int value;
  int key;
  int weight;
  int depth;
  int height;
  Tree* left;
  Tree* right;

  // default constructor
  Tree() {}

  // struct constructor
  Tree(int v, Tree* l, Tree* r) {
    value = v;
    left = l;
    right = r;
  }

  // fully constructor
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

```


Доступные API-функции:

```cpp

// Вывести значение (ключ) узла node
void showItem(Tree* node);

// Обход дерева различными методами
void preOrderLeft(Tree* node);   // Root -> left  -> right
void preOrderRight(Tree* node);  // Root -> right -> left
void postOrderLeft(Tree* node);  // left  -> right -> Root
void postOrderRight(Tree* node); // right -> left  -> Root
void inOrderLeft(Tree* node);    // left  -> Root -> right
void inOrderRight(Tree* node);   // right -> Root -> left

// Вывод дерева на экран с помощью символьной печати
void printTree(Tree* node, int offset);

// Создать сбалансированное дерево заданной высоты
// Значения узлов для дерева генерируются программно.
void buildBalancedTree(Tree* node, int height);

// Получить высоту узла
int getNodeHeight(Tree* node);

// Вычислить высоту узла и присвоить этому узлу параметр высоты
int setNodeHeight(Tree* node);

// Вставить новый узел в дерево (или поддерево)
Tree* insertKeyToSubtree(Tree* node, int key);

// Обновить все параметры узлов (высота, глубина и ширина узла)
void updateTreeNodes(Tree* node, int depth, int weight);

// найти что-то
Tree* findMinNodeByKey(Tree* node); // ???
Tree* findMaxNodeByKey(Tree* node); // ???

// Удалить минимальный лист в дереве
Tree* removeMinNode(Tree* node); // remove list
// Удалить максимальный лист в дереве
Tree* removeMaxNode(Tree* node); // remove list

// Удалить узел по ключу Правым и Левым удалением
Tree* removeNodeByKeyRight(Tree* node, int key);
Tree* removeNodeByKeyLeft(Tree* node, int key);

// Получить количество потомков для заданного узла
int getChildsAmount(Tree* node);

// Стандартная функция генерации дерева
Tree* buildTree(Tree* node, int value);

// Получить сумму ключей всех листов для максимального пути дерева
int getMaxPathListsSum(Tree* node);
// Сервисная функция для подсчета суммы всех листов максимального пути
int getMaxPathListsUtil(Tree* node);
// Получить максимальный путь, проходящий через данный узел
int getMaxPathFromNode(Tree* node);

// Сравнить все узлы дерева и вернуть максимальный
Tree* compareNodesMaxPath(Tree* node, int maxLength, int rootListSum, Tree* resultRoot);
// Найти корневой узел максимального пути дерева
Tree* findMaxPathRoot(Tree* node);

// Вывести все узлы максимального пути для этого дерева
void printMaxPathLeftUtil(Tree* node); // test: find duplicates
void printMaxPathRightUtil(Tree* root);
void printMaxPathNodes(Tree* root);

// Найти минимальный путь дерева
int getMinPathLength(Tree* root);
int getMinPathLengthUtil(Tree* node);

// Найти максимальный путь дерева
// TODO: ищет максимальный путь дерева, но не поддерева, т.е. путь обязательно проходит через node
int getMaxPathUtil(Tree* node, int &res);
Tree* getMaxSumAndRoot(Tree* root, int &res);

// Удаление узла по ключу
void removeNode(Tree* &p);
void removeNodeByKey(Tree* node, int item);

// Скопировать дерево
Tree* copyTree(Tree* node, Tree* newNode);

// Получить количество узлов дерева
int getNodeAmount(Tree* root);

// Найти центральную вершину дерева
Tree* getCenterOfTree(Tree* node);

// Удалить все листы дерева
void removeLists(Tree* node);

// Сравнить два узла дерева
int compareNodes(Tree* source, Tree* newest);

```

# Тестирование

Полного тестирования еще не проводилось.

Можно посмотреть задачу в файле srm.cpp.
Условие задачи в srm.cpp:

Среди максимальных путей в дереве выбрать тот, у которого сумма ключей всех его вершин максимальна, затем удалить центральную вершину и корень этого пути (правым удалением). Выполнить прямой (левый) обход полученного дерева.

## Фичер-лист
[] Поиск максимального пути: без включения главного root.
[] Тестирование функций

