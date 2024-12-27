#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}NODE;

NODE *predecessor(NODE *root){
    NODE *temp = root->left;
    while(temp->right!=NULL)
        temp = temp->right;
    return temp;
}

NODE *create_tree(NODE *root,int data){
    if(root==NULL){
        root = (NODE *)malloc(sizeof(NODE));
        root->data = data;
        root->right=NULL;
        root->left= NULL;
    }
    else{
        if(root->data<data)
            root->right = create_tree(root->right,data);
        else if(root->data>data)
            root->left = create_tree(root->left,data);
    }
    return root;
}

NODE *parent_func(NODE *root,NODE *req){
    if(root->left==req || root->right==req)
        return root;
    else{
        if(req->data<root->data)
            root = parent_func(root->left,req);
        else
            root = parent_func(root->right,req);
    }
    return root;
}

void delete(NODE **root,NODE **parent,int data){
    if((*root)->data == data){
        if((*root)->left==NULL && (*root)->right==NULL){
            if((*parent)->left == (*root))
                (*parent)->left = NULL;
            else
                (*parent)->right = NULL;
        }
        else if((*root)->left == NULL && (*root)->right!=NULL){
            if((*parent)->left == (*root))
                (*parent)->left = (*root)->right;
            else if((*parent)->right == (*root))
                (*parent)->right = (*root)->right;
            else
                root = &((*root)->right);
        }
        else if((*root)->left != NULL && (*root)->right==NULL){
            if((*parent)->right == (*root))
                (*parent)->right = (*root)->left;
            else if((*parent)->right == (*root))
                (*parent)->left = (*root)->left;
            else{
                root = &((*root)->left);
                printf("%d \n",(*root)->data);
            }
        }
        else if((*root)->left!=NULL && (*root)->right!=NULL){
            NODE *temp = predecessor(*root);
            NODE *parent1 = parent_func(*root,temp);
            int temp1;
            temp1 = (temp)->data;
            (temp)->data = (*root)->data;
            (*root)->data = temp1;
            delete(&temp,&parent1,data);
        }
    }
    else{
        if((*root)->data>data)
            delete(&((*root)->left),root,data);
        else
            delete(&((*root)->right),root,data);
    }
}

void inorder(NODE *root){
    if(root->left!=NULL)
        inorder(root->left);
    printf("%d-->",root->data);
    if(root->right!=NULL)
        inorder(root->right);
}

NODE *search(NODE *root,int data){
    if(root->data == data)
        return root;
    else{
        if(root->data<data)
            root = search(root->right,data);
        else
            root = search(root->left,data);
    }
    return root;
}

int height(NODE *root){
    if(root==NULL)
        return 0;
    else
    {
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1 + ((h1>h2)?h1:h2);
    }
}

int main(void){
    NODE *root = NULL;
    root = create_tree(root,9);
    //root = create_tree(root,10);
    root = create_tree(root,4);
    root = create_tree(root,2);
    root = create_tree(root,6);
    root = create_tree(root,5);
    root = create_tree(root,7);
    root = create_tree(root,3);
    root = create_tree(root,1);
    root = create_tree(root,8);
    inorder(root);
    printf("\n");
    //NODE *temp = search(root,4);
    //printf("\n%d \n",temp->data);
    //NODE *temp1 = parent_func(root,temp);
    //printf("%d \n",temp1->data);
    NODE **droot = &root;
    delete(droot,droot,8);
    inorder(root);
    printf("\n%d height",height(root));
}
