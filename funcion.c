#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern void asmFuncion(float i2, float i3, int n,float *y);
void cFuncion(float i2, float i3, int n,float *y);
double calcRelErr(float ref,float cal);

int main() {
	srandom(time(NULL));
	float cy,asmy, i2=0.5, i3=3.75;
	int n = 1000;

	struct timespec ti,tf;
	double elapsed;

	clock_gettime(CLOCK_REALTIME,&ti);
	cFuncion(i2,i3,n,&cy);
	clock_gettime(CLOCK_REALTIME,&tf);
	elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("el tiempo en nanosegundos que toma la función en C es %lf\n", elapsed);

	clock_gettime(CLOCK_REALTIME,&ti);
	asmFuncion(i2,i3,n,&asmy);
	clock_gettime(CLOCK_REALTIME,&tf);
	elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
	printf("El tiempo en nanosegundos que toma la función en ASM es %lf\n",elapsed);

	printf("%f\n%f\n",cy,asmy);

	double relerr=calcRelErr(cy,asmy);
	printf("El error relativo es: %f\n",relerr);

	return 0;
};

double calcRelErr(float ref,float cal){
	return fabsf(ref-cal)/fabsf(ref);
}

void cFuncion(float i2, float i3, int n,float *y){
	y[0]=n*n+i2*n-i3;
}