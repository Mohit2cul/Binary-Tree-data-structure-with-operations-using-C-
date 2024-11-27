#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

struct node *createNode(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrderTraversal(struct node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int isBST(struct node *root) {
    static struct node *prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

struct node *search(node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void insert(node *root, int key) {
    struct node *prev = NULL;

    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot insert %d, already in BST\n", key);
            return; 
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    struct node *new = createNode(key);
    if (key < prev->data) {
        prev->left = new;
    } else {
        prev->right = new;
    }
}

struct node *inOrderPredecessor(struct node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root,int value){
    struct node *iPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
         free(root);
         return NULL;
    }
    if(value < root->data){
       root->left = deleteNode(root->left,value);
    }
    else if(value > root->data){
       root->right = deleteNode(root->right,value);
    }
    else{
        iPre = inOrderPredecessor(root);
        root ->data = iPre->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
}

int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    //creation of a binary tree
    //      5
    //     / \
    //    3   6 
    //   / \
    //  1   4

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    if (p->right->right != NULL) {
        printf("%d\n", p->right->right->data);
    }
    printf("In-order Traversal: ");
    inOrderTraversal(p);
    printf("\n");
 
    // deleting a node 4
    deleteNode(p,4);

     // tree after deletion of 4
    //       5
    //      / \
    //     3   6 
    //    / 
    //   1 

    printf("In-order Traversal after deletion: ");
    inOrderTraversal(p);
    printf("\n");
    return 0;
}
