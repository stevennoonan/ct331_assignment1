#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");
  printf("The size of an int is %d \n", sizeof(int));
  printf("The size of an int pointer is %d \n", sizeof(int*));
  printf("The size of a long is %d \n", sizeof(long));
  printf("The size of a double pointer is %d \n", sizeof(double*));
  printf("The size of a pointer to a char pointer is %d", sizeof(char**));
  return 0;
}
