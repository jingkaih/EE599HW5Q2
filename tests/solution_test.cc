#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(InOrderShould, DoTraversal) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  mytree.inorder_re(mytree.root_);
  std::vector<int> actual = mytree.vect;
  std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10,11};
  EXPECT_EQ(expected, actual);
}
TEST(InOrderNonRecursivelyShould, DoTraversal) {
  std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
  BST mytree(vect);
  std::vector<int> actual = mytree.inorder_non();
  std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10,11};
  EXPECT_EQ(expected, actual);
}
