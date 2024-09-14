// File: twenty.c

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void playGame(struct Node* root) {
    char answer;
    if (root == NULL) {
        printf("I give up. What was your fruit/vegetable?\n");
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("It's a %s!\n", root->guess);
        printf("y/n: ");
        scanf(" %c", &answer);
        if (answer == 'y') {
            printf("I win!\n");
            return;
        }
        printf("I give up. What was your fruit/vegetable?\n");
        return;
    }
    printf("%s\n", root->question);
    printf("y/n: ");
    scanf(" %c", &answer);
    if (answer == 'y') {
        playGame(root->left);
    } else {
        playGame(root->right);
    }
}

int main() {
    struct Node* gameTree = NULL;
    gameTree = insertNode(gameTree, 100, "Does it grow underground?", "");
    insertNode(gameTree, 50, "Is it long in shape?", "");
    insertNode(gameTree, 25, "Is it orange in color?", "");
    insertNode(gameTree, 15, "", "It's a carrot!");
    insertNode(gameTree, 35, "", "It's a parsnip!");
    insertNode(gameTree, 75, "Is it red in color?", "");
    insertNode(gameTree, 65, "", "It's a radish!");
    insertNode(gameTree, 85, "", "It's a potato!");
    insertNode(gameTree, 150, "Does it grow on a tree?", "");
    insertNode(gameTree, 125, "Is it red in color?", "");
    insertNode(gameTree, 115, "", "It's an apple!");
    insertNode(gameTree, 135, "", "It's a peach!");
    insertNode(gameTree, 175, "Is it red in color?", "");
    insertNode(gameTree, 165, "", "It's a tomato!");
    insertNode(gameTree, 185, "", "It's a pea!");

    // Game Starts
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char c;
    scanf(" %c", &c);
    while (c != 'q') {
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        playGame(gameTree);
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &c);
    }

    freeTree(gameTree);

    printf("Bye Bye!\n");

    return 0;
}

