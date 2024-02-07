/// @file priorityqueue.h
///
///@brief Priority Queue class allows for the storage of data in a tree structure where each data has a priority associated with it. 
///This class also allows the user to manipulate the tree by adding, removing, and looking for data.
///
///@author Raymond Lo
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    
    /**
     * @brief Copy a node and its children
     * 
     * @param node to copy
     * 
     * @return pointer to the new node with the same value as the original
     */
    NODE* copyNode(NODE* node){
        if(node == nullptr){
            return nullptr;
        }
        NODE* newNode = new NODE;
        newNode->priority = node->priority;
        newNode->value = node->value;
        newNode->dup = node->dup;
        newNode->link = copyNode(node->link);
        newNode->left = copyNode(node->left);
        newNode->right = copyNode(node->right);
        return newNode;
    }

    /**
     * @brief Set the parent pointer for all nodes in the tree
     * 
     * @param node to start at
     */
    void setParent(NODE* node){
        if(node == nullptr){
            return;
        }
        if(node->left != nullptr){
            node->left->parent = node;
            setParent(node->left);
        }
        if(node->dup == true){
            node->link->parent = node;
            setParent(node->link);
        }
        if(node->right != nullptr){
            node->right->parent = node;
            setParent(node->right);
        }
    }

    /**
     * @brief Delete all duplicate nodes in a node's link
     * 
     * @param node to start at
     */
    void clearLink(NODE* node){
        if(node == nullptr){
            return;
        }else{    
            NODE* temp = node->link;
            delete node;
            clearLink(temp);
        }
    }
    
    /**
     * @brief Delete all nodes in the tree
     * 
     * @param node to start at
     */
    void clearNode(NODE* node) {
        if(node == nullptr){
            return;
        }
        if(node->dup == true){
            clearLink(node->link);
            node->link = nullptr;
        }
        clearNode(node->left);
        clearNode(node->right);
        delete node->left;
        delete node->right;
        node->left = nullptr;
        node->right = nullptr;
    }

    /**
     * @brief insert a node into a node's link list
     * 
     * @param node to start at
     */
    void insertLinkNode(NODE* node, NODE* newNode){
        if(node->link == nullptr){
            node->dup = true;
            node->link = newNode;
            newNode->parent = node;
            return;
        }else{
            insertLinkNode(node->link, newNode);
        }
    }

    /**
     * @brief insert a node into the tree
     * 
     * @param node to start at
     */
    void insertNode(NODE* node, NODE* newNode, const int& priority){
        if(priority == node->priority){
            insertLinkNode(node, newNode);
            return;
        }else if(priority < node->priority){
            if(node->left == nullptr){
                node->left = newNode;
                newNode->parent = node;
                return;
            }else{
                insertNode(node->left, newNode, priority);
            }
        }else{
            if(node->right == nullptr){
                node->right = newNode;
                newNode->parent = node;
                return;
            }else{
                insertNode(node->right, newNode, priority);
            }
        }
    }

    /**
     * @brief stores the data of the node which are the value and priority in order
     * 
     * @param node to start at
     */
    void toStringHelper(NODE* node, stringstream& ss){
        if(node == nullptr){
            return;
        }
        toStringHelper(node->left, ss);
        ss << node->priority << " value: " << node->value << "\n";
        if(node->dup == true){
            toStringHelper(node->link, ss);
        }
        toStringHelper(node->right, ss);
    }

    /**
     * @brief print the tree in order
     * 
     * @param node to start at
     *
     */
    void printTreeHelper(NODE* node){
        if(node == nullptr){
            return;
        }
        printTreeHelper(node->left);
        cout << "Node value: " << node->value << ", Node priority: " << node->priority << endl;
        if(node->dup == true){
            printTreeHelper(node->link);
        }
        printTreeHelper(node->right);
    }

