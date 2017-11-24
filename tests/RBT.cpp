#include <catch.hpp>

#include "RBT.hpp"

/*           10            */
TEST_CASE("insert1", "[root]") 
{
   Tree<int> tree;
   tree.insert(10);
   Node<int> * node = tree.search(10);
   REQUIRE(tree.left_(node) == nullptr);
   REQUIRE(tree.right_(node) == nullptr);
   REQUIRE(tree.parent_(node) == nullptr);
   REQUIRE(tree.value_(node) == 10);
   REQUIRE(tree.color_(node) == BLACK);
   REQUIRE(tree.count_() == 1);
}

/*/*        10             9
         /             /   \       
        9      ->     8     10        
      /
     8                           */
TEST_CASE("insert2", "[rotate_right]") 
{
   AVL_tree<int> tree;
   tree.insert(10);
   tree.insert(9);
   tree.insert(8);
   Node<int> * node = tree.search(9);
   REQUIRE(tree.left_(node) == tree.search(8));
   REQUIRE(tree.right_(node) == tree.search(10));
   REQUIRE(tree.parent_(node) == nullptr);
   REQUIRE(tree.key_(node) == 9);
   REQUIRE(tree.height_(node) == 2);
   REQUIRE(tree.parent_(tree.search(8)) == node);
   REQUIRE(tree.parent_(tree.search(10)) == node);
   REQUIRE(tree.height_(tree.search(8)) == 1);
   REQUIRE(tree.height_(tree.search(10)) == 1);
   REQUIRE(tree.count_() == 3);
}

/*  8                        9
      \                    /   \       
        9           ->    8     10        
          \
           10                     */
TEST_CASE("insert3", "[rotate_left]") 
{
   AVL_tree<int> tree;
   tree.insert(8);
   tree.insert(9);
   tree.insert(10);
   Node<int> * node = tree.search(9);
   REQUIRE(tree.left_(node) == tree.search(8));
   REQUIRE(tree.right_(node) == tree.search(10));
   REQUIRE(tree.parent_(node) == nullptr);
   REQUIRE(tree.key_(node) == 9);
   REQUIRE(tree.height_(node) == 2);
   REQUIRE(tree.parent_(tree.search(8)) == node);
   REQUIRE(tree.parent_(tree.search(10)) == node);
   REQUIRE(tree.height_(tree.search(8)) == 1);
   REQUIRE(tree.height_(tree.search(10)) == 1);
   REQUIRE(tree.count_() == 3);
}

/*        9                9
        /   \     ->     /
       8     10         8        */
TEST_CASE("delete1", "[leaf]") 
{
   AVL_tree<int> tree;
   tree.insert(8);
   tree.insert(9);
   tree.insert(10);
   REQUIRE(tree.count_() == 3);
   tree.remove(10);
   REQUIRE(tree.height_(tree.search(8)) == 1);
   REQUIRE(tree.height_(tree.search(9)) == 2);
   REQUIRE(tree.count_() == 2);
}

/*        9                9
        /   \     ->     /   \
       8     10         7     10    
      /                          
     7                            */
TEST_CASE("delete2", "[node->left]") 
{
   AVL_tree<int> tree;
   tree.insert(8);
   tree.insert(9);
   tree.insert(10);
   tree.insert(7);
   REQUIRE(tree.height_(tree.search(7)) == 1);
   REQUIRE(tree.height_(tree.search(10)) == 1);
   REQUIRE(tree.height_(tree.search(8)) == 2);
   REQUIRE(tree.height_(tree.search(9)) == 3);
   REQUIRE(tree.count_() == 4);
   tree.remove(8);
   REQUIRE(tree.height_(tree.search(7)) == 1);
   REQUIRE(tree.height_(tree.search(10)) == 1);
   REQUIRE(tree.height_(tree.search(9)) == 2);
   REQUIRE(tree.count_() == 3);
}

/*        9                10
        /   \     ->     /
       8     10         8        */
TEST_CASE("delete3", "[node->right]") 
{
   AVL_tree<int> tree;
   tree.insert(8);
   tree.insert(9);
   tree.insert(10);
   REQUIRE(tree.count_() == 3);
   tree.remove(9);
   REQUIRE(tree.height_(tree.search(8)) == 1);
   REQUIRE(tree.height_(tree.search(10)) == 2);
   REQUIRE(tree.count_() == 2);
}
*/
