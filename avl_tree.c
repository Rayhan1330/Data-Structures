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

int bal_fac(NODE *root){
    int bf = height(root->left) - height(root->right);
    if(bf==1 || bf==-1 || bf==0)
        return 1;
    else
        return 0;
}

NODE *leftleft(NODE *z){
    NODE *y = z->left;
    z->left = y->right;
    y->right = z;
    return y;
}

NODE *rightright(NODE *z){
    NODE *y = z->right;
    z->right = y->left;
    y->left = z;
    return y;
}

NODE *leftright(NODE *z){
    z->left = rightright(z->left);
    return leftleft(z);
}

NODE *rightleft(NODE *z){
    z->right = leftleft(z->right);
    return rightright(z);
}

NODE *create_tree(NODE *root,int data){
    if(root==NULL){
        root = (NODE *)malloc(sizeof(NODE));
        root->data = data;
        root->right=NULL;
        root->left= NULL;
    }
    else{
        if(root->data<data){
            root->right = create_tree(root->right,data);
            int bf = height(root->left) - height(root->right);
            if(bf<=-2){
                if(data>(root->right)->data)
                    root = rightright(root);
                else
                    root = rightleft(root);
            }
        }
        else if(root->data>data){
            root->left = create_tree(root->left,data);
            int bf = height(root->left) - height(root->right);
            if(bf>=2){
                if(data<(root->left)->data)
                    root = leftleft(root);
                else
                    root = leftright(root);
            }
        }
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



int main(void){
    NODE *root = NULL;
    int c;
    while(1){
        printf("insert(0/1): ");
        scanf("%d",&c);
        if(c==1){
            int data;
            printf("Enter data: ");
            scanf("%d",&data);
            root = create_tree(root,data);
            inorder(root);
            printf("\n\n");
        }
        else
            break;
    }
    inorder(root);
}
