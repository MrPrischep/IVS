//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Dmitrii Kozhevnikov <xkozhe00@stud.fit.vutbr.cz>
// $Date:       $2020-02-15
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Dmitrii Kozhevnikov
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

class EmptyTree : public ::testing::Test {
    protected:

    BinaryTree tree1;
};

TEST_F(EmptyTree, InsertNode) {

    //  insert first node with quantity 1
    std::pair<bool, BinaryTree::Node_t *> firstPair = tree1.InsertNode(1);
    BinaryTree::Node_t *node1 = firstPair.second;
    
    ASSERT_FALSE(node1 == NULL);    //  node1 is not empty
    EXPECT_TRUE(firstPair.first);    //  bool-pointer in node1 is true
    EXPECT_TRUE(node1->pParent == NULL);    //  node1 haven't got parent

    //  insert second node with quantity 2
    std::pair<bool, BinaryTree::Node_t *> secondPair = tree1.InsertNode(2);
    BinaryTree::Node_t *node2 = secondPair.second;
    
    ASSERT_FALSE(node2 == NULL);    //  node2 is not empty
    EXPECT_TRUE(secondPair.first);    //  bool-pointer in node2 is true
    ASSERT_TRUE(node2->pParent != NULL);    //  node2 haven't got parent
	EXPECT_EQ(node2->pParent->key, 1);  //  parent of node2 is 1

    //  insert third node with quantity 3
    std::pair<bool, BinaryTree::Node_t *> thirdPair = tree1.InsertNode(3);
    BinaryTree::Node_t *node3 = thirdPair.second;
    
    ASSERT_FALSE(node3 == NULL);    //  node3 is not empty
    EXPECT_TRUE(secondPair.first);    //  bool-pointer in node3 is true
    ASSERT_TRUE(node3->pParent != NULL);    //  node3 have got parent
	EXPECT_EQ(node3->pParent->key, 2);  //  parent of node3 is 2

    //  vlozeni existujciho uzlu
	std::pair<bool, BinaryTree::Node_t *> existPair = tree1.InsertNode(1);
	BinaryTree::Node_t *existNode = existPair.second;
	ASSERT_FALSE(existNode == NULL);    //  existNode is not empty
	EXPECT_FALSE(existPair.first);  //  bool-pointer in existNode is false

    //  insert negative node with quantity -1
    std::pair<bool, BinaryTree::Node_t *> minusPair = tree1.InsertNode(-1);
    BinaryTree::Node_t *minusNode = minusPair.second;
    ASSERT_FALSE(minusNode == NULL);    //  minusNode is not empty
    EXPECT_TRUE(minusPair.first);    //  bool-pointer in minusNode is true
    ASSERT_TRUE(minusNode->pParent != NULL);    //  minusNode have got parent
	EXPECT_EQ(minusNode->pParent->key, 1);  //  parent of minusNode is 1
}

TEST_F(EmptyTree, FindNode) {
    
    ASSERT_NO_THROW(tree1.InsertNode(1));
    ASSERT_NO_THROW(tree1.InsertNode(2));

    BinaryTree::Node_t *firstFoundNode = tree1.FindNode(1);
    EXPECT_NE(nullptr, firstFoundNode); //  finding node with quantity 1
    EXPECT_EQ(firstFoundNode->key, 1);

    BinaryTree::Node_t *firstNotFoundNode = tree1.FindNode(322);
    EXPECT_EQ(nullptr, firstNotFoundNode); //  finding node with quantity 322
}

TEST_F(EmptyTree, DeleteNode) {

    ASSERT_NO_THROW(tree1.InsertNode(1));
    ASSERT_NO_THROW(tree1.InsertNode(2));

    EXPECT_TRUE(tree1.DeleteNode(1));   //  we can delete node with quantity 1
    EXPECT_TRUE(tree1.DeleteNode(2));   //  we can delete node with quantity 2
    EXPECT_FALSE(tree1.DeleteNode(1));  //  we can not delete node with quantity 1
    EXPECT_FALSE(tree1.DeleteNode(2));  //  we can not delete node with quantity 2
    EXPECT_FALSE(tree1.DeleteNode(322));  //  we can not delete node with quantity 322
}

class NonEmptyTree : public ::testing::Test{
    protected:
        void SetUp(){
            tree2.InsertNode(10);
            tree2.InsertNode(11);
            tree2.InsertNode(12);
        }
        BinaryTree tree2;
};

