./*
Author Name: Dadayakkara Dewege Poorna
*/

#include <stdio.h>
#include <stdlib.h>

int* allocate(int n) {
  // allocate memory block to store n integers
  int* address = (int*) calloc(n, sizeof(int));

  // check if memory allocation was successful
  if (address == NULL) {
    printf("Failed to allocate memory.\n");
    exit(1);
  }

  return address;
}

void set(int *b, int index, int number) {
  // check if index is within bounds
  if (index < 0 || index >= sizeof(b)) {
    printf("Invalid index.\n");
    return;
  }

  b[index] = number;
}

int get(int *b, int index) {
  // check if index is within bounds
  if (index < 0 || index >= sizeof(b)) {
    printf("Invalid index.\n");
    return -1;
  }

  return b[index];
}

int main(void) {
  printf("Memory Management System\n");
  printf("Hi,welcome.Lets see our Menu:\n");
  int* blockAddress = NULL;
  int size = 0;

  while(1) {

    printf(" Enter 1 to allocate\n Enter 2 to set\n Enter 3 to get\n Enter 4 to quit: \n");
    int input;
    scanf("%d",&input);

    if (input == 1) {
      // allocate memory block
      printf("Enter size: ");
      scanf("%d", &size);

      if (blockAddress != NULL) {
        free(blockAddress);
      }

      blockAddress = allocate(size);
      printf("Memory allocated successfully.\n");

    } else if (input == 2) {
      // set value at specified index
      if (blockAddress == NULL) {
        printf("No memory allocated yet.\n");
        continue;
      }

      int index, value;
      printf("Enter index: ");
      scanf("%d", &index);

      if (index < 0 || index >= size) {
        printf("Invalid index.The index you entered has not lied between size and 0\n");
        continue;
      }

      printf("Enter value: ");
      scanf("%d", &value);

      set(blockAddress, index, value);
      printf("Value set successfully.\n");

    } else if (input == 3) {
      // get value at specified index
      if (blockAddress == NULL) {
        printf("No memory allocated yet.\n");
        continue;
      }

      int index;
      printf("Enter index: ");
      scanf("%d", &index);

      if (index < 0 || index >= size) {
        printf("Invalid index.The index you entered,has not assigned to any value previously\n");
        continue;
      }

      printf("Value at index %d is %d\n", index, get(blockAddress, index));

    } else if (input == 4) {
      // free memory and exit program
      free(blockAddress);
      printf("Memory freed successfully.\n");
      break;

    } else {
      printf("Invalid input. Please enter again.\n");
    }
  }

  return 0;
}


