/*-----------------------------
Author:  Hilario Nengare Jr.
Lab Work :   No. 8
Recursive Functions in Data Str
-----------------------------*/

 
#include <stdio.h>
 
 

// Summation of the integers 1, 2, 3, …, n
int sum_of_int(int n) {
        int temp;
        if (n == 1) {
                return (1);
        } else {
                temp = n + sum_of_int(n - 1);
        }
        return (temp);
}

// Factorial function
unsigned int factorial_of(unsigned int n) {
        //  Base case
        if (n == 0)
                return 1;
        else
                // multiply number (n) by its depletion by 1 such that (n-1) becomes the new parameter for next recursion
                return n * factorial_of(n - 1);
}

// Fibonacci numbers
unsigned int fibonacci_of(unsigned int n) {
        //  Default the seed values 0 and 1
        if (n < 2)
                return n;
        else
                // According to slide 9: Fib(n) = Fib(n-2) + Fib(n-1) if n >= 2
                return (fibonacci_of(n - 2) + fibonacci_of(n - 1));
}

// Power of n raised by m
unsigned int power(unsigned int n, unsigned int m) {
        //  Base case
        if (m == 0)
                return 1;
        else
                // tail recursive
                return n * power(n, m - 1);
}

// Summation of the elements of an array of integers
int sum_arr(int a[0], unsigned int length) {
        if (length == 0)
                return 0;
        else
                return (sum_arr(a, length - 1) + a[length - 1]);
}

// The minimum element of an array of integers
int min_value(int a[], int n) {
        int min;

        if (n == 1)
                return a[0];

        else {
                min = min_value(a, n - 1);
                if (min < a[n - 1])
                        return min;
                else
                        return a[n - 1];
        }
  }

 int main() {
        // Driver program
        int ar[] = {
                1,
                2,
                3,
                5,
                6,
                7,
                8,
                9,
                1
        };
        printf("Sum of Int\t->\t%i\n", sum_of_int(1));
        printf("Factorial\t->\t%i\n", factorial_of(4));
        printf("Fibonacci\t->\t%i\n", fibonacci_of(7));
        printf("Power\t\t->\t%i\n", power(2, 2));
        printf("Sum of Elements\t->\t%i\n", sum_arr(ar, 9));
        printf("Minimum Value\t->\t%i\n", min_value(ar, 9));
        return 0;

}
