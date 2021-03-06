#ifndef BINARYTREE_H
#define BINARYTREE_H 1

#include <queue> // needed a queue for the insert operation
#include "Node.h"
#include <iostream>

TEMP
class BinaryTree {
public:
    // constructor
    BinaryTree(type);
    // destructor
    ~BinaryTree();

    // traversals
    
    // traverse the tree in preorder
    BinaryTree<type> *traversePreOrder();
    // traverse the tree in postrder
    BinaryTree<type> *traversePostOrder();
    // traverse the tree in inorder
    BinaryTree<type> *traverseInOrder();
    // traverse the tree in level order
    BinaryTree<type> *traverseLevelOrder();

    // add an element to the tree
    BinaryTree<type> *insertItem(type);


private: // variables
    Node<type> *root;

private: // functions
    // the dark side version of pre order traversal 
    static void preOrderTraversal(Node<type> *);
    // the dark side version of pre order traversal 
    static void postOrderTraversal(Node<type> *);
    // the dark side version of pre order traversal 
    static void inOrderTraversal(Node<type> *);
    // the dark side version of level order traversal
    static void levelOrderTraversal(Node<type> *);

    // get a node's height
    static int getNodeHeight(Node<type> *);

    // print a specified level
    static void printLevel(Node<type> *, int);

    // append an element to where null is found
    static void appendToNullNode(Node<type> *, type);

};

TEMP
// constructor
BinaryTree<type>::BinaryTree(type value) {
    // update root
    root = new Node<type>(value);
    // set root parent to null
    root->setParent(NULL);
}

TEMP
// destructor
BinaryTree<type>::~BinaryTree() {
    delete root;
}

TEMP
// print tree's elements in preorder traversal
BinaryTree<type> *BinaryTree<type>::traversePreOrder() {
    // 
    BinaryTree::preOrderTraversal(this->root);
    // stdout flush
    std::cout << std::endl;

    return this;
}

TEMP
// print tree's elements in postorder traversal
BinaryTree<type> *BinaryTree<type>::traversePostOrder() {
    // 
    BinaryTree::postOrderTraversal(this->root);
    // stdout flush
    std::cout << std::endl;

    return this;
}

TEMP
// print tree's elements in inorder traversal
BinaryTree<type> *BinaryTree<type>::traverseInOrder() {
    // 
    BinaryTree::inOrderTraversal(this->root);
    // stdout flush
    std::cout << std::endl;

    return this;
}

TEMP
// print tree's elements in level order traversal
BinaryTree<type> *BinaryTree<type>::traverseLevelOrder() {
    //
    BinaryTree::levelOrderTraversal(this->root);
    // stdout flush
    std::cout << std::endl;

    return this;
}

TEMP
// insert an item to the binary tree
BinaryTree<type> *BinaryTree<type>::insertItem(type value) {
    BinaryTree::appendToNullNode(this->root, value);

    return this;
}

// static functions
TEMP
// the dark side version of preorder traversal 
void BinaryTree<type>::preOrderTraversal(Node<type> *root) {
    // preorder <root><left><right>
    
    // current node in the tree
    Node<type> *current = root;
    Node<type> *currentLeft = root->getLeft();
    Node<type> *currentRight = root->getRight();
    
    // print current node's value
    std::cout << current->getValue() << " ";

    // now traverse left and right children
    if(currentLeft) {
        BinaryTree::preOrderTraversal(currentLeft);
    }
    if(currentRight) {
        BinaryTree::preOrderTraversal(currentRight);
    }

}

TEMP
// the dark side version of postorder traversal 
void BinaryTree<type>::postOrderTraversal(Node<type> *root) {
    // postorder <left><root><right>
    
    // current node in the tree
    Node<type> *current = root;
    Node<type> *currentLeft = root->getLeft();
    Node<type> *currentRight = root->getRight();
    
    // now traverse left and right children
    if(currentLeft) {
        BinaryTree::postOrderTraversal(currentLeft);
    }
    if(currentRight) {
        BinaryTree::postOrderTraversal(currentRight);
    }
    // print current node's value
    std::cout << current->getValue() << " ";

}

TEMP
// the dark side version of inorder traversal 
void BinaryTree<type>::inOrderTraversal(Node<type> *root) {
    // inorder <left><right><root>
    
    // current node in the tree
    Node<type> *current = root;
    Node<type> *currentLeft = root->getLeft();
    Node<type> *currentRight = root->getRight();
     
    // traverse left child
    if(currentLeft) {
        BinaryTree::inOrderTraversal(currentLeft);
    }
    
    // print current node's value
    std::cout << current->getValue() << " ";
    
    // traverse right child
    if(currentRight) {
        BinaryTree::inOrderTraversal(currentRight);
    }
    

}

TEMP 
// print a specified level
void BinaryTree<type>::printLevel(Node<type> *someNode, int level) {
    // print value when root is reached
    if(level == 1) {
        std::cout << someNode->getValue() << " ";
    } 
    // there must be an else, because the function is a void returning type
    else {
        int rightHeight, leftHeight;
        leftHeight = BinaryTree::getNodeHeight(someNode->getLeft());
        rightHeight = BinaryTree::getNodeHeight(someNode->getRight());

        if(someNode->getLeft()) {
            BinaryTree::printLevel(someNode->getLeft(), level - 1); 
        }
        if(someNode->getRight()){
                BinaryTree::printLevel(someNode->getRight(), level - 1);
        }
        // -1 so it prints L & R of the current level
    }

}

TEMP
// get node's height
int BinaryTree<type>::getNodeHeight(Node<type> *someNode) {
    if(!someNode){
        return 0;
    }
    int leftHeight;
    int rightHeight;
    
    leftHeight = BinaryTree::getNodeHeight(someNode->getLeft());
    rightHeight = BinaryTree::getNodeHeight(someNode->getRight());

    return leftHeight > rightHeight? leftHeight + 1: rightHeight + 1; // +1 for root
}

TEMP
// the dark side version of level order traversal
void BinaryTree<type>::levelOrderTraversal(Node<type> *root) {
    int height;
    height = BinaryTree::getNodeHeight(root);
    int tmp = height;
    while(height--) {
        BinaryTree::printLevel(root,tmp - height );
    }
}

TEMP
// append an element to where null is found
void BinaryTree<type>::appendToNullNode(Node<type> *someNode, type valueToAppend) {

    std::queue<Node<type> *> *q = new std::queue<Node<type> *>;
    // add current node to the queue
    q->push(someNode);

    while(!q->empty()) {
        Node<type> *tmp = q->front();
        // remove the front node from the queue to emplacer an another one
        q->pop();

        // if there isn't a left add one
        if( !tmp->getLeft() ) {
            tmp->setLeft(new Node<type>(valueToAppend));
            break;
        } // if there is add it to the queue
        else {
            q->push(tmp->getLeft());
        }
        
        // if there isn't a right add one
        if( !tmp->getRight() ) {
            tmp->setRight(new Node<type>(valueToAppend));
            break;
        } // if there is add it to the queue
        else {
            q->push(tmp->getRight());
        }

    }

}
// end of static functions

#endif // BINARYTREE_H