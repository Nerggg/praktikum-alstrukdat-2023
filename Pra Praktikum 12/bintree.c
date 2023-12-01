#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    Address t = newTreeNode(root);
    if(t != NULL){
        t->left = left_tree;
        t->right = right_tree;
    }
    return t;
} 

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = newTreeNode(root);
    if(*p != NULL){
        (*p)->left = left_tree;
        (*p)->right = right_tree;
    }
}

Address newTreeNode(ElType val) {
    Address p = (Address) malloc(sizeof(TreeNode));
    if(p != NULL){
        p->info = val;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void deallocTreeNode (Address p) {
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    return p == NULL;
}

boolean isOneElmt (BinTree p) {
    if(!isTreeEmpty(p)){
        return p->left == NULL && p->right == NULL;
    }
    else{
        return false;
    }
}

boolean isUnerLeft (BinTree p) {
    if(!isTreeEmpty(p)){
        return p->left != NULL && p->right == NULL;
    }
    else{
        return false;
    }
}

boolean isUnerRight (BinTree p) {
    if(!isTreeEmpty(p)){
        return p->left == NULL && p->right != NULL;
    }
    else{
        return false;
    }
} 

boolean isBinary (BinTree p) {
    if(!isTreeEmpty(p)){
        return p->right != NULL && p->left != NULL;
    }
    else{
        return false;
    }
}

void printPreorder(BinTree p) {
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printf("%d", p->info);
        printPreorder(p->left);
        printPreorder(p->right);
        printf(")");
    }
}

void printInorder(BinTree p) {
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printInorder(p->left);
        printf("%d", p->info);
        printInorder(p->right);
        printf(")");
    }
}

void printPostorder(BinTree p) {
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printPostorder(p->left);
        printPostorder(p->right);
        printf("%d", p->info);
        printf(")");
    }
}

void recursivePrintTree(BinTree p, int h, int dep) {
    if(!isTreeEmpty(p)){
        for(int i = 0; i < h*dep; i++){
            printf(" ");
        }
        printf("%d\n", p->info);
        recursivePrintTree(p->left, h, dep+1);
        recursivePrintTree(p->right, h, dep+1);
    }
}

void printTree(BinTree p, int h) {
    recursivePrintTree(p,h,0);
}
