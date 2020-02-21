#include "solution.h"

BST::BST(std::vector<int> initial_values)
{
  for(auto x : initial_values)
  push(root_, x);
}

void BST::push(TreeNode* &node_ptr,int key)
{
  if(node_ptr == nullptr)
  node_ptr = new TreeNode(key);
  else if (key > node_ptr->val)
  return push(node_ptr->right, key);
  else if (key < node_ptr->val)
  return push(node_ptr->left, key);
}

bool BST::find(TreeNode* node_ptr, int key)
{
  if(node_ptr == nullptr)
  return false;
  else
  {
    if(node_ptr->val == key)
    return true;
    else if(node_ptr->val > key)
    return find(node_ptr->left, key);
    else if(node_ptr->val < key)
    return find(node_ptr->right, key);
  }
}

bool BST::erase(int key)
{
  TreeNode * node_ptr = root_;
  TreeNode * parent_node_ptr = root_;
  if(find(root_, key))
  {

    while (node_ptr->val != key)
    {

      if(node_ptr->val > key)
      {
        parent_node_ptr = node_ptr;
        node_ptr = node_ptr->left;
      }
      else if(node_ptr->val < key)
      {
        parent_node_ptr = node_ptr;
        node_ptr = node_ptr->right;
      }

    }

    if(node_ptr->left == nullptr && node_ptr->right == nullptr)//the deleted node has no child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = nullptr;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = nullptr;
    }
    else if(node_ptr->left == nullptr && node_ptr->right != nullptr)//the deleted node only has a right child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = node_ptr->right;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = node_ptr->right;
    }
    else if(node_ptr->left != nullptr && node_ptr->right == nullptr)//the deleted node only has a left child
    {
      if(parent_node_ptr->left->val == key)
      parent_node_ptr->left = node_ptr->left;
      else if(parent_node_ptr->right->val == key)
      parent_node_ptr->right = node_ptr->left;
    }
    else//the deleted node has two children. Let's find the minimum value of its right subtree, the node wiht minimum value must have no or only one child. This child must be a right child.
    {
      TreeNode * min_val_ptr = node_ptr->right;
      TreeNode * min_parent_ptr = node_ptr->right;
      while(min_val_ptr->left != nullptr)
      {
        min_parent_ptr = min_val_ptr;
        min_val_ptr = min_val_ptr->left;
      }
      
      node_ptr->val = min_val_ptr->val;

      min_parent_ptr->left = min_val_ptr->right;//no matter min_val_ptr->right is nullptr or not
    }
    return true;
  }
  else
  {
    return false;
  }
  

}

int BST::find_height()
{
  std::queue<TreeNode *> node_queue;
  node_queue.push(root_);
  TreeNode *node;
  int height = 0;
  while(!node_queue.empty())
  {
    node = node_queue.front();
    int level_size = node_queue.size();
    for(int i = 0; i < level_size; i++)
    {
      if(node->left!=nullptr)
      node_queue.push(node->left);
      if(node->right!=nullptr)
      node_queue.push(node->right);
      node_queue.pop();
      node = node_queue.front();
    }
    height++;
  }
  return height;
}

void BST::inorder_re(TreeNode *node)
{
  if(node != nullptr)
  {
    inorder_re(node->left);
    vect.push_back(node->val);
    inorder_re(node->right);
  }
}

std::vector<int> BST::inorder_non()
{
  std::vector<int> result;
  std::stack<TreeNode *> node_stack;
  TreeNode *node = root_;

  while(!node_stack.empty()||node!=nullptr)
  {
    while(node!=nullptr)
    {
      node_stack.push(node);
      node = node->left;
    }
      node = node_stack.top();

      node_stack.pop();
      result.push_back(node->val);

      
      // node = node_stack.top();
      // result.push_back(node->val);

      node = node->right;//check if there is a right subtree
    }
    return result;
}