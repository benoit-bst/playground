#include <iostream>

// g++ -std=c++11 BST.cpp

class Node
{
public:
  int item;
  Node* left;
  Node* right;

  Node(int i, Node* l = nullptr, Node* r = nullptr)
  {
    item = i;
    left = l;
    right = r;
  };
  ~Node()
  {
    if (left != nullptr)
      delete left;
    if (right != nullptr)
      delete right;
  };

};

// inorder O(n)
// left root right
void inorder(Node* root)
{
  if (root != nullptr)
  {
    inorder(root->left);
    std::cout << root->item << " ";
    inorder(root->right);
  }
}

// preorder O(n)
// root left right
void preorder(Node* root)
{
  if (root != nullptr)
  {
    std::cout << root->item << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

// postorder O(n)
// left right root
void postorder(Node* root)
{
  if (root != nullptr)
  {
    postorder(root->left);
    postorder(root->right);
    std::cout << root->item << " ";
  }
}

// breadth first traversal O(n)
// You have to now the height of the tree
int height(Node* root)
{
  if (root == nullptr)
    return 0;
  else
  {
    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
      return (lheight+1);
    else
      return (rheight+1);
  }
}
void printGivenLevel(Node* root, int level)
{
  if ((root == nullptr) || (level < 0))
    return;
  if (level == 1)
    std::cout << root->item << " ";
  else{
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
void levelOrder(Node* root)
{
  for (int i = 1; i <= height(root); i++)
  {
    printGivenLevel(root, i);
  }
}

// Search BST O(h) -> O(n) for a skewed tree
Node* search(Node* root, int item)
{
  if ((root == nullptr) || (root->item == item))
    return root;
  if (root->item < item)
    return search(root->right, item);
  else
    return search(root->left, item);
}

// insert BST O(h) -> O(n) for a skewed tree
Node* insert(Node* root, int item)
{
  if (root == nullptr)
    return new Node(item);

  if (root->item < item){
    root->right = insert(root->right, item);
  }
  else{
    root->left = insert(root->left, item);
  }
}

// Min BST
Node* min(Node* root)
{
  if (root == nullptr)
    return root;

  Node* current = root;

  while (current->left != nullptr)
  {
    current = current->left;
  }
  return current;
}

// Max BST
Node* max(Node* root)
{
  if (root == nullptr)
    return root;

  Node* current = root;

  while (current->right != nullptr)
  {
    current = current->right;
  }
  return current;
}

bool ifBstTree(Node* root)
{
  static Node* prev = nullptr;

  if (root != nullptr)
  {
    if (ifBstTree(root->left) == false)
      return false;

    if (prev != nullptr && root->item <= prev->item)
      return false;

    prev = root;

    return ifBstTree(root->right);
  }
  return true;
}

//----------------------------------------
// Test
//----------------------------------------
int main()
{
  //               100
  //              /  \
  //            20   110
  //           /  \  /  \
  //         10  25 102   120
  Node* root = new Node(100, new Node(20), new Node(110));

  root->left->left = new Node(10);
  root->left->right = new Node(25);

  root->right->left = new Node(102);
  root->right->right = new Node(120);

  inorder(root);
  std::cout << "\n";
  preorder(root);
  std::cout << "\n";
  postorder(root);
  std::cout << "\n";
  std::cout << "height : " << height(root) << "\n";
  levelOrder(root);
  std::cout << "\n";
  Node* tmp = search(root, 102);
  if (tmp != nullptr)
    std::cout << "search 102 : " << tmp->item << "\n";
  else
     std::cout << "search 102 : Nope"<< "\n";
  tmp = search(root, 27);
  if (tmp != nullptr)
    std::cout << "search 27 : " << tmp->item << "\n";
  else
     std::cout << "search 27 : Nope"<< "\n";
  std::cout << "insert : " << "\n";
  insert(root, 113);
  levelOrder(root);
  std::cout << "\n";
  std::cout << "Min : " << min(root)->item  << "\n";
  std::cout << "Max : " << max(root)->item  << "\n";

  Node* root2 = new Node(100, new Node(35), new Node(110));

  root2->left->left = new Node(10);
  root2->left->right = new Node(25);

  root2->right->left = new Node(102);
  root2->right->right = new Node(120);


  std::cout << "Is BST : " << ifBstTree(root) << "\n";
  std::cout << "Is BST : " << ifBstTree(root2) << "\n";

  return 0;
}
