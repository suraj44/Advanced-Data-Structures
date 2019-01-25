#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"

#ifndef max
#define max(a,b)            (((a) >= (b)) ? (a) : (b))
#endif


node* new_node(int val){
    node* n = (node*)malloc(sizeof(node));
    n->val= val;
    n->right = NULL;
    n->left = NULL;
    n->height = 0;
    return n;
}

int height(node* root) {
    if(root== NULL)
        return 0;
    return root->height;
}


node* left_rotate(node* root) {
    node * right = root->right;
    node * right_child = right->left;

    root->right = right_child;
    right->left = root;

    root->height = max(height(root->right), height(root->left)) + 1;
    right->height = max(height(right->right), height(right->left)) + 1;

    return right;
}

node* right_rotate(node* root) {
    node* left = root->left;
    node* left_child = left->right;

    left->right = root;
    root->left = left_child;

    root->height = max(height(root->right), height(root->left)) + 1;
    left->height = max(height(left->right), height(left->left)) + 1;

    return left;


}


int balance_factor(node* root) {
    int balance_factor = height(root->left) - height(root->right);
    return balance_factor;
}

node * insert(node *root, int val) {  
    if (root == NULL) 
        return new_node(val);
    int currVal = root->val;
    if(val < currVal) {
        insert(root->left, val);
    } else if ( val > currVal) {
        insert(root->right, val);
    } else {
        return root;
    }

    root->height = max(height(root->right), height(root->left)) + 1;

    int bf = balance_factor(root);
    if(bf > 1 && val < root->left->val) {
        right_rotate(root);
    }
    if (bf < -1 && val > root->right->val ) {
        left_rotate(root);
    }
    if(bf > 1 && val > root->left->val) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (bf < -1 && val < root->right->val) {
        root->right = right_rotate(root->right);
        left_rotate(root);
    }

    return root;
}
int main(int argc, char*argv[]) {
    clock_t start, stop;
    NUM_VALS = (long long int)atoll(argv[1]);

    int *values = (int*)malloc(NUM_VALS * sizeof(int));

    FILE *f = fopen("data.txt", "r");

    for(int i=0;i< NUM_VALS; i++) {
        fscanf(f, "%d\n", &values[i]);
    }

    while(1) {
        int ch;
        printf("1. Search for a value, 2. Delete a value, anything else to exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter a value to search for:\n");
                int search;
                scanf("%d", &search);
                // search function
                break;
            case 2:
            printf("Enter a value to delete:\n");
                int del;
                scanf("%d", &del);
                // delete function
                break;

            default:
                printf("exiting...");
                exit(0);

        }
    }

}

