// File: bst.h

#ifndef BST_H
#define BST_H

struct Node {
    int data;
    char* question;
    char* guess;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data, char* question, char* guess);
struct Node* insertNode(struct Node* root, int data, char* question, char* guess);
void freeTree(struct Node* root);

#endif 