TEST_F(NonEmptyTree, InsertNode) {

    //  insert first node with quantity 4
    std::pair<bool, BinaryTree::Node_t *> fourPair = tree2.InsertNode(4);
    BinaryTree::Node_t *node4 = fourPair.second;
    
    ASSERT_FALSE(node4 == NULL);    //  node4 is not empty
    EXPECT_TRUE(fourPair.first);    //  bool-pointer in node4 is true
    ASSERT_TRUE(node4->pParent != NULL);    //  node4 have got parent
    EXPECT_EQ(node4->pParent->key, 10);    //  node4 have got parent 10

//  vlozeni existujciho uzlu
	std::pair<bool, BinaryTree::Node_t *> newExistPair = tree2.InsertNode(10);
	BinaryTree::Node_t *newExistNode = newExistPair.second;
	ASSERT_FALSE(newExistNode == NULL);    //  existNode is not empty
	ASSERT_FALSE(newExistPair.first);  //  bool-pointer in existNode is false

}

TEST_F(NonEmptyTree, FindNode) {

    BinaryTree::Node_t *secondFoundNode = tree2.FindNode(10);
    EXPECT_NE(nullptr, secondFoundNode); //  finding node with quantity 1
    EXPECT_EQ(secondFoundNode->key, 10);

    BinaryTree::Node_t *secondNotFoundNode = tree2.FindNode(322);
    EXPECT_EQ(nullptr, secondNotFoundNode); //  finding node with quantity 322
}

TEST_F(NonEmptyTree, DeleteNode) {

    EXPECT_TRUE(tree2.DeleteNode(10));   //  we can delete node with quantity 1
    EXPECT_TRUE(tree2.DeleteNode(11));   //  we can delete node with quantity 11
    EXPECT_TRUE(tree2.DeleteNode(12));   //  we can delete node with quantity 12
    EXPECT_FALSE(tree2.DeleteNode(10));  //  we can not delete node with quantity 10
    EXPECT_FALSE(tree2.DeleteNode(11));   //  we can delete node with quantity 11
    EXPECT_FALSE(tree2.DeleteNode(12));  //  we can not delete node with quantity 12
    EXPECT_FALSE(tree2.DeleteNode(322));  //  we can not delete node with quantity 322
}

class TreeAxioms : public ::testing::Test{
    protected:
        void SetUp(){
            tree3.InsertNode(10);
            tree3.InsertNode(20);
            tree3.InsertNode(30);
            tree3.InsertNode(40);
            tree3.InsertNode(50);
            tree3.InsertNode(60);
            tree3.InsertNode(70);
            tree3.InsertNode(80);
            tree3.InsertNode(90);
            tree3.InsertNode(100);
        }
        BinaryTree tree3;
};

TEST_F(TreeAxioms, Axiom1) {
    std::vector<BinaryTree::Node_t *> allLeafs;
    tree3.GetLeafNodes(allLeafs);   //  take all leafs nodes

    for(int i = 0; i < allLeafs.size(); i++) {
        ASSERT_EQ(nullptr, allLeafs[i]->pLeft); //  leaf haven't got descendant
        ASSERT_EQ(nullptr, allLeafs[i]->pRight);    //  leaf haven't got descendant 
        EXPECT_TRUE(allLeafs[i]->pParent != NULL);  //  leaf have got parent
        EXPECT_EQ(allLeafs[i]->key, NULL);  //  leaf haven't got information
        EXPECT_TRUE(allLeafs[i]->color == BLACK);   //  leaf is black
    }
}

TEST_F(TreeAxioms, Axiom2) {
    std::vector<BinaryTree::Node_t *> nodesNotLeafs;
    tree3.GetNonLeafNodes(nodesNotLeafs);   //  take all non leafs nodes

    for(int i = 0; i < nodesNotLeafs.size(); i++) {
        if (nodesNotLeafs[i]->color == RED) {
            EXPECT_TRUE(nodesNotLeafs[i]->pLeft->color == BLACK);   //  left descendant is black
            EXPECT_TRUE(nodesNotLeafs[i]->pRight->color == BLACK);   //  right descendant is black
        }
    }
}

TEST_F(TreeAxioms, Axiom3) {
    std::vector<BinaryTree::Node_t *> leafsNodes;
    tree3.GetLeafNodes(leafsNodes); //  leafs
    Node_t *root = tree3.GetRoot(); //  root
    int cesta = 0;
    //  way for leafs from nodes
    for (int i = 0; i < leafsNodes.size(); i++) {
        while (leafsNodes[i] != root) {
            if (leafsNodes[i]->color == BLACK) {
                cesta++;
            }
            leafsNodes[i] = leafsNodes[i]->pParent;
        }   
        EXPECT_EQ(cesta, 3);
        cesta = 0; 
    }
}

/*** Konec souboru black_box_tests.cpp ***/