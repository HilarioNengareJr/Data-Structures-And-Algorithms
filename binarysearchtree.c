// Modified Version

#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

typedef struct Node {
        int key;
        struct Node * left, * right;
}
Node;

Node * get_node(int x) {
        // allocate memory from the heap
        Node * newnode = malloc(sizeof(Node));
        newnode -> key = x;
        newnode -> left = NULL;
        newnode -> right = NULL;

        return newnode;
}

Node * Insert(Node * root, int x) {
        if (root == NULL) {
                return get_node(x);
        }

        if (root -> key > x) {
                root -> right = Insert(root -> right, x);
        } else if (root -> key < x) {
                root -> left = Insert(root -> left, x);
        }

        return root;
}

Node * search(Node * root, int x) {
        while (root != NULL) {
                if (root -> key == x) {
                        printf("Root is Equivalent to %i", x);
                        return root;
                } else if (root -> key > x) {
                        printf("Found in the Left Subtree!");
                        return search(root -> left, x);
                } else
                        printf("Found in the Right Subtree");
                return search(root -> right, x);
        }
        return NULL;
}

int get_right_min(Node * root) {
        Node * temp = root;

        //min value should be present in the left most node.
        while (temp -> left != NULL) {
                temp = temp -> left;
        }

        return temp -> key;
}

Node * delete_node(Node * root, int x) {
        if (root == NULL)
                return NULL;

        else if (x > root -> key) {
                root -> right = delete_node(root -> right, x);
        } else if (x < root -> key) {
                root -> left = delete_node(root -> left, x);
        } else {
                // for the leaves
                if (root -> left == NULL && root -> right) {
                        free(root);
                        return NULL;
                } else if (root -> left == NULL) {
                        Node * temp = root -> right; // back the right subtree up in temp address
                        free(root); // then release that space
                        return temp;
                } else if (root -> right == NULL) {
                        Node * temp = root -> right;
                        free(root);
                        return temp;
                }
                // Node has both left and right children.
                else {
                        int rmin = get_right_min(root -> right);
                        root -> key = rmin;
                        root -> right = delete_node(root -> right, rmin);
                }

        }
        return root;
}

void inorder(Node * root) {
        if (root == NULL)
                return; //if root is null return out of this whole situation

        inorder(root -> right);
        printf(" %i ", root -> key);
        inorder(root -> left);
}

int main(int argc, char * argv[]) {

        // initialise the tree
        struct Node * tree = NULL;

        tree = Insert(tree, 5);
        tree = Insert(tree, 6);
        tree = Insert(tree, 7);
        search(tree, 6);

        inorder(tree);

        return 0;
}
