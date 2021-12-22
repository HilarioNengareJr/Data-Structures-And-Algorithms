/*-----------------------------
Author:  Hilario Nengare Jr.
Lab Work :   No. 7
Linked Queue:
String-Corrector Algorithm
-----------------------------*/
#include<stdio.h>

#include<stdlib.h>

#include<ctype.h>

struct Node {
        char info;
        struct Node * next;
};

struct Node * front = NULL;
struct Node * rear = NULL;

int isAlpha(char x) {
        // If symbol is an alphabet insert into a node
        if (x >= 65 && x <= 90) {
                return 1;
        }
        // Else If it is a lower-case alphabet, then convert it to upper case
        else if (x >= 97 && x <= 122) {
                return 2;
        }
        // Else If symbol is a digit, then discard it
        else if (x >= 48 && x <= 57) {
                return 3;
        }
        // Else If symbol is a punctuator, then discard it
        else if ((x >= 0 && x <= 47) || (x >= 58 && x <= 64) || (x >= 91 && x <= 96) || (x >= 123 && x <= 125)) {
                return 4;
        }
        // Else if symbol is a white-space character, then insert space
        else if (x == 32) {
                return 5;
        } else
                printf("Unrecognised symbol!");

}

void Insert(char x) {
        struct Node * new_node =
                (struct Node * ) malloc(sizeof(struct Node));
        if (isAlpha(x) == 1 || isAlpha(x) == 5) {
                new_node -> info = x;
                new_node -> next = NULL;
        } else if (isAlpha(x) == 2) {
                char temp;
                temp = toupper(x);
                new_node -> info = temp;
                new_node -> next = NULL;
        } else if (isAlpha == 3) {
                printf("'%c' is a digit, is discarded as well.\n\n", x);
        } else if (isAlpha(x) == 4) {
                printf("'%c' is a punctuator hence is discarded!!\n\n", x);
        }
        if (front == NULL && rear == NULL) {
                front = rear = new_node;
                return;
        }
        rear -> next = new_node;
        rear = new_node;
}

void Remove() {

        struct Node * new_node = front;

        if (front == NULL) {
                printf("Queue is Empty\n");
                return;
        }
        if (front == rear) {
                front = rear = NULL;
        } else {
                front = front -> next;
        }
        printf("%c is removed\n\n", new_node -> info);
        free(new_node);

        return;
}

void Print() {
        struct Node * some_node;

        while (some_node != NULL) {
                printf("%c ", some_node -> info);
                some_node = some_node -> next;
        }
        printf(" -> x \n\n");
        return;
}

int main() {

        Insert('d');
        Print();
        Insert(']');
        Insert('e');
        Print();
        Remove();
        return 0;
}
