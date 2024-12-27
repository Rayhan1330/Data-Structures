#include <stdio.h>
#include <time.h>
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

NODE *parent_func(NODE *root,NODE *sub){
    if(root->left == sub || root->right==sub)
        return root;
    else{
        if(sub->data<root->data)
            root = parent_func(root->left,sub);
        else
            root = parent_func(root->right,sub);
    }
    return root;
}

void delete(NODE **root,NODE **parent,int data){
    NODE *pre,*par;int temp;
    if((*root)->data == data){
        if((*root)->left==NULL && (*root)->right==NULL){
            if((*parent)->left==(*root))
                (*parent)->left = NULL;
            else
                (*parent)->right = NULL;
        }
        else if((*root)->left!=NULL && (*root)->right==NULL){
            if((*parent)->left==(*root))
                (*parent)->left = (*root)->left;
            else
                (*parent)->right = (*root)->left;
        }
        else if((*root)->left==NULL && (*root)->right!=NULL){
            if((*parent)->left==(*root))
                (*parent)->left = (*root)->right;
            else
                (*parent)->right = (*root)->right;
        }
        else if((*root)->left!=NULL && (*root)->right!=NULL){
            pre = predecessor(*root);
            temp = pre->data;
            pre->data = (*root)->data;
            (*root)->data = temp;
            par = parent_func(*root,pre);
            delete(&pre,&par,data);
        }
    }
    else{
        if((*root)->data>data)
            delete(&((*root)->left),root,data);
        else
            delete(&((*root)->right),root,data);
    }
}

int height(NODE *root){
    if(root==NULL)
        return 0;
    else{
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1 + (h1>h2?h1:h2);
    }
}

NODE *create(NODE *root,int data){
    if(root==NULL){
        root = (NODE *)malloc(sizeof(NODE));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if(root->data>data)
            root->left = create(root->left,data);
        else
            root->right = create(root->right,data);
    }
    return root;
}

NODE *create_complete(NODE *root,int data,int n){
    if(root==NULL){
        root = (NODE *)malloc(sizeof(NODE));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if(root->data>data)
            root->left = create(root->left,data);
        else
            root->right = create(root->right,data);
    }
    if(height(root)>n)
        delete(&root,&root,data);
    return root;
}

int no_of_nodes(NODE *root,int h){
    if(root->left!=NULL)
        h = no_of_nodes(root->left,++h);
    if(root->right!=NULL)
        h = no_of_nodes(root->right,++h);
    return h;
}

void inorder(NODE *root){
    if(root->left!=NULL)
        inorder(root->left);
    printf("%d--> ",root->data);
    if(root->right!=NULL)
        inorder(root->right);
}

void leaf_link(NODE **root,NODE **tail){
    if((*root)->left!=NULL)
        leaf_link(&(*root)->left,tail);
    if((*root)->left==NULL && (*root)->right==NULL){
        if(*tail==NULL)
            *tail = *root;
        else{
            (*tail)->right = *root;
            *tail = *root;
        }
    }
    if((*root)->right!=NULL)
        leaf_link(&(*root)->right,tail);
}

void print_leaf(NODE *root){
    while(root->left!=NULL)
        root=root->left;
    for(NODE *temp = root;root!=NULL;root = root->right)
        printf("%d--> ",root->data);
}

int main(void){
    NODE *root = NULL;
    NODE *com = NULL;
    srand(time(0));
    int n;
    printf("Enter height of tree: ");
    scanf("%d",&n);
    int data;
    int no = 1;
    for(int i =0;i<n;i++)
        no = 2*no;
    no = no -1;
    for(int i=0;i<no;i++){
        data = (rand()%(100-1+1)) + 1;
        if(i==0)
            data = (rand()%(75-25+1)) + 25;
        printf("\n%d \n",data);
        com = create_complete(com,data,n);
        if(no_of_nodes(com,1)!=i+1){
            printf("%d height: %d, %d",no_of_nodes(com,1),height(com),i+1);
            i--;
        }
            
    }
    printf("\n");
    inorder(com);
    printf("\n%d\n",no_of_nodes(com,1));
    
    leaf_link(&com,&root);
    print_leaf(com);
    return 0;
}
