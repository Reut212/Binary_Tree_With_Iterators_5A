#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("Check add_root()"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      // Now 2 is the left child of 1
    .add_left(2, 4)      // Now 3 is the left child of 2
    .add_right(1, 3)     // Now 4 is the right child of 1
    .add_right(2, 5)     // Now 5 is the right child of 4
    .add_left(3, 6)
    .add_right(3, 7);    // Now 6 is the left child of 4

    /* My tree is:
            1
           / \
          2   3
         /|   |\
        4 5   6 7
    */
    string preorder_treverse = "";
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(preorder_treverse = "1245367");
    
    string postorder_treverse = "";
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse = "7635421");

    string inorder_treverse = "";
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse = "4251637");

    CHECK_FALSE(preorder_treverse = inorder_treverse);
    CHECK_FALSE(preorder_treverse = postorder_treverse);
    CHECK_FALSE(inorder_treverse = postorder_treverse);

    tree_of_ints.add_right(3,8);

    string preorder_treverse = "";
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(preorder_treverse = "1245368");
    
    string postorder_treverse = "";
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse = "8635421");

    string inorder_treverse = "";
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse = "4251638");
}