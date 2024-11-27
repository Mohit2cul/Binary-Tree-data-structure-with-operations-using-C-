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
// searching for the tree is a BST or not

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

struct node * search(node *root , int key){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == key){
        return root;
    }
    else if (root -> data > key){
        return search(root -> left , key);
    }
    else{
        return search(root -> right , key);
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
    struct node * n = search(p , 8);
    if(n != NULL){
        printf("Element Found : %d",n -> data);
    }
    else{
        printf("Element Not Found.");
    }
    return 0;
}