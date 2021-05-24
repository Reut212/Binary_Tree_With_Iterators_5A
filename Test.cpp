#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("Check traverse"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      // Now 2 is the left child of 1
    .add_left(2, 4)      // Now 4 is the left child of 2
    .add_right(1, 3)     // Now 3 is the right child of 1
    .add_right(2, 5)     // Now 5 is the right child of 2
    .add_left(3, 6)      // Now 6 is the right child of 3
    .add_right(3, 7);    // Now 7 is the left child of 3

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
    CHECK(preorder_treverse == "1245367");
    
    string postorder_treverse = "";
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse == "7635421");

    string inorder_treverse = "";
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse == "4251637");

    CHECK_FALSE(preorder_treverse == inorder_treverse);
    CHECK_FALSE(preorder_treverse == postorder_treverse);
    CHECK_FALSE(inorder_treverse == postorder_treverse);
}
TEST_CASE("Update child"){
    //* Same tree
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      
    .add_left(2, 4)      
    .add_right(1, 3)     
    .add_right(2, 5)     
    .add_left(3, 6)      
    .add_right(3, 7);    

    tree_of_ints.add_right(3,8); //updating the right child of node 3

    string preorder_treverse = "";
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(preorder_treverse == "1245368");
    
    string postorder_treverse = "";
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse == "8635421");

    string inorder_treverse = "";
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse == "4251638");
}

TEST_CASE("Update root"){
    //* Same tree
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      
    .add_left(2, 4)      
    .add_right(1, 3)     
    .add_right(2, 5)     
    .add_left(3, 6)      
    .add_right(3, 7);    

    tree_of_ints.add_root(8); //updatin the root

    string preorder_treverse = "";
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(preorder_treverse == "8245367");
    
    string postorder_treverse = "";
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse == "7635428");

    string inorder_treverse = "";
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse == "4258637");

    CHECK_FALSE(preorder_treverse == inorder_treverse);
    CHECK_FALSE(preorder_treverse == postorder_treverse);
    CHECK_FALSE(inorder_treverse == postorder_treverse);
}

TEST_CASE("Tree of chars"){
    BinaryTree<char> tree_of_chars;
    tree_of_chars.add_root(1)
    .add_left('a', 'b')      // b is the left child of a
    .add_left('b', 'd')      // d is the left child of b
    .add_right('a', 'c')     // c is the right child of a
    .add_right('b', 'e')     // e is the right child of b
    .add_left('c', 'f')      // f is the right child of c
    .add_right('c', 'g');    // g is the left child of c

    /* My tree is:
            a
           / \
          b   c
         /|   |\
        d e   f g
    */

   string preorder_treverse = "";
    for (auto it=tree_of_chars.begin_preorder(); it!=tree_of_chars.end_preorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(preorder_treverse == "abdecfg");
    
    string postorder_treverse = "";
    for (auto it=tree_of_chars.begin_postorder(); it!=tree_of_chars.end_postorder(); ++it) {
        preorder_treverse = to_string(*it);
    }
    CHECK(postorder_treverse == "gfcedba");

    string inorder_treverse = "";
    for (auto it=tree_of_chars.begin_inorder(); it!=tree_of_chars.end_inorder(); ++it) {
        inorder_treverse = to_string(*it);
    }
    CHECK(inorder_treverse == "dbeafcg");

    CHECK_FALSE(preorder_treverse == inorder_treverse);
    CHECK_FALSE(preorder_treverse == postorder_treverse);
    CHECK_FALSE(inorder_treverse == postorder_treverse);
}

TEST_CASE("false information"){
    /* Same tree as the one in the first test case */
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      
    .add_left(2, 4)      
    .add_right(1, 3)     
    .add_right(2, 5)     
    .add_left(3, 6)      
    .add_right(3, 7);

    /* check updates between nodes that exists in the tree */
    CHECK_THROWS(tree_of_ints.add_left(2,1));
    CHECK_THROWS(tree_of_ints.add_left(4,2));
    CHECK_THROWS(tree_of_ints.add_left(6,3));
    CHECK_THROWS(tree_of_ints.add_right(5,2));
    CHECK_THROWS(tree_of_ints.add_right(3,1));
    CHECK_THROWS(tree_of_ints.add_right(7,3));

    /* check updates between nodes that not exists in the tree */
    CHECK_THROWS(tree_of_ints.add_left(4,10));
    CHECK_THROWS(tree_of_ints.add_left(5,10));
    CHECK_THROWS(tree_of_ints.add_left(6,10));
    CHECK_THROWS(tree_of_ints.add_left(7,10));
    CHECK_THROWS(tree_of_ints.add_right(4,10));
    CHECK_THROWS(tree_of_ints.add_right(5,10));
    CHECK_THROWS(tree_of_ints.add_right(6,10));
    CHECK_THROWS(tree_of_ints.add_right(7,10));
}