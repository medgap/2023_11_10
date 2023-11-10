#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

int max(int a, int b){
    return a > b ? a :b;
}

int getHeight(TreeNode* t){
    return t ? t->height : 0;
}

void llRotation(TreeNode* node,TreeNode** root){
    TreeNode* temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node -> height = max(getHeight(node -> lchild), getHeight(node -> rchild)) + 1;
    temp -> height = max(getHeight(temp -> lchild), getHeight(temp -> rchild)) + 1;
    *root = temp;
}

void rrRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node -> height = max(getHeight(node -> lchild), getHeight(node -> rchild)) + 1;
    temp -> height = max(getHeight(temp -> lchild), getHeight(temp -> rchild)) + 1;
    *root = temp;
}

void AVLInsert(TreeNode** t,int data){
    if(*t == NULL){
        *t = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data = data;
        (*t)->height = 1;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
    }
    else if((*t)->data == data){
        return;
    }
    else if(data < (*t)->data){
        AVLInsert(&(*t)->lchild,data);
        int lheight = getHeight((*t)->lchild);
        int rheight = getHeight((*t)->rchild);
        if(lheight - rheight == 2){
            //调整
            if(data < (*t)->lchild->data){
                //LL
                llRotation(*t,t);
            }
            else{
                //LR
                rrRotation((*t)->lchild,&((*t)->lchild));
                llRotation(*t,t);
            }
        }
    }
    else if(data > (*t)->data){
        AVLInsert(&(*t)->rchild,data);
        int lheight = getHeight((*t)->lchild);
        int rheight = getHeight((*t)->rchild);
        if(rheight - lheight == 2){
            if(data > (*t)->rchild->data){
                //RR
                rrRotation(*t,t);
            }
            else{
                //RL
                llRotation((*t)->rchild,&((*t)->rchild));
                rrRotation(*t,t);
            }
        }
    }
     (*t)->height = max(getHeight((*t) -> lchild), getHeight((*t) -> rchild)) + 1;
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
    int nums[5] = {1,8,6,7,10};
    for(int i = 0; i < 5; i++){
        AVLInsert(&t,nums[i]);
    }
    preOrder(t);
    printf("\n");
    return 0;
}