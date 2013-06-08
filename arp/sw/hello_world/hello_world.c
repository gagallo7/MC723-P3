#include <stdio.h>

int main(int argc, char *argv[]){
  int i;
  volatile int * lock;
  //for(i=0;i<10;i++)
    //printf("Hi from processor MIPS!\n");

  lock = 6 * 1024 * 1024;
  printf("LOCK -->%d\n", *lock);
  while(*lock);
  *lock = 1;
  printf("Peguei o lock\n");
  *lock = 0;

  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

