#include <stdio.h>
#include <stdlib.h>

int size, g = 0, *v1, *v2, sum;
volatile int ready = 0, finish = 0;

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
		
		fscanf(f1, " %d", &size);
		fscanf(f2, " %d", &size);

		v1 = (int *) malloc(size * sizeof(int));
		v2 = (int *) malloc(size * sizeof(int));

		for(i = 0; i < size; i++) {
			fscanf(f1, " %d", &v1[i]);
			fscanf(f2, " %d", &v2[i]);
		}

		fclose(f1);
		fclose(f2);

		ready = 1;
	}
	*lock = 0;

	while(!ready);

	for(i = proc; i < size; i += 8) {
		r = v1[i] * v2[i];
		while(*lock);
		*lock = 1;
		sum += r;
		if (i + 8 >= size )
 			finish++;
		*lock = 0;
	}

	while(finish < 8);
	
	if (proc == 0) {
		printf("Resultado: %d\n", sum);
		free(v1);
		free(v2);
	}

	exit(0); // To avoid cross-compiler exit routine
	return 0; // Never executed, just for compatibility
}

