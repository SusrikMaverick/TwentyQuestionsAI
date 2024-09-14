// File: bst.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct Node* createNode(int data, char* question, char* guess) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->question = strdup(question);
    if (newNode->question == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->guess = strdup(guess);
    if (newNode->guess == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data, char* question, char* guess) {
    if (root == NULL) {
        return createNode(data, question, guess);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data, question, guess);
    } else {
        root->right = insertNode(root->right, data, question, guess);
    }
    return root;
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root->question);
    free(root->guess);
    free(root);
}

