/*
 * Program  : Searching an element in the array
 */

#include<stdio.h>

#define size 5

int main() {
        int arr[size] = {
                34,
                2,
                23,
                100,
                60
        };
        int key, i, flag = 0;

        printf("Enter element to search\n");
        scanf("%d", & key);

        /*
         * iterate the array elements using loop
         * if any element matches the key, set flag as 1 and break the loop
         * flag = 1 indicates that the key present in the array
         * if execution comes out of loop and the flag remains 0, print search not found
         */

        for (i = 0; i < size; i++) {
                if (arr[i] == key) {
                        flag = 1;
                        break;
                }
        }

        if (flag == 1)
                printf("Search Found\n");
        else
                printf("Search Not Found\n");

        return 0;
}
