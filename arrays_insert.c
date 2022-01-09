/*
 * Program  : ARRAYS
 * Language : C
 * Note: Are arrays mutable in C? From Google,
 
Arrays in C are not a special data type per se - they are just memory buffers - so the contents are indeed mutable.
However, C arrays are fixed in size, and cannot be extended or shortened. 
To achieve extensible arrays, you need to use dynamic allocation with malloc and free.
 */

#include<stdio.h>

#define size 5

int main() {
        int arr[size] = {
                1,
                20,
                5,
                78,
                30
        };
        int element, pos, i;

        printf("Enter position \n");
        scanf("%d", & pos);
        printf("Enter element \n");
        scanf("%d", & element);

        if (pos < size && pos >= 0) {
                //shift all the elements from the last index to pos by 1 position to right
                for (i = size; i > pos; i--) {
                        // printf("%d\n",i); to track the branching
                        arr[i] = arr[i - 1];
                }

                //insert element at the given position
                arr[pos] = element;

                /*
                 * print the new array
                 * the new array size will be size+1(actual size+new element)
                 * so, use i <= size in for loop
                 */
                for (i = 0; i <= size; i++)
                        printf("%d ", arr[i]);
        } else
                printf("Invalid Position\n");

        return 0;
}
