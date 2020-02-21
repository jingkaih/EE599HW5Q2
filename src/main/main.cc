#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::vector<int> vect = {1,5,3,8,6,7,10,2,4,9,11};
    BST mytree(vect);
    mytree.inorder_re(mytree.root_);
    for(auto x :mytree.vect)
    std::cout << x <<' ';

    std::vector<int> rst = mytree.inorder_non();
    for(auto x : rst)
    std::cout << x <<' ';

    return EXIT_SUCCESS;
}