public:
    /**
     * @brief Default constructor
     * 
     * creates an empty priority queue
     * O(1)
    */
    priorityqueue() {
        root = nullptr;
        size = 0;
        curr = nullptr;      
    }
        
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other){
        this->clear();
        this->root = copyNode(other.root);
        this->size = other.size;
        this->curr = this->root;
        setParent(this->root);
        return *this;
    }

    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        this->~priorityqueue();
        root = nullptr;
        size = 0;
        curr = nullptr;
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        if(root == nullptr){
            return;
        }
        clearNode(root);
        //if(root->left != nullptr){delete root->left;}
        //if(root->right != nullptr){delete root->right;}
        delete root;
    }

    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    //
    void enqueue(T value, int priority){
        NODE* newNode = new NODE;
        newNode->value = value;
        newNode->priority = priority;
        newNode->dup = false;
        newNode->parent = nullptr;
        newNode->link = nullptr;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if(root == nullptr){
            root = newNode;
            size++;
            return;
        }
        insertNode(root, newNode, priority);
        size++;
    }
    
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T dequeue() {
        T valueOut = T();
        NODE* node = root;
        if(root == nullptr){
            return valueOut;
        }
        if(node->left == nullptr && node == root){
            if(node->dup == true){
                root = node->link;
                root->parent = nullptr;
                root->right = node->right; 
                node->right = nullptr;   
                node->dup = false;  
            }else{
                root = node->right;
                if(root != nullptr){\
                    root->parent = nullptr;
                }
                node->right = nullptr;
            }
            //node = node->right;
        }
        while(node->left != nullptr){
            node = node->left;
        }
        if(node->dup == true){
            if(node->parent != nullptr){
                if(node->parent->left == node){
                    node->link->left = node->left;
                    node->link->right = node->right;
                    node->link->parent = node->parent;
                    node->parent->left = node->link;
                }else{
                    node->link->left = node->left;
                    node->link->right = node->right;
                    node->link->parent = node->parent;
                    node->parent->right = node->link;
                }
            }
        }
        valueOut = node->value;
        if(node->right != nullptr){
            if(node->parent->left == node){
                node->right->parent = node->parent;
                node->parent->left = node->right;
            }
        }
        if(node->parent != nullptr){
            if(node->parent->left == node){
                node->parent->left = nullptr;
            }else if(node->parent->right == node){
                node->parent->right = nullptr;
            }
        }
        delete node;
        size--;
        return valueOut;
    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        return size; 
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;    
    void begin(){
        NODE* node = root;
        while(node != nullptr){
            if(node->left != nullptr){
                node = node->left;
            }else{
                curr = node;
                break;
            }
        }
    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls. If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority){
        if(curr == nullptr){
            return false;
        }
        value = curr->value;
        priority = curr->priority;
        if(curr->dup == true){
            curr = curr->link;
            return true;
        }
        if(curr->parent != nullptr && curr->parent->link == curr){
            while(curr->parent != nullptr && curr->parent->link == curr){
                curr = curr->parent;
            }
        }
        if(curr->right != nullptr){
            curr = curr->right;
            while(curr->left != nullptr){
                curr = curr->left;
            }
        }else{
            if(curr->parent == nullptr){
                return false;
            }
            while(curr->parent->left != curr){
                curr = curr->parent;
                if(curr->parent == nullptr){
                    return false;
                }
            }
            curr = curr->parent;
        }
        return true;
    }

    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
        // TO DO: write this function.
        stringstream test;
        toStringHelper(root, test);
        return test.str(); // TO DO: update this return
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T peek() {
        T valueOut = T();
        NODE* node = root;
        if(node == nullptr){
            return valueOut;
        }
        while(node->left != nullptr){
            node = node->left;
        }
        valueOut = node->value;
        return valueOut; // TO DO: update this return
    }
    

    bool checkTree(NODE* node, const NODE* otherNode) const{
        if(node == nullptr && otherNode == nullptr){
            return true;
        }
        if(node != nullptr && otherNode != nullptr){
            return (node->priority == otherNode->priority 
                    && node->value == otherNode->value 
                    && node->dup == otherNode->dup
                    && checkTree(node->link, otherNode->link)
                    && checkTree(node->left, otherNode->left) 
                    && checkTree(node->right, otherNode->right));
        }
        return true;
    }

    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const{
        if(this->root == nullptr && other.root == nullptr){
            return true;
        }
        if(this->size != other.size){
            return false;
        }
        return checkTree(this->root, other.root);
    }
    
    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }

    /**
     * @brief Prints the tree in order
    */
    void printTree(){
        if(root == nullptr){
            cout << "Tree is empty" << endl;
            return;
        }
        printTreeHelper(root);
    }
};
