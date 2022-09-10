#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void cPromedio(int *arr,int cant,float *prom);
void extern asmPromedio(int *arr,int cant,float *prom);
void llenarArreglo(int *arr,int cant);

int main(){
    int arr[10],N=10;
    float promC=0,promASM=0;
    double elapsed;
    struct timespec ti,tf;

    llenarArreglo(arr,N);

    clock_gettime(CLOCK_REALTIME,&ti);
    cPromedio(arr,N,&promC);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%f\n",promC);
    printf("El tiempo en nanosegundos que toma la función en C es: %lf\n",elapsed);

    clock_gettime(CLOCK_REALTIME,&ti);
    asmPromedio(arr,N,&promASM);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%f\n",promASM);
    printf("El tiempo en nanosegundos que toma la funcion en ASM es: %lf\n",elapsed);



}

void cPromedio(int *arr,int cant,float *prom){
    for(int i=0;i<cant;i++){
        prom[0]+=arr[i];
    }
    prom[0]=prom[0]/cant;
}

void llenarArreglo(int *arr,int cant){
    for(int i=0;i<cant;i++){
        arr[i]=rand()%101;
    }
}
