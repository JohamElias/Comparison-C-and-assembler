#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void asmFloatNormTwo(float *v1, int N, float *n2);
void cFloatNormTwo(float *v1, int N, float *n2);

int main() {

	float *v1, n2C, n2Asm;
	int N = 1024;

	v1 = malloc(N * sizeof(float));

	int i = 0;

	for(i = 0; i < N; i++){
		v1[i] = (float)i;
	}

	cFloatNormTwo(v1, N, &n2C);
	
	asmFloatNormTwo(v1, N, &n2Asm);

	printf("%f\n%f\n",n2C,n2Asm);

	return 0;
};

void cFloatNormTwo(float *v1, int N, float *n2) {
	int i = 0;
	float sum = 0;
	for(i = 0; i < N; i++) {
		sum += v1[i] * v1[i];
	}
	n2[0] = sqrtf(sum);
}