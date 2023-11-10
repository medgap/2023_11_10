#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

TreeNode* BST(TreeNode* t,int key){
    if(t){
        if(key == t->data){
            return t;
        }
        else if(key < t->data){
            BST(t->lchild,key);
        }   
        else{
            BST(t->rchild,key);
        }
    }
    else{
        return NULL;
    }
    
}

void BSTInsert(TreeNode** t,int data){
    if(*t == NULL){
        *t = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data = data;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
    }
    else if(data == (*t)->data ){
        return;
    }
    else if(data < (*t)->data){
        BSTInsert(&((*t)->lchild),data);
    }
    else{
        BSTInsert(&((*t)->rchild),data);
    }
}

void preOrder(TreeNode* t){
    if(t){
        printf("%d ",t->data);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

int main(int argc,char* argv[]){
    TreeNode* t = NULL;
    int nums[6] = {8, 6, 10, 9, 11, 23};
    for(int i = 0; i < 6; i++){
        BSTInsert(&t,nums[i]);
    }
    preOrder(t);
    printf("\n");
    return 0;
}