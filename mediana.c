#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float cMediana(float *arr,int cant);
float extern asmMediana(int cant,float *arr);
void llenarArreglo(float *arr,int cant);
void imprimirArreglo(float *arr,int N);
void ordenarArreglo(float *arr,int N);
double speedUp(double ref,double cal);

int main(){
    float arr[16];
    int N=16;
    float medC=0,medASM=0;
    double elapsedC,elapsedA;
    struct timespec ti,tf;

    llenarArreglo(arr,N);

    ordenarArreglo(arr,N);

    imprimirArreglo(arr,N);
    
    clock_gettime(CLOCK_REALTIME,&ti);
    medC=cMediana(arr,N);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedC=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%f\n",medC);
    printf("El tiempo en nanosegundos que toma la función en C es: %lf\n",elapsedC);

    
    clock_gettime(CLOCK_REALTIME,&ti);
    medASM=asmMediana(N,arr);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedA=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%f\n",medASM);
    printf("El tiempo en nanosegundos que toma la funcion en ASM es: %lf\n",elapsedA);
    double spdup=speedUp(elapsedC,elapsedA);
    printf("El speed up es: %lf\n",spdup);
}

float cMediana(float *arr,int cant){
    if(cant%2==0){
        return (arr[(cant/2)-1]+arr[cant/2])/2;
    }else{
        return arr[cant/2];
    }
}

void llenarArreglo(float *arr,int cant){
    for(int i=0;i<cant;i++){
        arr[i]=rand()%101;
    }
}

void imprimirArreglo(float *arr,int N){
    for(int i=0;i<N;i++){
        printf("%f ",arr[i]);
    }
    printf("\n");
}

void ordenarArreglo(float *arr,int N){
    float aux;
    for(int i=0;i<N-1;i++)
        for(int j=i;j<N;j++)
            if(arr[i]>arr[j]){
                aux=arr[i];
                arr[i]=arr[j];
                arr[j]=aux;
            }
}

double speedUp(double ref,double cal){
    return ref/cal;
}
