// Arrays: Dynamic Allocation in the Heap

#include <stdio.h>

#include <stdlib.h>

int main() {

        char * list,
                value;
        int size,
        i;

        // Add size at the address of x
        printf("Enter size of array \n");
        scanf("%i", & size);

        // Allocate a chunk of memory in the heap
        list = (char * ) malloc(size * sizeof(char));

        /* Add value at the address of value...leave space before %c because conversion specifier won't automatically skip any leading whitespace
         */
        for (i = 0; i < size; i++) {
                printf("Enter Value \n");
                scanf(" %c", & value);
                list[i] = value;
        }

        // print list
        printf("\n list:\n");
        for (i = 0; i < size; i++) {
                printf("%i -> %c\n", i, list[i]);
        }

        // Time passed and I want a bigger container

        char * temp;
        int s;

        printf("\n\nEnter new size for the new array\n");
        scanf("%i", & s);

        temp = realloc(temp, s * sizeof(char));
        printf("New Memory reallocated");
        //enter code here

        return 0;
}
