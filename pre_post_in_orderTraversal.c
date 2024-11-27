# include <stdio.h>
# include <malloc.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

//creation of a binary tree
//      4
//     / \
//    1   6 
//   / \
//  5   2

struct node* createNode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void preOrderTraversal(struct node *root){
    if(root != NULL){
        printf("%d ",root -> data);
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

void postOrderTraversal(struct node *root){
    if(root != NULL){
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        printf("%d ",root -> data);
    }
}

void inOrderTraversal(struct node *root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d ",root -> data);
        inOrderTraversal(root -> right);
    }
}

int main() {

    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    printf("Pre-Order Traversal : ");
    preOrderTraversal(p);
    printf("\nPost-Order traversal : ");
    postOrderTraversal(p);
    printf("\nIn-Order Traversal : ");
    inOrderTraversal(p);
    return 0;
}