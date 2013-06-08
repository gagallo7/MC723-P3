#include <stdio.h>

int main(int argc, char *argv[]){
  int i, *lock;
  for(i=0;i<10;i++)
    printf("Hi from processor MIPS!\n");

  lock = 6 * 1024 * 1024;

  printf("[LOCKER] Antes: %d\n", *lock);
  *lock = 1;
  printf("[LOCKER] Depois: %d\n", *lock);


  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

