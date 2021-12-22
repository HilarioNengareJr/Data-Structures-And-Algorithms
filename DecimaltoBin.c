/*-----------------------------
Author:  Hilario Nengare Jr.
Lab Work :   No. 6
Linked Stack:
Decimal to Binary conversion
-----------------------------*/

#include <stdio.h>
 // for malloc()
#include <stdlib.h>


// Node structure for stack
struct node {
        // store the remainder 
        int info;
        // self-referencing pointer to store address of next node
        struct node * next;
};

// last inserted node indicating an empty stack
struct node * head = NULL;

// push the remainder to stack
void push(int rem) {
        // Create a new node  
        struct node * new_node = malloc(sizeof(struct node));
        new_node -> info = rem;

        // new node points to the head node
        new_node -> next = head;

        // make new node as the head node so that it points to last inserted data
        head = new_node;
}

void pop() {
        struct node * temp;

        // check if stack is empty
        if (head == NULL) {
                printf(" Stack is empty!!");
        } else {
                printf(" Popped binary %i", head -> info);

                temp = head;
                // remove the node
                head = head -> next;
                free(temp);
        }
}

// printing function
void traverse() {
        struct node * temp;
        temp = head;

        printf("The Binary Equivalence = ");
        while (temp != NULL) {
                printf("%i", temp -> info);
                temp = temp -> next;
        }
        printf("\n");
        return;
}

// conversion function
void DecimalToBin(int number) {
        int r;

        while (number != 0) {
                r = number % 2;
                number = number / 2;
                push(r);
        }
}

int main() {

        int n;

        printf("\nEnter Any Decimal Number To Convert Into Binary = ");
        scanf("%i", & n);
        printf("\n");
        DecimalToBin(n);
        traverse();

        return 0;
}
