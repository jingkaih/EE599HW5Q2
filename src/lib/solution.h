#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <queue>
#include <stack>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
  public:
    BST();

    // Inserts elements of initial_values
    // one by one into the Tree
    BST(std::vector<int> initial_values);
    //~BST();

    void push(TreeNode * &node_ptr,int key); // **GT** Inserts a key inside Tree
    bool find(TreeNode * node_ptr,int key); // **GT** Returns true of key is in the tree
    bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.

  //private:
    TreeNode *root_ = nullptr;
    int find_height();//find the max depth
    void inorder_re(TreeNode *);
    std::vector<int> inorder_non();
    std::vector<int> vect;
};

#endif