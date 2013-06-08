#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int g = 0, v1[SIZE], v2[SIZE], sum;
volatile int ready = 0, finish = 0;;

int main(int argc, char *argv[]) {

	FILE * f1, * f2;
	int i, proc, r, inicio, fim;
	volatile int * lock;

	lock = 6 * 1024 * 1024;

	while(*lock);
	*lock = 1;
	proc = g++;
	*lock = 0;

	while(*lock);
	*lock = 1;
	if (proc == 0) {
		f1 = fopen("/home/ec2007/ra073203/home-ext/mc723/p3/arp/sw/reducer/v1", "r");
		f2 = fopen("/home/ec2007/ra073203/home-ext/mc723/p3/arp/sw/reducer/v2", "r");

		for(i = 0; i < SIZE; i++) {
			fscanf(f1, " %d", &v1[i]);
			fscanf(f2, " %d", &v2[i]);
		}

		fclose(f1);
		fclose(f2);

		ready = 1;
	}
	*lock = 0;

	while(!ready);

	inicio = proc * (SIZE / 8);
	fim = (proc + 1) * (SIZE / 8);
	for(i = inicio; i < fim; i++) {
		r = v1[i] * v2[i];
		while(*lock);
		*lock = 1;
		sum += r;
		if (i == fim - 1)
			finish++;
		*lock = 0;
	}	

	while(finish < 8);
	
	if (proc == 0)
		printf("Resultado: %d\n", sum);

	exit(0); // To avoid cross-compiler exit routine
	return 0; // Never executed, just for compatibility
}

