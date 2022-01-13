// Online C compiler to run C program online
#include <stdio.h>

#include <stdlib.h>

//create a Node structure for Queue
struct node {
        int data;
        struct node * next;
};

struct node * front = NULL, * rear = NULL;

void Enqueue(int x) {
        struct node * newnode = malloc(sizeof(struct node));
        newnode -> data = x;
        newnode -> next = NULL;

        if (front == NULL && rear == NULL) {
                front = rear = newnode;
        } else {
                rear -> next = newnode;
                rear = newnode;
        }

}

void Dequeue() {
        // to be used to delete node
        struct node * temp;

        if (front == NULL) {
                printf("Nothing to delete");
                return;
        } else {
                temp = front;
                front = front -> next;

                if (front == NULL)
                        rear = NULL;

                free(temp);
        }
}

void printl() {
        struct node * temp = front;

        while (temp) {
                printf(" %i -> ", temp -> data);
                temp = temp -> next;
        }
        printf("NULL\n");
}

int main() {

        Enqueue(45);
        Enqueue(78);
        Enqueue(546);
        printl();

        return 0;
}
