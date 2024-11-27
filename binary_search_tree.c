# include <stdio.h>
# include <malloc.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

//creation of a binary tree
//      5
//     / \
//    3   6 
//   / \
//  1   4

struct node* createNode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void inOrderTraversal(struct node *root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d ",root -> data);
        inOrderTraversal(root -> right);
    }
}

int isBST(struct node* root){
    static struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root -> left)){
            return 0;
        }
        if(prev != NULL && root -> data <= prev -> data){
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    }
    else{
        return 1;
    }
}

int main() {

    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    printf("In-Order Traversal : ");
    inOrderTraversal(p);
    if(isBST(p)){
        printf("\nSince In-Order Traversal is in ascending order so this is a Binary Search Tree(BST).");
    }
    else{
        printf("\nThis is not a Binary search tree..");
    }
    return 0;
}
