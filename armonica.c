#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void llenarArreglo(unsigned long *arr,int cant);
void imprimirArreglo(unsigned long *arr,int N);
double armonicaC(unsigned long *arr,int cant);
double extern asmArmonica(unsigned long *arr,int cant);
double speedUp(double ref,double cal);

int main(){
    unsigned long arr[16];
    int N=16;
    double medC=0,medASM=0;
    double elapsedC,elapsedA;
    struct timespec ti,tf;

    llenarArreglo(arr,N);

    imprimirArreglo(arr,N);
    
    clock_gettime(CLOCK_REALTIME,&ti);
    medC=armonicaC(arr,N);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedC=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%lf\n",medC);
    printf("El tiempo en nanosegundos que toma la función en C es: %lf\n",elapsedC);

    
    clock_gettime(CLOCK_REALTIME,&ti);
    medASM=asmArmonica(arr,N);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedA=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%lf\n",medASM);
    printf("El tiempo en nanosegundos que toma la funcion en ASM es: %lf\n",elapsedA);
    double spdup=speedUp(elapsedC,elapsedA);
    printf("El speed up es: %lf\n",spdup);
}

double armonicaC(unsigned long *arr,int cant){
    double media=0;
    for(int i=0;i<cant;i++){
        media+=1.0/arr[i];
    }
    return cant/media;
}

void llenarArreglo(unsigned long *arr,int cant){
    for(int i=0;i<cant;i++){
        arr[i]=random()%101;
    }
}

void imprimirArreglo(unsigned long *arr,int N){
    for(int i=0;i<N;i++){
        printf("%ld ",arr[i]);
    }
    printf("\n");
}

double speedUp(double ref,double cal){
    return ref/cal;
}
