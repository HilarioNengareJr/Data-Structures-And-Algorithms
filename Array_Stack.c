  /*
   * Program :Stack data structure using array
   * Language : C
   */

  #include<stdio.h>

  #define size 5

  int arr[size];
  int top = -1; //-1 indicates empty stack

  int isStackFull() {
          if (top == size - 1)
                  return 1;
          return 0;
  }

  void push(int val) {
          //check if the stack is full
          if (isStackFull())
                  printf("Unable to push %d as the Stack Is Full\n", val);
          else {
                  //increment top by 1 
                  ++top;
                  //push the element into stack 
                  arr[top] = val;
          }

  }

  int isStackEmpty() {
          if (top == -1)
                  return 1;
          return 0;
  }

  void pop() {
          //check if the stack is empty
          if (isStackEmpty())
                  printf("Stack Is Empty\n");
          else {
                  //print the popped element
                  printf("Popped element = %d\n", arr[top]);
                  //decrement top by 1
                  top--;
          }

  }

  int main() {
          push(10);
          push(13);
          push(5);
          push(26);
          push(100);
          push(78); //we can't push 78 as the stack is full
          pop(); //100
          pop(); //26
          pop(); //5
          pop(); //13
          pop(); //10
          pop(); //unable to pop as the stack is empty
          return 0;
  }
