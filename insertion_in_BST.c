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

//creation of a binary tree
//      5
//     / \
//    3   6 
//   / \
//  1   4

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

int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 7); 

    if (p->right->right != NULL) {
        printf("%d\n", p->right->right->data);
    } else {
        printf("Node not inserted\n");
    }

    printf("In-order Traversal: ");
    inOrderTraversal(p);
    printf("\n");

    if (isBST(p)) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is not a BST\n");
    }

    return 0;
}
